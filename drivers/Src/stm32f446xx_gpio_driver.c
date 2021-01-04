/*
 * stm32f446xx_gpio_driver.c
 *
 *  Created on: 2021. 1. 3.
 *      Author: JKwan
 */


#include "stm32f446xx_gpio_driver.h"

/*
 * Peripheral Clock Setup
 */

/*********************************************************************
 * @fn				- GPIO_PeripheralClockControl
 *
 * @ brief			- This function enables or disables peripheral clock for the given GPIO port
 *
 * @param[in]		- base address of the gpio peripheral
 * @param[in] 		- ENABLE or DISABLE macros
 *
 * @return			- none
 *
   @Note			- none
 */
void GPIO_PeripheralClockControl(GPIO_RegDef_t* pGPIOx, uint8_t EnorDi)
{
	if (EnorDi == ENABLE)
	{
		if (pGPIOx == GPIOA)
		{
			GPIOA_PCLK_EN();
		} else if (pGPIOx == GPIOB)
		{
			GPIOB_PCLK_EN();
		} else if (pGPIOx == GPIOC)
		{
			GPIOC_PCLK_EN();
		} else if (pGPIOx == GPIOD)
		{
			GPIOD_PCLK_EN();
		} else if (pGPIOx == GPIOE)
		{
			GPIOE_PCLK_EN();
		} else if (pGPIOx == GPIOF)
		{
			GPIOF_PCLK_EN();
		} else if (pGPIOx == GPIOG)
		{
			GPIOG_PCLK_EN();
		} else if (pGPIOx == GPIOH)
		{
			GPIOH_PCLK_EN();
		}
	} else
	{
		if (pGPIOx == GPIOA)
		{
			GPIOA_PCLK_DI();
		} else if (pGPIOx == GPIOB)
		{
			GPIOB_PCLK_DI();
		} else if (pGPIOx == GPIOC)
		{
			GPIOC_PCLK_DI();
		} else if (pGPIOx == GPIOD)
		{
			GPIOD_PCLK_DI();
		} else if (pGPIOx == GPIOE)
		{
			GPIOE_PCLK_DI();
		} else if (pGPIOx == GPIOF)
		{
			GPIOF_PCLK_DI();
		} else if (pGPIOx == GPIOG)
		{
			GPIOG_PCLK_DI();
		} else if (pGPIOx == GPIOH)
		{
			GPIOH_PCLK_DI();
		}
	}
}

/*
 * Init and De-Init
 */

/*********************************************************************
 * @fn				- GPIO_Init
 *
 * @ brief			- This function inits gpio
 *
 * @param[in]		- gpio handle
 *
 * @return			- none
 *
   @Note			- none
 */
void GPIO_Init(GPIO_Handle_t* pGPIOHandle)
{
	// 1. configure the mode of gpio pin
	int temp;
	if (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG)
	{
		temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber) );
		pGPIOHandle->pGPIOx->MODER &= ~( 0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber) );
		pGPIOHandle->pGPIOx->MODER |= temp;
		temp = 0;
	} else
	{
		// this part will code later (interrupt mode)
	}

	// 2. configure the speed
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber) );
	pGPIOHandle->pGPIOx->OSPEEDR  &= ~( 0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber) );
	pGPIOHandle->pGPIOx->OSPEEDR |= temp;
	temp = 0;

	// 3. configure the pupd settings
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber) );
	pGPIOHandle->pGPIOx->PUPDR &= ~( 0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber) );
	pGPIOHandle->pGPIOx->PUPDR |= temp;
	temp = 0;

	// 4. configure the optypes
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType << (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber) );
	pGPIOHandle->pGPIOx->OTYPER  &= ~( 0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber) );
	pGPIOHandle->pGPIOx->OTYPER |= temp;
	temp = 0;

	// 5. configure the alt funtionality
	if (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN)
	{
		// configure the alt function registers
		 uint8_t temp1, temp2;

		 temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 8;
		 temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 8;

		 pGPIOHandle->pGPIOx->AFR[temp1] &= ~(0xF << (4 * temp2 ) ); // clearing
		 pGPIOHandle->pGPIOx->AFR[temp1] |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode << (4 * temp2 ) );
	}
}
/*********************************************************************
 * @fn				- GPIO_DeInit
 *
 * @ brief			- This function resets gpio
 *
 * @param[in]		- base address of gpio peripheral
 *
 * @return			- none
 *
   @Note			- none
 */
void GPIO_DeInit(GPIO_RegDef_t* pGPIOx)
{
	if (pGPIOx == GPIOA)
	{
		GPIOA_REG_RESET();
	} else if (pGPIOx == GPIOB)
	{
		GPIOB_REG_RESET();
	} else if (pGPIOx == GPIOC)
	{
		GPIOC_REG_RESET();
	} else if (pGPIOx == GPIOD)
	{
		GPIOD_REG_RESET();
	} else if (pGPIOx == GPIOE)
	{
		GPIOE_REG_RESET();
	} else if (pGPIOx == GPIOF)
	{
		GPIOF_REG_RESET();
	} else if (pGPIOx == GPIOG)
	{
		GPIOG_REG_RESET();
	} else if (pGPIOx == GPIOH)
	{
		GPIOH_REG_RESET();
	}
}

/*
 * Data read and write
 */
/*********************************************************************
 * @fn				- GPIO_ReadFromInputPin
 *
 * @ brief			- This function read data from input pin
 *
 * @param[in]		- base address of gpio peripheral
 * @param[in]		- gpio pin number
 *
 * @return			- data from input pin
 *
   @Note			- none
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t* pGPIOx, uint8_t PinNumber)
{
	uint8_t value;
	value = (uint8_t)((pGPIOx->IDR >> PinNumber) & 0x0000001 );

	return value;
}

/*********************************************************************
 * @fn				- GPIO_ReadFromInputPin
 *
 * @ brief			- This function read data from input port
 *
 * @param[in]		- base address of gpio peripheral
 *
 * @return			- data from input port
 *
   @Note			- none
 */uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t* pGPIOx)
{
	uint16_t value;
	value = (uint16_t)pGPIOx->IDR;

	return value;
}

/*********************************************************************
 * @fn				- GPIO_WriteToOutputPin
 *
 * @ brief			- This function writes to output pin
 *
 * @param[in]		- base address of gpio peripheral
 * @param[in]		- gpio pin number
 * @param[in]		- value to write
 *
 * @return			- none
 *
   @Note			- none
 */
void GPIO_WriteToOutputPin(GPIO_RegDef_t* pGPIOx, uint8_t PinNumber, uint8_t Value)
{
	if (Value == GPIO_PIN_SET)
	{
		// write 1 to the output data register at the bit field corresponding to the pin number
		pGPIOx->ODR |= ( 1 << PinNumber);
	} else
	{
		// write 0
		pGPIOx->ODR &= ~( 1 << PinNumber);
	}
}

/*********************************************************************
 * @fn				- GPIO_WriteToOutputPort
 *
 * @ brief			- This function writes to output port
 *
 * @param[in]		- base address of gpio peripheral
 * @param[in]		- value to write
 *
 * @return			- none
 *
   @Note			- none
 */
void GPIO_WriteToOutputPort(GPIO_RegDef_t* pGPIOx, uint16_t Value)
{
	pGPIOx->ODR = Value;
}

/*********************************************************************
 * @fn				- GPIO_ToggleOutputPin
 *
 * @ brief			- This function toggles output pin
 *
 * @param[in]		- base address of gpio peripheral
 * @param[in]		- pin number
 *
 * @return			- none
 *
   @Note			- none
 */
void GPIO_ToggleOutputPin(GPIO_RegDef_t* pGPIOx, uint8_t PinNumber)
{
	pGPIOx->ODR ^= ( 1 << PinNumber);
}


/*
 * IRQ configuration and ISR handling
 */
/*********************************************************************
 * @fn				- GPIO_Init
 *
 * @ brief			- This function inits gpio
 *
 * @param[in]		- gpio
 *
 * @return			- none
 *
   @Note			- none
 */
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi)
{

}

/*********************************************************************
 * @fn				- GPIO_Init
 *
 * @ brief			- This function inits gpio
 *
 * @param[in]		- gpio
 *
 * @return			- none
 *
   @Note			- none
 */
void GPIO_IRQHandling(uint8_t PinNumber)
{

}
