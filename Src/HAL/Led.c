/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Led.c
 *  Module:  	  Led
 *  Description:  Source file for Led driver
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Philo emad
 *	Date:		  21/09/2022
 *********************************************************************************************************************/
 
 /**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Led.h"
#include "Port.h"
/**********************************************************************************************************************
 *  STATIC GLOBAL DATA
 *********************************************************************************************************************/
static TimerChannelType timerChannle;
static Device_Channel deviceChannel;
static uint8 flag = 0;

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
void Blinking_CallBack(void)
{
	toggleLed(deviceChannel);
	flag = 1;
}
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
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
void initLED(void)
{
	Port_Init(&Port_ConfigType);
}
 
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
void LedOn(Led_LedChannelType LedChannel)
{
	Dio_WriteChannel(LedChannel, LEVEL_HIGH);
}
 
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
void LedOff(Led_LedChannelType LedChannel)
{
	Dio_WriteChannel(LedChannel, LEVEL_LOW);
}

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
void toggleLed(Led_LedChannelType LedChannel)
{
	Dio_FlipChannel(LedChannel);
}

/*******************************************************************************
* Service Name: LedBlink
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Non-Reentrant
* Parameters (in):
* Parameters (inout): None
* Parameters (out): None
* Return value: void
* Description: 
*******************************************************************************/
void LedBlink(TimerChannelType TimerChannle, Device_Channel DeviceChannel, TimeType Time, HighPeriodType HighPeriod, LowPeriodType LowPeriod)
{
	initLED();
	Dio_WriteChannel(DeviceChannel, LEVEL_HIGH);
	
	timerChannle = TimerChannle;
	
	Gpt_Config.channels[TimerChannle].isEnabled = ENABLED;
	Gpt_Config.channels[TimerChannle].mode = GPT_MODE_ONESHOT;
	Gpt_Config.channels[TimerChannle].Callback = Blinking_CallBack;
	
	Gpt_Init(&Gpt_Config.channels[TimerChannle]);
	
	TimeType period = 0;
	
	while (Time > 0)
	{
		period = HighPeriod;
		
		if (period > Time)
			period = Time;
		
		if (period > 0)
		{
			Gpt_StartTimer(TimerChannle, (period)*1000000);
		
			while(flag != 1);
			flag = 0;
			Time -= period;
		}
		
		if (Time < 1)
			break;
		
		period = LowPeriod;
		
		if (period > Time)
			period = Time;

		Gpt_StartTimer(TimerChannle, (period)*1000000);
	
		while(flag != 1);
		flag = 0;
		Time -= period;
	}
}
 
/*******************************************************************************
* Service Name: Blink_Stop
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): DeviceChannel - The device which is blinking
* Parameters (inout): None
* Parameters (out): None
* Return value: void
* Description:
*******************************************************************************/
void Blink_Stop(Device_Channel DeviceChannel)
{
	Gpt_StopTimer(timerChannle);
	
	LedOff(DeviceChannel);
}
 /**********************************************************************************************************************
 *  END OF FILE: Led.c
 *********************************************************************************************************************/
