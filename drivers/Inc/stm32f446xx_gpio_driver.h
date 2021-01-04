/*
 * stm32f446xx_gpio_driver.h
 *
 *  Created on: 2021. 1. 3.
 *      Author: JKwan
 */

#ifndef INC_STM32F446XX_GPIO_DRIVER_H_
#define INC_STM32F446XX_GPIO_DRIVER_H_

#include "stm32f446xx.h"

/*
 * THis is a Handle structure for a GPIO pin
 */


typedef struct
{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMOde;
	uint8_t GPIO_PinSpeed;
	uint8_t GPIO_PinPuPdControl;
	uint8_t GPIO_PinOPType;
	uint8_t GPIO_PinAltFunMode;
}GPIO_PinConfig_t;

typedef struct
{
	GPIO_RegDef_t* pGPIOx;		/* <This holds the base address of the GPIO port to which the pin belongs > */
	GPIO_PinConfig_t GPIO_PinCofig;	/* < This holds GPIO pin configuration settings > */
}GPIO_Handle_t;

/******************************************************************************
 * 						API supported by this driver
 * 		for more information about the APIs check the function definition
 ******************************************************************************/

/*
 * Peripheral Clock Setup
 */
void GPIO_PeripheralClockControl(GPIO_RegDef_t* pGPIOx, uint8_t EnorDi);

/*
 * Init and De-Init
 */
void GPIO_Init(GPIO_Handle_t* pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t* pGPIOx);

/*
 * Data read and write
 */

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t* pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t* pGPIOx);
void GPIO_WriteToOutputPin(GPIO_RegDef_t* pGPIOx, uint8_t PinNumber, uint8_t Value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t* pGPIOx, uint16_t Value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t* pGPIOx, uint8_t PinNumber);

/*
 * IRQ configuration and ISR handling
 */
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi);
void GPIO_IRQHandling(uint8_t PinNumber);

#endif /* INC_STM32F446XX_GPIO_DRIVER_H_ */
