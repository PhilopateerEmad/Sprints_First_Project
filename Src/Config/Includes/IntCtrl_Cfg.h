/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  IntCtrl_Cfg.h
 *  Module:  	  IntCtrl_Cfg
 *
 *  Description:  Header file for TM4C123GH6PM MCU - NVIC Module's configurations
 *  
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Philo emad	
 *	Date:		  21/09/2022
 *********************************************************************************************************************/
#ifndef INTCTRL_CFG_H_
#define INTCTRL_CFG_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "IntCtrl_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define PROCESSOR_EXCEPTIONS_NUM								10
#define MICROCONTROLLER_INTERRUPTS_NUM							24

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
typedef struct
{
	IntCtrl_ExceptionConfigType exceptions[PROCESSOR_EXCEPTIONS_NUM];
	IntCtrl_InterruptConfigType interrupts[MICROCONTROLLER_INTERRUPTS_NUM];
} IntCtrl_ConfigType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
extern IntCtrl_ConfigType IntCtrl_Config;
 
#endif  /* INTCTRL_CFG_H_ */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Cfg.h
 *********************************************************************************************************************/
