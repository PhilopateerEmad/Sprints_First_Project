/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  IntCtrl.h
 *  Module:  	  IntCtrl
 *
 *  Description:  Header file for TM4C123GH6PM MCU - NVIC Module
 *  
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Philo emad 
 *	Date:		 21/09/2022
 *********************************************************************************************************************/
#ifndef INTCTRL_H_
#define INTCTRL_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "IntCtrl_Cfg.h"
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
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
void IntCrtl_Init(void);

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
void IntCtrl_EnableInterrupt(IntCtrl_InterruptType interruptIdentifier, IntCtrl_PriorityLevel Priority);

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
void IntCtrl_DisableInterrupt(IntCtrl_InterruptType interruptIdentifier);
 
#endif  /* INTCTRL_H_ */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl.h
 *********************************************************************************************************************/
