/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Gpt_Lcfg.c
 *  Module:  	  Gpt_Lcfg
 *  Description:  Source file for TM4C123GH6PM MCU - Gpt Module's user configurations at linking stage
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Philo emad 
 *	Date:		  21/09/2022
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Gpt_Types.h"
#include "Gpt_regs.h"
#include "Gpt.h"
#include "Dio.h"
#include "Macros.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS PROTOTYPES
 *********************************************************************************************************************/
void Gpt_Callback_0(void);
void Gpt_Callback_1(void);
void Gpt_Callback_2(void);
void Gpt_Callback_3(void);
void Gpt_Callback_4(void);
void Gpt_Callback_5(void);
void Gpt_Callback_6(void);
void Gpt_Callback_7(void);
void Gpt_Callback_8(void);
void Gpt_Callback_9(void);
void Gpt_Callback_10(void);
void Gpt_Callback_11(void);

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
int Timer0_Counter = 0;

Gpt_ConfigType Gpt_Config = 
{
	TIMER0_16BIT, DISABLED,  UP, 16000000, GPT_MODE_CONTINOUS, Gpt_Callback_0, 0,
	TIMER1_16BIT, DISABLED, UP, 16000000, GPT_MODE_CONTINOUS, Gpt_Callback_1, 0,
	TIMER2_16BIT, DISABLED, UP, 16000000, GPT_MODE_CONTINOUS, Gpt_Callback_2, 0,
	TIMER3_16BIT, DISABLED, UP, 16000000, GPT_MODE_CONTINOUS, Gpt_Callback_3, 0,
	TIMER4_16BIT, DISABLED, UP, 16000000, GPT_MODE_CONTINOUS, Gpt_Callback_4, 0,
	TIMER5_16BIT, DISABLED, UP, 16000000, GPT_MODE_CONTINOUS, Gpt_Callback_5, 0,
	TIMER0_32BIT, DISABLED, UP, 16000000, GPT_MODE_CONTINOUS, Gpt_Callback_6, 0,
	TIMER1_32BIT, DISABLED, UP, 16000000, GPT_MODE_CONTINOUS, Gpt_Callback_7, 0,
	TIMER2_32BIT, DISABLED, UP, 16000000, GPT_MODE_CONTINOUS, Gpt_Callback_8, 0,
	TIMER3_32BIT, DISABLED, UP, 16000000, GPT_MODE_CONTINOUS, Gpt_Callback_9, 0,
	TIMER4_32BIT, DISABLED, UP, 16000000, GPT_MODE_CONTINOUS, Gpt_Callback_10, 0,
	TIMER5_32BIT, DISABLED, UP, 16000000, GPT_MODE_CONTINOUS, Gpt_Callback_11, 0,
};

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/*******************************************************************************
* Service Name: Gpt_Callback_0
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): void
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: 
*******************************************************************************/
void Gpt_Callback_0(void)
{

	Dio_FlipChannel(LED1_CHANNEL_ID);
	Timer0_Counter++;
}

/*******************************************************************************
* Service Name: Gpt_Callback_1
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): void
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: 
*******************************************************************************/
void Gpt_Callback_1(void)
{

}

/*******************************************************************************
* Service Name: Gpt_Callback_2
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): void
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: 
*******************************************************************************/
void Gpt_Callback_2(void)
{
	
}

/*******************************************************************************
* Service Name: Gpt_Callback_3
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): void
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: 
*******************************************************************************/
void Gpt_Callback_3(void)
{
	
}

/*******************************************************************************
* Service Name: Gpt_Callback_4
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): void
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: 
*******************************************************************************/
void Gpt_Callback_4(void)
{
	
}

/*******************************************************************************
* Service Name: Gpt_Callback_5
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): void
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: 
*******************************************************************************/
void Gpt_Callback_5(void)
{
	
}

/*******************************************************************************
* Service Name: Gpt_Callback_6
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): void
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: 
*******************************************************************************/
void Gpt_Callback_6(void)
{
	
}

/*******************************************************************************
* Service Name: Gpt_Callback_7
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): void
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: 
*******************************************************************************/
void Gpt_Callback_7(void)
{
	
}

/*******************************************************************************
* Service Name: Gpt_Callback_8
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): void
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: 
*******************************************************************************/
void Gpt_Callback_8(void)
{
	
}

/*******************************************************************************
* Service Name: Gpt_Callback_9
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): void
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: 
*******************************************************************************/
void Gpt_Callback_9(void)
{
	
}

/*******************************************************************************
* Service Name: Gpt_Callback_10
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): void
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description:
*******************************************************************************/
void Gpt_Callback_10(void)
{
	
}

/*******************************************************************************
* Service Name: Gpt_Callback_11
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): void
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: 
*******************************************************************************/
void Gpt_Callback_11(void)
{
	
}

/**********************************************************************************************************************
 *  TIMERS ISR
 *********************************************************************************************************************/
void TIMER0A_Handler(void)
{
	GPT_GPTMICR(GPT_16BIT_TIMER0_BASE_ADDRESS).TATOCINT = 1;
	
	if(Gpt_Config.channels[0].Callback != ((void *)0))
	{
		Gpt_Config.channels[0].Callback();
	}
}

void TIMER1A_Handler(void)
{
	GPT_GPTMICR(GPT_16BIT_TIMER1_BASE_ADDRESS).TATOCINT = 1;
	
	if(Gpt_Config.channels[1].Callback != ((void *)0))
	{
		Gpt_Config.channels[1].Callback();
	}
}


