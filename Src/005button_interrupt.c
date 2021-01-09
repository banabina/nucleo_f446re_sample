/*
 * 005button_interrupt.c
 *
 *  Created on: 2021. 1. 9.
 *      Author: JKwan
 */

#include <string.h>
#include "stm32f446xx.h"

#define LOW					0
#define BTN_PRESSED			LOW
#define DELAY_PERIOD		(500000/2)

void delay(void)
{
	for (uint32_t i = 0; i < DELAY_PERIOD; i++);
}

int main(void)
{
	GPIO_Handle_t GpioLed, GpioButton;
	memset(&GpioLed, 0, sizeof(GpioLed));
	memset(&GpioButton, 0, sizeof(GpioButton));

	GpioLed.pGPIOx = GPIOA;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GpioButton.pGPIOx = GPIOC;
	GpioButton.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
	GpioButton.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IT_FT;
	GpioButton.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioButton.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;

	GPIO_PeripheralClockControl(GPIOA, ENABLE);
	GPIO_PeripheralClockControl(GPIOC, ENABLE);
	GPIO_Init(&GpioLed);
	GPIO_Init(&GpioButton);

	//IRQ configuration
	GPIO_IRQPriorityConfig(IRQ_NO_EXTI15_10, NVIC_IRQ_PRI15);
	GPIO_IRQInterruptConfig(IRQ_NO_EXTI15_10, ENABLE);

	return 0;
}

void EXTI15_10_IRQHandler(void)
{
	GPIO_IRQHandling(GPIO_PIN_NO_13);
	GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_5);
}

