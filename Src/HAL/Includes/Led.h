/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Led.h
 *  Module:  	  Led
 *  Description:  Header file for Led driver
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Philo emad
 *	Date:		  21/09/2022
 *********************************************************************************************************************/
#ifndef LED_H_
#define LED_H_

/**********************************************************************************************************************
* INCLUDES
*********************************************************************************************************************/
#include "Std_Types.h"
#include "Dio.h"
#include "Led.h"
#include "Dio.h"
#include "Gpt.h"
#include "Macros.h"

/**********************************************************************************************************************
*  GLOBAL DATA PROTOTYPES
*********************************************************************************************************************/
typedef Dio_ChannelType Led_LedChannelType;

typedef Led_LedChannelType Device_Channel; 

typedef uint16 TimeType;

typedef uint8 HighPeriodType;

typedef uint8 LowPeriodType;

typedef Gpt_ChannelType TimerChannelType;
 /**********************************************************************************************************************
 *  GLOBAL FUNCTIONS PROTOTYPES
 *********************************************************************************************************************/
/*******************************************************************************
* Service Name: initLED
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: void
* Description: Function to initialize the connected channel using Port MCAL
*******************************************************************************/
 void initLED(void);
 
 /*******************************************************************************
* Service Name: LedOn
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): LedChannel - An identifier for the dedicated led
* Parameters (inout): None
* Parameters (out): None
* Return value: void
* Description: Function to turn on the Led using Dio MCAL
*******************************************************************************/
 void LedOn(Led_LedChannelType LedChannel);
 
 /*******************************************************************************
* Service Name: LedOff
* Service ID[hex]: 0x02
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): LedChannel - An identifier for the dedicated led
* Parameters (inout): None
* Parameters (out): None
* Return value: void
* Description: Function to turn off the Led using Dio MCAL
*******************************************************************************/
 void LedOff(Led_LedChannelType LedChannel);
 
  /*******************************************************************************
* Service Name: toggleLed
* Service ID[hex]: 0x03
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): LedChannel - An identifier for the dedicated led
* Parameters (inout): None
* Parameters (out): None
* Return value: void
* Description: Function to toggle the Led using Dio MCAL
*******************************************************************************/
void toggleLed(Led_LedChannelType LedChannel);

/*******************************************************************************
* Service Name: Led_RefreshOutput
* Service ID[hex]: 0x04
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): LedChannel - An identifier for the dedicated led
* Parameters (inout): None
* Parameters (out): None
* Return value: void
* Description: Function to refresh the Led's state using Dio MCAL
*******************************************************************************/
void Led_RefreshOutput(Led_LedChannelType LedChannel);
/*******************************************************************************
* Service Name: LedBlink
* Service ID[hex]: 0x05
* Sync/Async: Synchronous
* Reentrancy: Non-Reentrant
* Parameters (in): 
* Parameters (inout): None
* Parameters (out): None
* Return value: void
* Description: 
*******************************************************************************/
void LedBlink(TimerChannelType TimerChannle, Device_Channel DeviceChannel, TimeType Time, HighPeriodType HighPeriod, LowPeriodType LowPeriod);
 
/*******************************************************************************
* Service Name: Blink_Stop
* Service ID[hex]: 0x06
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): DeviceChannel - The device which is blinking
* Parameters (inout): None
* Parameters (out): None
* Return value: void
* Description: 
*******************************************************************************/
void Blink_Stop(Device_Channel DeviceChannel); 
 #endif /* LED_H_ */
 /**********************************************************************************************************************
 *  END OF FILE: Led.h
 *********************************************************************************************************************//**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Dio_Lcfg.c
 *  Module:  	  Dio_Lcfg
 *  Description:  Source file for Dio Module's user configurations at linking stage
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Philo emad
 *	Date:		  21/09/2022
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Dio_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
//const Dio_ConfigType channelList =
//{
//	DIO_CONFIG_LED1_PORT, DIO_CONFIG_LED1_CHANNEL,			
//	DIO_CONFIG_LED2_PORT, DIO_CONFIG_LED2_CHANNEL,		
//	DIO_CONFIG_LED3_PORT, DIO_CONFIG_LED3_CHANNEL,

//};

