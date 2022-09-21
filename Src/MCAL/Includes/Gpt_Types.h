/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Gpt_Types.h
 *  Module:  	  Gpt_Types
 *
 *  Description:  Header file for TM4C123GH6PM MCU - Gpt Module's Types
 *  
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Philo emad 
 *	Date:		  21/09/2022
 *********************************************************************************************************************/
#ifndef GPT_TYPES_H_
#define GPT_TYPES_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "IntCtrl_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define TOTAL_NUM_TIMERS				(12U)

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
typedef enum
{
	TIMER0_16BIT = 0,
	TIMER1_16BIT = 1,
	TIMER2_16BIT = 2,
	TIMER3_16BIT = 3,
	TIMER4_16BIT = 4,
	TIMER5_16BIT = 5,
	TIMER0_32BIT = 6,
	TIMER1_32BIT = 7,
	TIMER2_32BIT = 8,
	TIMER3_32BIT = 9,
	TIMER4_32BIT = 10,
	TIMER5_32BIT = 11
} Gpt_ChannelType;

typedef IntCtrl_InterruptType Gpt_TimerInterruptType;

typedef enum
{
    FULL = 0x0,
	HALF = 0x4
} Gpt_ChannelSizeType;

typedef enum
{
	DOWN = 0x0,
	UP   = 0x1
} Gpt_DirectionType;

typedef enum
{
	DISABLED = 0,
	ENABLED  = 1
} Gpt_EnableType;

typedef enum
{
	GPT_MODE_NORMAL = 0,
	GPT_MODE_SLEEP  = 1
} Gpt_ModeType;

typedef unsigned long long Gpt_ChannelTickFrequencyType;

typedef enum
{
	GPT_MODE_ONESHOT   = 0x1,
	GPT_MODE_CONTINOUS = 0x2
} Gpt_ChannelModeType;

typedef unsigned long long  Gpt_ValueType;

typedef void (*Gpt_CallbackType)(void);

typedef uint8 Gpt_CallbackPriority;



typedef struct
{
	Gpt_ChannelType channelId;
	Gpt_EnableType isEnabled;
	Gpt_DirectionType direction;
	Gpt_ChannelTickFrequencyType frequency;
	Gpt_ChannelModeType mode;
	Gpt_CallbackType Callback;
	Gpt_CallbackPriority priority;
} Gpt_ChannelConfigType;

typedef uint8 Gpt_PredefTimerType;

typedef struct
{
	Gpt_ChannelConfigType channels[TOTAL_NUM_TIMERS];
} Gpt_ConfigType;

#endif  /* GPT_TYPES_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Gpt_Types.h
 *********************************************************************************************************************/
