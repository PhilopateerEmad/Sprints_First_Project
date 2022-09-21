/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Dio_regs.h
 *  Module:  	  Dio_regs
 *
 *  Description:  Header file for Dio Module's registers map
 *  
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Philo emad
 *	Date:		  21/09/2022
 *********************************************************************************************************************/
#ifndef Dio_REGS_H_
#define Dio_REGS_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Port_regs.h"

 
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* GPIO Registers base addresses */
#define GPIO_PORTA_DATA           					(*((volatile uint32*)(GPIO_PORTA_BASE_ADDRESS+GPIO_GPIODATA_OFFSET)))
#define GPIO_PORTB_DATA           					(*((volatile uint32*)(GPIO_PORTB_BASE_ADDRESS+GPIO_GPIODATA_OFFSET)))
#define GPIO_PORTC_DATA           					(*((volatile uint32*)(GPIO_PORTC_BASE_ADDRESS+GPIO_GPIODATA_OFFSET)))
#define GPIO_PORTD_DATA           					(*((volatile uint32*)(GPIO_PORTD_BASE_ADDRESS+GPIO_GPIODATA_OFFSET)))
#define GPIO_PORTE_DATA           					(*((volatile uint32*)(GPIO_PORTE_BASE_ADDRESS+GPIO_GPIODATA_OFFSET)))
#define GPIO_PORTF_DATA           					(*((volatile uint32*)(GPIO_PORTF_BASE_ADDRESS+GPIO_GPIODATA_OFFSET)))
 
#endif  /* DIO_REGS_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Dio_regs.h
 *********************************************************************************************************************/
