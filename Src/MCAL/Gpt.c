/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Gpt.c
 *  Module:  	  General Purpose Timer
 *  Description:  Source file for TM4C123GH6PM MCU - General Purpose Timer Module's driver
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
#include "Gpt.h"
#include "Gpt_regs.h"
#include "Macros.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/*******************************************************************************
* Service Name: Gpt_Init
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): 
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: 
*******************************************************************************/
void Gpt_Init(const Gpt_ChannelConfigType* ConfigPtr)
{
	
	INTERRUPTS_DISABLE
	volatile uint8* channelPtr = ((void *)0);
	volatile Gpt_TimerInterruptType interruptIdentifier = 0;

	switch (ConfigPtr->channelId)
	{
		case TIMER0_16BIT:
			channelPtr = (volatile uint8*)GPT_16BIT_TIMER0_BASE_ADDRESS;
			interruptIdentifier = TIMER_16_32_BIT_0A;
			SYSCTL_RCGCTIMER.R0 = 1;
			break;
		case TIMER1_16BIT:
			channelPtr = (volatile uint8*)GPT_16BIT_TIMER1_BASE_ADDRESS;
			interruptIdentifier = TIMER_16_32_BIT_1A;
			SYSCTL_RCGCTIMER.R1 = 1;
			break;
		case TIMER2_16BIT:
			channelPtr = (volatile uint8*)GPT_16BIT_TIMER2_BASE_ADDRESS;
			interruptIdentifier = TIMER_16_32_BIT_2A;
			SYSCTL_RCGCTIMER.R2 = 1;
			break;
		case TIMER3_16BIT:
			channelPtr = (volatile uint8*)GPT_16BIT_TIMER3_BASE_ADDRESS;
			interruptIdentifier = TIMER_16_32_BIT_3A;
			SYSCTL_RCGCTIMER.R3 = 1;
			break;
		case TIMER4_16BIT:
			channelPtr = (volatile uint8*)GPT_16BIT_TIMER4_BASE_ADDRESS;
			interruptIdentifier = TIMER_16_32_BIT_4A;
			SYSCTL_RCGCTIMER.R4 = 1;
			break;
		case TIMER5_16BIT:
			channelPtr = (volatile uint8*)GPT_16BIT_TIMER5_BASE_ADDRESS;
			interruptIdentifier = TIMER_16_32_BIT_5A;
			SYSCTL_RCGCTIMER.R5 = 1;
			break;
		case TIMER0_32BIT:
			channelPtr = (volatile uint8*)GPT_32BIT_WIDE_TIMER0_BASE_ADDRESS;
			interruptIdentifier = TIMER_32_64_BIT_0A;
			SYSCTL_RCGCWTIMER.R0 = 1;
			break;
		case TIMER1_32BIT:
			channelPtr = (volatile uint8*)GPT_32BIT_WIDE_TIMER1_BASE_ADDRESS;
			interruptIdentifier = TIMER_32_64_BIT_1A;
			SYSCTL_RCGCWTIMER.R1 = 1;
			break;
		case TIMER2_32BIT:
			channelPtr = (volatile uint8*)GPT_32BIT_WIDE_TIMER2_BASE_ADDRESS;
			interruptIdentifier = TIMER_32_64_BIT_2A;
			SYSCTL_RCGCWTIMER.R2 = 1;
			break;
		case TIMER3_32BIT:
			channelPtr = (volatile uint8*)GPT_32BIT_WIDE_TIMER3_BASE_ADDRESS;
			interruptIdentifier = TIMER_32_64_BIT_3A;
			SYSCTL_RCGCWTIMER.R3 = 1;
			break;
		case TIMER4_32BIT:
			channelPtr = (volatile uint8*)GPT_32BIT_WIDE_TIMER4_BASE_ADDRESS;
			interruptIdentifier = TIMER_32_64_BIT_4A;
			SYSCTL_RCGCWTIMER.R4 = 1;
			break;
		case TIMER5_32BIT:
			channelPtr = (volatile uint8*)GPT_32BIT_WIDE_TIMER5_BASE_ADDRESS;
			interruptIdentifier = TIMER_32_64_BIT_5A;
			SYSCTL_RCGCWTIMER.R5 = 1;
			break;
		default:
			return;
	}
	
	IntCtrl_EnableInterrupt(interruptIdentifier, ConfigPtr->priority);
	
	GPT_GPTMCTL(channelPtr).TAEN = 0;


	GPT_GPTMCFG(channelPtr) = 0x00000000;
	
	GPT_GPTMTAMR(channelPtr).TAMIE = 1;
	
	GPT_GPTMTAMR(channelPtr).TAMIE = 1;
	

	GPT_GPTMTAMR(channelPtr).TAMR = ConfigPtr->mode;
	
	GPT_GPTMTAMR(channelPtr).TACDIR = ConfigPtr->direction;
	
	GPT_GPTMTAMR(channelPtr).TAILD = 1;
	
	GPT_GPTMTAMR(channelPtr).TAMRSU = 1;
	
	GPT_GPTMIMR(channelPtr).TATOIM = 1;
	
	INTERRUPTS_ENABLE
}

/*******************************************************************************
* Service Name: Gpt_DisableCallback
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): 
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: 
*******************************************************************************/
void Gpt_DisableCallback(Gpt_ChannelType ChannelId)
{
	const Gpt_ChannelConfigType* ConfigPtr = &(Gpt_Config.channels[ChannelId]);
	
	volatile uint8* channelPtr = ((void *)0);
	volatile Gpt_TimerInterruptType interruptIdentifier = 0;
	
 	switch (ConfigPtr->channelId)
	{
		case TIMER0_16BIT:
			channelPtr = (volatile uint8*)GPT_16BIT_TIMER0_BASE_ADDRESS;
			interruptIdentifier = TIMER_16_32_BIT_0A;
			break;
		case TIMER1_16BIT:
			channelPtr = (volatile uint8*)GPT_16BIT_TIMER1_BASE_ADDRESS;
			interruptIdentifier = TIMER_16_32_BIT_1A;
			break;
		case TIMER2_16BIT:
			channelPtr = (volatile uint8*)GPT_16BIT_TIMER2_BASE_ADDRESS;
			interruptIdentifier = TIMER_16_32_BIT_2A;
			break;
		case TIMER3_16BIT:
			channelPtr = (volatile uint8*)GPT_16BIT_TIMER3_BASE_ADDRESS;
			interruptIdentifier = TIMER_16_32_BIT_3A;
			break;
		case TIMER4_16BIT:
			channelPtr = (volatile uint8*)GPT_16BIT_TIMER4_BASE_ADDRESS;
			interruptIdentifier = TIMER_16_32_BIT_4A;
			break;
		case TIMER5_16BIT:
			channelPtr = (volatile uint8*)GPT_16BIT_TIMER5_BASE_ADDRESS;
			interruptIdentifier = TIMER_16_32_BIT_5A;
			break;
		case TIMER0_32BIT:
			channelPtr = (volatile uint8*)GPT_32BIT_WIDE_TIMER0_BASE_ADDRESS;
			interruptIdentifier = TIMER_32_64_BIT_0A;
			break;
		case TIMER1_32BIT:
			channelPtr = (volatile uint8*)GPT_32BIT_WIDE_TIMER1_BASE_ADDRESS;
			interruptIdentifier = TIMER_32_64_BIT_1A;
			break;
		case TIMER2_32BIT:
			channelPtr = (volatile uint8*)GPT_32BIT_WIDE_TIMER2_BASE_ADDRESS;
			interruptIdentifier = TIMER_32_64_BIT_2A;
			break;
		case TIMER3_32BIT:
			channelPtr = (volatile uint8*)GPT_32BIT_WIDE_TIMER3_BASE_ADDRESS;
			interruptIdentifier = TIMER_32_64_BIT_3A;
			break;
		case TIMER4_32BIT:
			channelPtr = (volatile uint8*)GPT_32BIT_WIDE_TIMER4_BASE_ADDRESS;
			interruptIdentifier = TIMER_32_64_BIT_4A;
			break;
		case TIMER5_32BIT:
			channelPtr = (volatile uint8*)GPT_32BIT_WIDE_TIMER5_BASE_ADDRESS;
			interruptIdentifier = TIMER_32_64_BIT_5A;
			break;
		default:
 			return;
	}
	
	GPT_GPTMIMR(channelPtr).TATOIM = 0;
	
 	IntCtrl_DisableInterrupt(interruptIdentifier);
}

/*******************************************************************************
* Service Name: Gpt_EnableCallback
* Service ID[hex]: 0x02
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): 
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: 
*******************************************************************************/
void Gpt_EnableCallback(Gpt_ChannelType ChannelId)
{
	const Gpt_ChannelConfigType* ConfigPtr = &(Gpt_Config.channels[ChannelId]);
	
	volatile uint8* channelPtr = ((void *)0);
	volatile Gpt_TimerInterruptType interruptIdentifier = 0;
	
 	switch (ConfigPtr->channelId)
	{
		case TIMER0_16BIT:
			channelPtr = (volatile uint8*)GPT_16BIT_TIMER0_BASE_ADDRESS;
			interruptIdentifier = TIMER_16_32_BIT_0A;
			break;
		case TIMER1_16BIT:
			channelPtr = (volatile uint8*)GPT_16BIT_TIMER1_BASE_ADDRESS;
			interruptIdentifier = TIMER_16_32_BIT_1A;
			break;
		case TIMER2_16BIT:
			channelPtr = (volatile uint8*)GPT_16BIT_TIMER2_BASE_ADDRESS;
			interruptIdentifier = TIMER_16_32_BIT_2A;
			break;
		case TIMER3_16BIT:
			channelPtr = (volatile uint8*)GPT_16BIT_TIMER3_BASE_ADDRESS;
			interruptIdentifier = TIMER_16_32_BIT_3A;
			break;
		case TIMER4_16BIT:
			channelPtr = (volatile uint8*)GPT_16BIT_TIMER4_BASE_ADDRESS;
			interruptIdentifier = TIMER_16_32_BIT_4A;
			break;
		case TIMER5_16BIT:
			channelPtr = (volatile uint8*)GPT_16BIT_TIMER5_BASE_ADDRESS;
			interruptIdentifier = TIMER_16_32_BIT_5A;
			break;
		case TIMER0_32BIT:
			channelPtr = (volatile uint8*)GPT_32BIT_WIDE_TIMER0_BASE_ADDRESS;
			interruptIdentifier = TIMER_32_64_BIT_0A;
			break;
		case TIMER1_32BIT:
			channelPtr = (volatile uint8*)GPT_32BIT_WIDE_TIMER1_BASE_ADDRESS;
			interruptIdentifier = TIMER_32_64_BIT_1A;
			break;
		case TIMER2_32BIT:
			channelPtr = (volatile uint8*)GPT_32BIT_WIDE_TIMER2_BASE_ADDRESS;
			interruptIdentifier = TIMER_32_64_BIT_2A;
			break;
		case TIMER3_32BIT:
			channelPtr = (volatile uint8*)GPT_32BIT_WIDE_TIMER3_BASE_ADDRESS;
			interruptIdentifier = TIMER_32_64_BIT_3A;
			break;
		case TIMER4_32BIT:
			channelPtr = (volatile uint8*)GPT_32BIT_WIDE_TIMER4_BASE_ADDRESS;
			interruptIdentifier = TIMER_32_64_BIT_4A;
			break;
		case TIMER5_32BIT:
			channelPtr = (volatile uint8*)GPT_32BIT_WIDE_TIMER5_BASE_ADDRESS;
			interruptIdentifier = TIMER_32_64_BIT_5A;
			break;
		default:
			return;
	}
	
	GPT_GPTMIMR(channelPtr).TATOIM = 1;
	
 	IntCtrl_EnableInterrupt(interruptIdentifier, ConfigPtr->priority);
}

/*******************************************************************************
* Service Name: Gpt_StartTimer
* Service ID[hex]: 0x03
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): 
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: 
*******************************************************************************/
void Gpt_StartTimer(Gpt_ChannelType ChannelId, Gpt_ValueType Value)
{
	const Gpt_ChannelConfigType* ConfigPtr = &(Gpt_Config.channels[ChannelId]);
	
	volatile uint8* channelPtr = ((void *)0);
	volatile uint8 timerWidth = 0;
	
	switch (ConfigPtr->channelId)
	{
		case TIMER0_16BIT:
			channelPtr = (volatile uint8*)GPT_16BIT_TIMER0_BASE_ADDRESS;
			timerWidth = 32;
			break;
		case TIMER1_16BIT:
			channelPtr = (volatile uint8*)GPT_16BIT_TIMER1_BASE_ADDRESS;
			timerWidth = 32;
			break;
		case TIMER2_16BIT:
			channelPtr = (volatile uint8*)GPT_16BIT_TIMER2_BASE_ADDRESS;
			timerWidth = 32;
			break;
		case TIMER3_16BIT:
			channelPtr = (volatile uint8*)GPT_16BIT_TIMER3_BASE_ADDRESS;
			timerWidth = 32;
			break;
		case TIMER4_16BIT:
			channelPtr = (volatile uint8*)GPT_16BIT_TIMER4_BASE_ADDRESS;
			timerWidth = 32;
			break;
		case TIMER5_16BIT:
			channelPtr = (volatile uint8*)GPT_16BIT_TIMER5_BASE_ADDRESS;
			timerWidth = 32;
			break;
		case TIMER0_32BIT:
			channelPtr = (volatile uint8*)GPT_32BIT_WIDE_TIMER0_BASE_ADDRESS;
			timerWidth = 64;
			break;
		case TIMER1_32BIT:
			channelPtr = (volatile uint8*)GPT_32BIT_WIDE_TIMER1_BASE_ADDRESS;
			timerWidth = 64;
			break;
		case TIMER2_32BIT:
			channelPtr = (volatile uint8*)GPT_32BIT_WIDE_TIMER2_BASE_ADDRESS;
			timerWidth = 64;
			break;
		case TIMER3_32BIT:
			channelPtr = (volatile uint8*)GPT_32BIT_WIDE_TIMER3_BASE_ADDRESS;
			timerWidth = 64;
			break;
		case TIMER4_32BIT:
			channelPtr = (volatile uint8*)GPT_32BIT_WIDE_TIMER4_BASE_ADDRESS;
			timerWidth = 64;
			break;
		case TIMER5_32BIT:
			channelPtr = (volatile uint8*)GPT_32BIT_WIDE_TIMER5_BASE_ADDRESS;
			timerWidth = 64;
			break;
		default:
			return;
	}
	
	Value = Value * F_CPU;		
	
	switch (timerWidth)
	{
		case 32:
			GPT_GPTMTAILR(channelPtr) = Value & (0x00000000FFFFFFFF);

			break;
		case 64:
			
			GPT_GPTMTBILR(channelPtr) = ((Value) & (0xFFFFFFFF00000000))>>32;
			GPT_GPTMTAILR(channelPtr) = Value & (0x00000000FFFFFFFF);
			

			break;
	}
	
	GPT_GPTMCTL(channelPtr).TAEN = 1;
}

/*******************************************************************************
* Service Name: Gpt_StopTimer
* Service ID[hex]: 0x04
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): 
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: 
*******************************************************************************/
void Gpt_StopTimer(Gpt_ChannelType ChannelId)
{
	const Gpt_ChannelConfigType* ConfigPtr = &(Gpt_Config.channels[ChannelId]);
	
	volatile uint8* channelPtr = ((void *)0);
	volatile uint8 timerWidth = 0;
	
	switch (ConfigPtr->channelId)
	{
		case TIMER0_16BIT:
			channelPtr = (volatile uint8*)GPT_16BIT_TIMER0_BASE_ADDRESS;
			break;
		case TIMER1_16BIT:
			channelPtr = (volatile uint8*)GPT_16BIT_TIMER1_BASE_ADDRESS;
			break;
		case TIMER2_16BIT:
			channelPtr = (volatile uint8*)GPT_16BIT_TIMER2_BASE_ADDRESS;
			break;
		case TIMER3_16BIT:
			channelPtr = (volatile uint8*)GPT_16BIT_TIMER3_BASE_ADDRESS;
			break;
		case TIMER4_16BIT:
			channelPtr = (volatile uint8*)GPT_16BIT_TIMER4_BASE_ADDRESS;
			break;
		case TIMER5_16BIT:
			channelPtr = (volatile uint8*)GPT_16BIT_TIMER5_BASE_ADDRESS;
			break;
		case TIMER0_32BIT:
			channelPtr = (volatile uint8*)GPT_32BIT_WIDE_TIMER0_BASE_ADDRESS;
			break;
		case TIMER1_32BIT:
			channelPtr = (volatile uint8*)GPT_32BIT_WIDE_TIMER1_BASE_ADDRESS;
			break;
		case TIMER2_32BIT:
			channelPtr = (volatile uint8*)GPT_32BIT_WIDE_TIMER2_BASE_ADDRESS;
			break;
		case TIMER3_32BIT:
			channelPtr = (volatile uint8*)GPT_32BIT_WIDE_TIMER3_BASE_ADDRESS;
			break;
		case TIMER4_32BIT:
			channelPtr = (volatile uint8*)GPT_32BIT_WIDE_TIMER4_BASE_ADDRESS;
			break;
		case TIMER5_32BIT:
			channelPtr = (volatile uint8*)GPT_32BIT_WIDE_TIMER5_BASE_ADDRESS;
			break;
		default:
			return;
	}
	
	GPT_GPTMCTL(channelPtr).TAEN = 0;
}

/*******************************************************************************
* Service Name: Gpt_GetTimeElapsed
* Service ID[hex]: 0x05
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): 
* Parameters (inout): None
* Parameters (out): None
* Return value: Gpt_ValueType
* Description: 
*******************************************************************************/
Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType ChannelId)
{
	const Gpt_ChannelConfigType* ConfigPtr = &(Gpt_Config.channels[ChannelId]);
	
	volatile uint8* channelPtr = ((void *)0);
	volatile uint8 timerWidth = 0;
	
	switch (ConfigPtr->channelId)
	{
		case TIMER0_16BIT:
			channelPtr = (volatile uint8*)GPT_16BIT_TIMER0_BASE_ADDRESS;
			timerWidth = 32;
			break;
		case TIMER1_16BIT:
			channelPtr = (volatile uint8*)GPT_16BIT_TIMER1_BASE_ADDRESS;
			timerWidth = 32;
			break;
		case TIMER2_16BIT:
			channelPtr = (volatile uint8*)GPT_16BIT_TIMER2_BASE_ADDRESS;
			timerWidth = 32;
			break;
		case TIMER3_16BIT:
			channelPtr = (volatile uint8*)GPT_16BIT_TIMER3_BASE_ADDRESS;
			timerWidth = 32;
			break;
		case TIMER4_16BIT:
			channelPtr = (volatile uint8*)GPT_16BIT_TIMER4_BASE_ADDRESS;
			timerWidth = 32;
			break;
		case TIMER5_16BIT:
			channelPtr = (volatile uint8*)GPT_16BIT_TIMER5_BASE_ADDRESS;
			timerWidth = 32;
			break;
		case TIMER0_32BIT:
			channelPtr = (volatile uint8*)GPT_32BIT_WIDE_TIMER0_BASE_ADDRESS;
			timerWidth = 64;
			break;
		case TIMER1_32BIT:
			channelPtr = (volatile uint8*)GPT_32BIT_WIDE_TIMER1_BASE_ADDRESS;
			timerWidth = 64;
			break;
		case TIMER2_32BIT:
			channelPtr = (volatile uint8*)GPT_32BIT_WIDE_TIMER2_BASE_ADDRESS;
			timerWidth = 64;
			break;
		case TIMER3_32BIT:
			channelPtr = (volatile uint8*)GPT_32BIT_WIDE_TIMER3_BASE_ADDRESS;
			timerWidth = 64;
			break;
		case TIMER4_32BIT:
			channelPtr = (volatile uint8*)GPT_32BIT_WIDE_TIMER4_BASE_ADDRESS;
			timerWidth = 64;
			break;
		case TIMER5_32BIT:
			channelPtr = (volatile uint8*)GPT_32BIT_WIDE_TIMER5_BASE_ADDRESS;
			timerWidth = 64;
			break;
		default:
			break;
	}
	
	if (timerWidth == 32)
	{
		uint32 timeSpent = GPT_GPTMTAV(channelPtr);
		timeSpent = timeSpent / F_CPU;		
		
		return timeSpent;
	}
	else if (timerWidth == 64)
	{
		unsigned long long timeSpent = ((unsigned long long)GPT_GPTMTBV(channelPtr) & (0x00000000FFFFFFFF))<<32;
		timeSpent |= GPT_GPTMTAV(channelPtr) & (0x00000000FFFFFFFF);
		timeSpent = timeSpent / F_CPU;		
		
		return timeSpent;
	}
	
	return 0;
}

/*******************************************************************************
* Service Name: Gpt_GetTimeRemaining
* Service ID[hex]: 0x06
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): 
* Parameters (inout): None
* Parameters (out): None
* Return value: Gpt_ValueType
* Description: 
*******************************************************************************/
Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType ChannelId)
{
	const Gpt_ChannelConfigType* ConfigPtr = &(Gpt_Config.channels[ChannelId]);
	
	volatile uint8* channelPtr = ((void *)0);
	volatile uint8 timerWidth = 0;
	
	switch (ConfigPtr->channelId)
	{
		case TIMER0_16BIT:
			channelPtr = (volatile uint8*)GPT_16BIT_TIMER0_BASE_ADDRESS;
			timerWidth = 32;
			break;
		case TIMER1_16BIT:
			channelPtr = (volatile uint8*)GPT_16BIT_TIMER1_BASE_ADDRESS;
			timerWidth = 32;
			break;
		case TIMER2_16BIT:
			channelPtr = (volatile uint8*)GPT_16BIT_TIMER2_BASE_ADDRESS;
			timerWidth = 32;
			break;
		case TIMER3_16BIT:
			channelPtr = (volatile uint8*)GPT_16BIT_TIMER3_BASE_ADDRESS;
			timerWidth = 32;
			break;
		case TIMER4_16BIT:
			channelPtr = (volatile uint8*)GPT_16BIT_TIMER4_BASE_ADDRESS;
			timerWidth = 32;
			break;
		case TIMER5_16BIT:
			channelPtr = (volatile uint8*)GPT_16BIT_TIMER5_BASE_ADDRESS;
			timerWidth = 32;
			break;
		case TIMER0_32BIT:
			channelPtr = (volatile uint8*)GPT_32BIT_WIDE_TIMER0_BASE_ADDRESS;
			timerWidth = 64;
			break;
		case TIMER1_32BIT:
			channelPtr = (volatile uint8*)GPT_32BIT_WIDE_TIMER1_BASE_ADDRESS;
			timerWidth = 64;
			break;
		case TIMER2_32BIT:
			channelPtr = (volatile uint8*)GPT_32BIT_WIDE_TIMER2_BASE_ADDRESS;
			timerWidth = 64;
			break;
		case TIMER3_32BIT:
			channelPtr = (volatile uint8*)GPT_32BIT_WIDE_TIMER3_BASE_ADDRESS;
			timerWidth = 64;
			break;
		case TIMER4_32BIT:
			channelPtr = (volatile uint8*)GPT_32BIT_WIDE_TIMER4_BASE_ADDRESS;
			timerWidth = 64;
			break;
		case TIMER5_32BIT:
			channelPtr = (volatile uint8*)GPT_32BIT_WIDE_TIMER5_BASE_ADDRESS;
			timerWidth = 64;
			break;
		default:
			break;
	}
	
	if (timerWidth == 32)
	{
		uint32 timeSpent = GPT_GPTMTAV(channelPtr);
		timeSpent = timeSpent / F_CPU;		/* timeSpent = timeSpent / 16 */
		
		uint32 targetTime = GPT_GPTMTAILR(channelPtr);
		
		uint32 timeRemaining = targetTime - timeSpent;
		
		return timeRemaining;
	}
	else if (timerWidth == 64)
	{
		unsigned long long timeSpent = ((unsigned long long)GPT_GPTMTBV(channelPtr) & (0x00000000FFFFFFFF))<<32;
		timeSpent |= GPT_GPTMTAV(channelPtr) & (0x00000000FFFFFFFF);
		timeSpent = timeSpent / F_CPU;		/* timeSpent = timeSpent / 16 */
		
		unsigned long long targetTime = ((unsigned long long)GPT_GPTMTBILR(channelPtr) & (0x00000000FFFFFFFF))<<32;
		targetTime |= GPT_GPTMTAILR(channelPtr) & (0x00000000FFFFFFFF);
		
		unsigned long long timeRemaining = targetTime - timeSpent;
		
		return timeRemaining;
	}
	
	return 0;
}


