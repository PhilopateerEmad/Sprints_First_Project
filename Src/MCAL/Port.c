/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Port.c
 *  Module:  	  Port
 *  Description:  Source file for Port Module's driver
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Philo emad 
 *	Date:		  21/09/2022
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Port.h"
#include "Port_regs.h"
#include "Macros.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
 
/*******************************************************************************
* Service Name: Port_Init
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): 
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: 
*******************************************************************************/
void Port_Init(const Port_configType* ConfigPtr)
{

		uint8 pin = 0;
	volatile uint32* Portptr = ((void *)0); 
	

	for (pin = 0; pin < TOTAL_PORT_NUMBER_OF_PINS; pin++)
	{
		if (ConfigPtr->pinConfigType[pin].isEnabled == CHANNEL_DISABLED)
			continue;
		
		switch (ConfigPtr->pinConfigType[pin].portType)
		{
			case PORTA:
				Portptr = (volatile uint32*)GPIO_PORTA_BASE_ADDRESS;
				SYSCTL_RCGCGPIO.BF.GPIOA = 1;
				break;
			case PORTB:
				Portptr = (volatile uint32*)GPIO_PORTB_BASE_ADDRESS;
				SYSCTL_RCGCGPIO.BF.GPIOB = 1;
				break;
			case PORTC:
				Portptr = (volatile uint32*)GPIO_PORTC_BASE_ADDRESS;
				SYSCTL_RCGCGPIO.BF.GPIOC = 1;
				break;
			case PORTD:
				Portptr = (volatile uint32*)GPIO_PORTD_BASE_ADDRESS;
				SYSCTL_RCGCGPIO.BF.GPIOD = 1;
				break;
			case PORTE:
				Portptr = (volatile uint32*)GPIO_PORTE_BASE_ADDRESS;
				SYSCTL_RCGCGPIO.BF.GPIOE = 1;
				break;
			case PORTF:
				Portptr = (volatile uint32*)GPIO_PORTF_BASE_ADDRESS;
				SYSCTL_RCGCGPIO.BF.GPIOF = 1;
				break;
		}
	
		if ( \
			((ConfigPtr->pinConfigType[pin].portType == PORTD) && (ConfigPtr->pinConfigType[pin].pinType == PIN7)) \
			|| ((ConfigPtr->pinConfigType[pin].portType == PORTF) && (ConfigPtr->pinConfigType[pin].pinType == PIN0)) \
		)
		{
			*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOLOCK_OFFSET) = 0x4C4F434B;
			
			SET_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOCR_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
		}
		else if (((ConfigPtr->pinConfigType[pin].portType == PORTC) && (ConfigPtr->pinConfigType[pin].pinType < PIN4)))
		{

			 continue;
		}
		else
		{

		}
		
		switch (ConfigPtr->pinConfigType[pin].pinModeType)
		{
			case DIO_MODE:
				CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOAMSEL_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
				
				CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOAFSEL_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
				
				*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOPCTL_OFFSET) &= ~(0x0000000F << (ConfigPtr->pinConfigType[pin].pinType * 4));
				
				SET_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIODEN_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
				break;
			case ICU_MODE:
				break;
			case ADC_MODE:
				break;
			default: 
				CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOAMSEL_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
				
				CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOAFSEL_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
				
				*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOPCTL_OFFSET) &= ~(0x0000000F << (ConfigPtr->pinConfigType[pin].pinType * 4));
				
				SET_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIODEN_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
				break;
		}
		
		if (ConfigPtr->pinConfigType[pin].pinDirectionType == OUTPUT)
		{
			SET_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIODIR_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
			
			switch (ConfigPtr->pinConfigType[pin].pinOutputCurrentType)
			{
				case DRIVE_2mA:
					SET_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIODR2R_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIODR4R_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIODR8R_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					break;
				case DRIVE_4mA:
					CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIODR2R_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					SET_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIODR4R_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIODR8R_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					break;
				case DRIVE_8mA:
					CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIODR2R_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIODR4R_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					SET_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIODR8R_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					break;
				default:
					SET_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIODR2R_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIODR4R_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIODR8R_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					break;
			}
			
			if (ConfigPtr->pinConfigType[pin].pinLevelType == PIN_LEVEL_HIGH)
			{
				SET_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIODATA_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
			}
			else
			{
				CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIODATA_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
			}
		}
		else if (ConfigPtr->pinConfigType[pin].pinDirectionType == INPUT)
		{
			CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIODIR_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
		
			switch (ConfigPtr->pinConfigType[pin].pinInternalAttachType)
			{
				case PULL_UP:
					SET_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOPUR_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOPDR_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOODR_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOSLR_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					break;
				case PULL_DOWN:
					CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOPUR_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					SET_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOPDR_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOODR_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOSLR_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					break;
				case OPEN_DRAIN:
					CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOPUR_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOPDR_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					SET_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOODR_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOSLR_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					break;
				case SLEW_RATE:
					CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOPUR_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOPDR_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOODR_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					SET_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOSLR_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					break;
				default: /* Default is PULL_UP */
					SET_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOPUR_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOPDR_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOODR_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					CLEAR_BIT(*(volatile uint32*)((volatile uint8*)Portptr + GPIO_GPIOSLR_OFFSET), ConfigPtr->pinConfigType[pin].pinType);
					break;
			}
		}
		else
		{
			return;
		}
	}
}
