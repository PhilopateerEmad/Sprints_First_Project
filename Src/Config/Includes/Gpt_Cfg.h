/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Gpt_Cfg.h
 *  Module:  	  Gpt_Cfg
 *
 *  Description:  Header file for TM4C123GH6PM MCU - Gpt Module's user configurations
 *  
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  philo emad
 *	Date:		  21/09/2022
 *********************************************************************************************************************/
#ifndef GPT_CFG_H_
#define GPT_CFG_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Gpt_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define GPT_PREDEF_TIMER_1US_16BIT						(0U)
#define GPT_PREDEF_TIMER_1US_24BIT						(0U)
#define GPT_PREDEF_TIMER_1US_32BIT						(0U)
#define GPT_PREDEF_TIMER_100US_32BIT					(0U)

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
extern int Timer0_Counter;
extern Gpt_ConfigType Gpt_Config;
#endif  /* GPT_CFG_H_ */


