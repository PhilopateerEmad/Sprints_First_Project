/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Port_Types.h
 *  Module:  	  Port_Types
 *
 *  Description:  Header file for Port Module's Types
 *  
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Philo emad
 *	Date:		  21/09/2022
 *********************************************************************************************************************/
#ifndef PORT_TYPES_H_
#define PORT_TYPES_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define TOTAL_PORT_NUMBER_OF_PINS				43U

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
typedef enum
{
	PIN0 = 0,
	PIN1 = 1,
	PIN2 = 2,
	PIN3 = 3,
	PIN4 = 4,
	PIN5 = 5,
	PIN6 = 6,
	PIN7 = 7,
} Port_PinType;

typedef enum
{
	PORTA = 0,
	PORTB = 1,
	PORTC = 2,
	PORTD = 3,
	PORTE = 4,
	PORTF = 5
} Port_PortType;

typedef enum
{
	CHANNEL_DISABLED = 0,
	CHANNEL_ENABLED  = 1
} Port_EnableType;

typedef enum
{
	INPUT  = 0,	
	OUTPUT = 1
} Port_PinDirectionType;

typedef enum
{
	DIO_MODE = 0,	
	ICU_MODE = 1,
	ADC_MODE = 2
} Port_PinModeType;

typedef enum
{
	PULL_UP = 0,	
	PULL_DOWN = 1,
	OPEN_DRAIN = 2,
	SLEW_RATE = 3
} Port_PinInternalAttachType;

typedef enum
{
	DRIVE_2mA = 0,	
	DRIVE_4mA = 1,
	DRIVE_8mA = 2
} Port_PinOutputCurrentType;

typedef enum
{
	PIN_LEVEL_LOW = 0,
	PIN_LEVEL_HIGH = 1
} Port_PinLevelType;


typedef struct
{
	Port_PortType portType;
	Port_PinType pinType;
	Port_EnableType isEnabled;
	Port_PinDirectionType pinDirectionType;
	Port_PinLevelType pinLevelType;
	Port_PinModeType pinModeType;
	Port_PinInternalAttachType pinInternalAttachType;
	Port_PinOutputCurrentType pinOutputCurrentType;
} Port_PinConfigType;


typedef struct
{
	Port_PinConfigType pinConfigType[TOTAL_PORT_NUMBER_OF_PINS];
} Port_configType;

#endif  /* PORT_TYPES_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Port_Types.h
 *********************************************************************************************************************/
