/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  IntCtrl.c
 *  Module:  	  IntCtrl
 *  Description:  Source file for NVIC Module's driver
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Philo emad
 *	Date:		  21/09/2022
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "IntCtrl.h"
#include "Mcu_Hw.h"
#include "Macros.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/*******************************************************************************
* Service Name: IntCrtl_Init
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: void
* Description: 
*******************************************************************************/
void IntCrtl_Init(void)
{
	
	int ex = 0;
	IntCtrl_PriorityLevel priority;
		IntCtrl_ConfigType *ConfigPtr = &IntCtrl_Config;
	
    SCB_APINT = 0x05FA0000;	
	for (ex = 0; ex < PROCESSOR_EXCEPTIONS_NUM; ex++)
	{
		if (ConfigPtr->exceptions[ex].mode == EXC_DISABLED)
		{
			switch (ConfigPtr->exceptions[ex].exceptionId)
			{
				case RESET:
				case NMI:
				case HARD_FAULT:
					continue;
					break;
				case MEMORY_MANAGE_FAULT:
					SCB_SYSHNDCTRL.MEM = 0;
					break;
				case BUS_FAULT:
					SCB_SYSPRI1.BUS = priority;
					SCB_SYSHNDCTRL.BUS = 1;
					break;
				case USAGE_FAULT:
					SCB_SYSPRI1.USAGE = priority;
					SCB_SYSHNDCTRL.USAGE = 1;
					break;
				case SVCALL:
					SCB_SYSPRI2.SVC = priority;
					break;
				case DEBUG_MONITOR:
					SCB_SYSPRI3.DEBUG = priority;
					break;
				case PENDSV:
					SCB_SYSPRI3.PENDSV = priority;
					break;
				case SYSTICK:
					SCB_SYSPRI3.TICK = priority;
					SYSTICK_STCTRL.INTEN = 1;
					break;
			}
		}
		else if (ConfigPtr->exceptions[ex].mode == EXC_ENABLED)
		{
			priority = ConfigPtr->exceptions[ex].priority;
		
			switch (ConfigPtr->exceptions[ex].exceptionId)
			{
				case RESET:
				case NMI:
				case HARD_FAULT:
					continue;
					break;
				case MEMORY_MANAGE_FAULT:
					SCB_SYSPRI1.MEM = priority;
					SCB_SYSHNDCTRL.MEM = 1;
					break;
				case BUS_FAULT:
					SCB_SYSHNDCTRL.BUS = 0;
					break;
				case USAGE_FAULT:
					SCB_SYSHNDCTRL.USAGE = 0;
					break;
				case SVCALL:
					continue;
					break;
				case DEBUG_MONITOR:
					continue;
					break;
				case PENDSV:
					continue;
					break;
				case SYSTICK:
					SYSTICK_STCTRL.INTEN = 0;
					break;
			}
		}
	}
	
	uint8 irq = 0;
	uint8 irq_id = 0;
	for (irq = 0; irq < MICROCONTROLLER_INTERRUPTS_NUM; irq++)
	{
		irq_id = ConfigPtr->interrupts[irq].interruptIdentifier;
		
		if (ConfigPtr->interrupts[irq].mode == INT_DISABLED)
		{
			if ((irq_id >= 0) && (irq_id > 32))
				SET_BIT(NVIC_DIS0, irq_id);
			else if ((irq_id > 31) && (irq_id < 64))
				SET_BIT(NVIC_DIS1, irq_id);
			else if ((irq_id > 63) && (irq_id < 96))
				SET_BIT(NVIC_DIS2, irq_id);
			else if ((irq_id > 95) && (irq_id < 128))
				SET_BIT(NVIC_DIS3, irq_id);
			else if ((irq_id > 127) && (irq_id < 139))
				SET_BIT(NVIC_DIS4, irq_id);
			else
				return;
		}
		else if (ConfigPtr->interrupts[irq].mode == INT_ENABLED)
		{
			irq_id = ConfigPtr->interrupts[irq].interruptIdentifier;
			uint8 PrixOffset = irq_id / 4;	
			uint8 Intx = irq_id % 4;	
			volatile NVIC_PRIn_BF* PRIx = (volatile NVIC_PRIn_BF*)((volatile uint8*)NVIC_PRIx_BASE + (PrixOffset*4));
			
			priority = ConfigPtr->interrupts[irq].priority;
			
			switch (Intx)
			{
				case 0:
					(*PRIx).INTA = priority;
					break;
				case 1:
					(*PRIx).INTB = priority;
					break;
				case 2:
					(*PRIx).INTC = priority;
					break;
				case 3:
					(*PRIx).INTD = priority;
					break;
			}
			
			if ((irq_id >= 0) && (irq_id > 32))
				SET_BIT(NVIC_EN0, irq_id);
			else if ((irq_id > 31) && (irq_id < 64))
				SET_BIT(NVIC_EN1, irq_id);
			else if ((irq_id > 63) && (irq_id < 96))
				SET_BIT(NVIC_EN2, irq_id);
			else if ((irq_id > 95) && (irq_id < 128))
				SET_BIT(NVIC_EN3, irq_id);
			else if ((irq_id > 127) && (irq_id < 139))
				SET_BIT(NVIC_EN4, irq_id);
			else
				return;
		}
	}
}

/*******************************************************************************
* Service Name: IntCtrl_EnableInterrupt
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): 
* Parameters (inout): None
* Parameters (out): None
* Return value: void
* Description: 
*******************************************************************************/
void IntCtrl_EnableInterrupt(IntCtrl_InterruptType interruptIdentifier, IntCtrl_PriorityLevel Priority)
{
	uint8 irq_id = interruptIdentifier;
	uint8 PrixOffset = irq_id / 4;		
	uint8 Intx = irq_id % 4;	
	volatile NVIC_PRIn_BF* PRIx = (volatile NVIC_PRIn_BF*)(CORTEXM4_PERI_BASE_ADDRESS + (uint8*)NVIC_PRIx_BASE + (PrixOffset*4));
	
	
	switch (Intx)
	{
		case 0:
			(*PRIx).INTA = Priority;
			break;
		case 1:
			(*PRIx).INTB = Priority;
			break;
		case 2:
			(*PRIx).INTC = Priority;
			break;
		case 3:
			(*PRIx).INTD = Priority;
			break;
	}
	
	if ((irq_id >= 0) && (irq_id < 32))
		SET_BIT(NVIC_EN0, irq_id);
	else if ((irq_id > 31) && (irq_id < 64))
		SET_BIT(NVIC_EN1, irq_id);
	else if ((irq_id > 63) && (irq_id < 96))
		SET_BIT(NVIC_EN2, irq_id);
	else if ((irq_id > 95) && (irq_id < 128))
		SET_BIT(NVIC_EN3, irq_id);
	else if ((irq_id > 127) && (irq_id < 139))
		SET_BIT(NVIC_EN4, irq_id);
	else
		return;
		
	uint8 irq = 0;
	for (irq = 0; irq < MICROCONTROLLER_INTERRUPTS_NUM; irq++)
	{
		if(IntCtrl_Config.interrupts[irq].interruptIdentifier == interruptIdentifier)
		{
			IntCtrl_Config.interrupts[irq].mode = INT_ENABLED;
			IntCtrl_Config.interrupts[irq].priority = Priority;
			break;
		}
	}
}

/*******************************************************************************
* Service Name: IntCtrl_DisableInterrupt
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): 
* Parameters (inout): None
* Parameters (out): None
* Return value: void
* Description: 
*******************************************************************************/
void IntCtrl_DisableInterrupt(IntCtrl_InterruptType interruptIdentifier)
{
	if ((interruptIdentifier >= 0) && (interruptIdentifier > 32))
		SET_BIT(NVIC_DIS0, interruptIdentifier);
	else if ((interruptIdentifier > 31) && (interruptIdentifier < 64))
		SET_BIT(NVIC_DIS1, interruptIdentifier);
	else if ((interruptIdentifier > 63) && (interruptIdentifier < 96))
		SET_BIT(NVIC_DIS2, interruptIdentifier);
	else if ((interruptIdentifier > 95) && (interruptIdentifier < 128))
		SET_BIT(NVIC_DIS3, interruptIdentifier);
	else if ((interruptIdentifier > 127) && (interruptIdentifier < 139))
		SET_BIT(NVIC_DIS4, interruptIdentifier);
	else
		return;
		
	uint8 irq = 0;
	for (irq = 0; irq < MICROCONTROLLER_INTERRUPTS_NUM; irq++)
	{
		if(IntCtrl_Config.interrupts[irq].interruptIdentifier == interruptIdentifier)
			IntCtrl_Config.interrupts[irq].mode = INT_DISABLED;
	}
}


