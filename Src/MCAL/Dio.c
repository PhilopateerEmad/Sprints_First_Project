/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Dio.c
 *  Module:  	  Dio
 *  Description:  Source file for Dio Module's driver
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Philo emad 
 *	Date:		  21/09/2022
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  									INCLUDES
 *********************************************************************************************************************/
#include "Dio.h"
#include "Macros.h"
#include "Dio_regs.h"
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
 /*******************************************************************************
* Service Name: Dio_WriteChannel
* Service ID[hex]: 0x02
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - Dio_ChannelType, level - Dio_LevelType
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function for DIO write Channel API
*******************************************************************************/
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType level)
{
	switch (channelList.channels[ChannelId].portId)
	{
		case PORTA:
			if (level == LEVEL_HIGH)
				SET_BIT(GPIO_PORTA_DATA, channelList.channels[ChannelId].pinId);
			else
				CLEAR_BIT(GPIO_PORTA_DATA, channelList.channels[ChannelId].pinId);
			break;	
			
		case PORTB:
			if (level == LEVEL_HIGH)
				SET_BIT(GPIO_PORTB_DATA, channelList.channels[ChannelId].pinId);
			else
				CLEAR_BIT(GPIO_PORTB_DATA, channelList.channels[ChannelId].pinId);
			break;	
			
		case PORTC:
			if (level == LEVEL_HIGH)
				SET_BIT(GPIO_PORTC_DATA, channelList.channels[ChannelId].pinId);
			else
				CLEAR_BIT(GPIO_PORTC_DATA, channelList.channels[ChannelId].pinId);
			break;	
			
		case PORTD:
			if (level == LEVEL_HIGH)
				SET_BIT(GPIO_PORTD_DATA, channelList.channels[ChannelId].pinId);
			else
				CLEAR_BIT(GPIO_PORTD_DATA, channelList.channels[ChannelId].pinId);
			break;	
			
		case PORTE:
			if (level == LEVEL_HIGH)
				SET_BIT(GPIO_PORTE_DATA, channelList.channels[ChannelId].pinId);
			else
				CLEAR_BIT(GPIO_PORTE_DATA, channelList.channels[ChannelId].pinId);
			break;	
			
		case PORTF:
			if (level == LEVEL_HIGH)
				SET_BIT(GPIO_PORTF_DATA, channelList.channels[ChannelId].pinId);
			else
				CLEAR_BIT(GPIO_PORTF_DATA, channelList.channels[ChannelId].pinId);
			break;	
	}
}
/*******************************************************************************
* Service Name: Dio_ReadChannel
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - Dio_ChannelType
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_LevelType
* Description: Function for DIO read Channel API
*******************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
	switch (channelList.channels[ChannelId].portId)
	{
		case PORTA:
			if (GET_BIT(GPIO_PORTA_DATA, channelList.channels[ChannelId].pinId) == LEVEL_HIGH)
				return LEVEL_HIGH;
			else
				return LEVEL_LOW;
			break;	
			
		case PORTB:
			if (GET_BIT(GPIO_PORTB_DATA, channelList.channels[ChannelId].pinId) == LEVEL_HIGH)
				return LEVEL_HIGH;
			else
				return LEVEL_LOW;
			break;	
			
		case PORTC:
			if (GET_BIT(GPIO_PORTC_DATA, channelList.channels[ChannelId].pinId) == LEVEL_HIGH)
				return LEVEL_HIGH;
			else
				return LEVEL_LOW;
			break;	
			
		case PORTD:
			if (GET_BIT(GPIO_PORTD_DATA, channelList.channels[ChannelId].pinId) == LEVEL_HIGH)
				return LEVEL_HIGH;
			else
				return LEVEL_LOW;
			break;	
			
		case PORTE:
			if (GET_BIT(GPIO_PORTE_DATA, channelList.channels[ChannelId].pinId) == LEVEL_HIGH)
				return LEVEL_HIGH;
			else
				return LEVEL_LOW;
			break;	
			
		case PORTF:
			if (GET_BIT(GPIO_PORTF_DATA, channelList.channels[ChannelId].pinId) == LEVEL_HIGH)
				return LEVEL_HIGH;
			else
				return LEVEL_LOW;
			break;	
			
		default:
			return DIO_LEVEL_ERROR;
			break; 
	}
}

/*******************************************************************************
* Service Name: Dio_FlipChannel
* Service ID[hex]: 0x02
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - Dio_ChannelType
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_LevelType
* Description: Function for DIO flip Channel, then read Channel API
*******************************************************************************/
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{
	switch (channelList.channels[ChannelId].portId)
	{
		case PORTA:
			if (GET_BIT(GPIO_PORTA_DATA, channelList.channels[ChannelId].pinId) == LEVEL_HIGH)
			{
				CLEAR_BIT(GPIO_PORTA_DATA, channelList.channels[ChannelId].pinId);
				return LEVEL_LOW;
			}
			else
			{
				SET_BIT(GPIO_PORTA_DATA, channelList.channels[ChannelId].pinId);
				return LEVEL_HIGH;
			}
			break;	
			
		case PORTB:
			if (GET_BIT(GPIO_PORTB_DATA, channelList.channels[ChannelId].pinId) == LEVEL_HIGH)
			{
				CLEAR_BIT(GPIO_PORTB_DATA, channelList.channels[ChannelId].pinId);
				return LEVEL_LOW;
			}
			else
			{
				SET_BIT(GPIO_PORTB_DATA, channelList.channels[ChannelId].pinId);
				return LEVEL_HIGH;
			}
			break;	
			
		case PORTC:
			if (GET_BIT(GPIO_PORTC_DATA, channelList.channels[ChannelId].pinId) == LEVEL_HIGH)
			{
				CLEAR_BIT(GPIO_PORTC_DATA, channelList.channels[ChannelId].pinId);
				return LEVEL_LOW;
			}
			else
			{
				SET_BIT(GPIO_PORTC_DATA, channelList.channels[ChannelId].pinId);
				return LEVEL_HIGH;
			}
			break;	
			
		case PORTD:
			if (GET_BIT(GPIO_PORTD_DATA, channelList.channels[ChannelId].pinId) == LEVEL_HIGH)
			{
				CLEAR_BIT(GPIO_PORTD_DATA, channelList.channels[ChannelId].pinId);
				return LEVEL_LOW;
			}
			else
			{
				SET_BIT(GPIO_PORTD_DATA, channelList.channels[ChannelId].pinId);
				return LEVEL_HIGH;
			}
			break;	
			
		case PORTE:
			if (GET_BIT(GPIO_PORTE_DATA, channelList.channels[ChannelId].pinId) == LEVEL_HIGH)
			{
				CLEAR_BIT(GPIO_PORTE_DATA, channelList.channels[ChannelId].pinId);
				return LEVEL_LOW;
			}
			else
			{
				SET_BIT(GPIO_PORTE_DATA, channelList.channels[ChannelId].pinId);
				return LEVEL_HIGH;
			}
			break;	
			
		case PORTF:
			if (GET_BIT(GPIO_PORTF_DATA, channelList.channels[ChannelId].pinId) == LEVEL_HIGH)
			{
				CLEAR_BIT(GPIO_PORTF_DATA, channelList.channels[ChannelId].pinId);
				return LEVEL_LOW;
			}
			else
			{
				SET_BIT(GPIO_PORTF_DATA, channelList.channels[ChannelId].pinId);
				return LEVEL_HIGH;
			}
			break;	
	}
}

/*******************************************************************************
* Service Name: Dio_ReadPort
* Service ID[hex]: 0x03
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): PortId - Dio_PortType
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_PortLevelType
* Description: Function for DIO read Port API
*******************************************************************************/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{	
	switch (channelList.channels[PortId].portId)
	{
		case PORTA:
			return (Dio_PortLevelType)GPIO_PORTA_DATA;
			break;	
			
		case PORTB:
			return (Dio_PortLevelType)GPIO_PORTB_DATA;
			break;	
			
		case PORTC:
			return (Dio_PortLevelType)GPIO_PORTC_DATA;
			break;	
			
		case PORTD:
			return (Dio_PortLevelType)GPIO_PORTD_DATA;
			break;	
			
		case PORTE:
			return (Dio_PortLevelType)GPIO_PORTE_DATA;
			break;	
			
		case PORTF:
			return (Dio_PortLevelType)GPIO_PORTF_DATA;
			break;	
	}
}

/*******************************************************************************
* Service Name: Dio_WritePort
* Service ID[hex]: 0x04
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): PortId - Dio_PortType, level - Dio_PortLevelType
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function for DIO write Port API
*******************************************************************************/
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType level)
{	
	switch (channelList.channels[PortId].portId)
	{
		case PORTA:
			GPIO_PORTA_DATA = level;
			break;	
			
		case PORTB:
			GPIO_PORTB_DATA = level;
			break;	
			
		case PORTC:
			GPIO_PORTC_DATA = level;
			break;	
			
		case PORTD:
			GPIO_PORTD_DATA = level;
			break;	
			
		case PORTE:
			GPIO_PORTE_DATA = level;
			break;	
			
		case PORTF:
			GPIO_PORTF_DATA = level;
			break;	
	}
}

