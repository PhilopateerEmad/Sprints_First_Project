/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Gpt.h
 *  Module:  	  Gpt
 *
 *  Description:  Header file for TM4C123GH6PM MCU - Gpt Module
 *  
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Philo emad
 *	Date:		  21/09/2022
 *********************************************************************************************************************/
#ifndef Gpt_H_
#define Gpt_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Gpt_Types.h"
#include "Gpt_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS PROTOTYPES
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
void Gpt_Init(const Gpt_ChannelConfigType* ConfigPtr);

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
void Gpt_DisableCallback(Gpt_ChannelType ChannelId);

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
void Gpt_EnableCallback(Gpt_ChannelType ChannelId);

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
void Gpt_StartTimer(Gpt_ChannelType ChannelId, Gpt_ValueType Value);

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
void Gpt_StopTimer(Gpt_ChannelType ChannelId);

/*******************************************************************************
* Service Name: Gpt_GetTimeElapsed
* Service ID[hex]: 0x05
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - Pointer to Gpt_ChannelType data
* Parameters (inout): None
* Parameters (out): None
* Return value: Gpt_ValueType
* Description: 
*******************************************************************************/
Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType ChannelId);

/*******************************************************************************
* Service Name: Gpt_GetTimeRemaining
* Service ID[hex]: 0x06
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - Pointer to Gpt_ChannelType data
* Parameters (inout): None
* Parameters (out): None
* Return value: Gpt_ValueType
* Description: 
*******************************************************************************/
Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType ChannelId);

 
#endif  /* Gpt_H_ */


