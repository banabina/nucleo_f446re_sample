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
 * @param[in]		- gpio
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
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t* pGPIOx, uint8_t PinNumber)
{
	return 0;
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
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t* pGPIOx)
{
	return 0;
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
void GPIO_WriteToOutputPin(GPIO_RegDef_t* pGPIOx, uint8_t PinNumber, uint8_t Value)
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
void GPIO_WriteToOutputPort(GPIO_RegDef_t* pGPIOx, uint16_t Value)
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
void GPIO_ToggleOutputPin(GPIO_RegDef_t* pGPIOx, uint8_t PinNumber)
{

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
