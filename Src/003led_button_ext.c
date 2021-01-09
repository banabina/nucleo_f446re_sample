/*
 * 002led_button.c
 *
 *  Created on: 2021. 1. 5.
 *      Author: JKwan
 */



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
	GPIO_Handle_t GpioLed;

	GpioLed.pGPIOx = GPIOA;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_8;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_Handle_t GpioButton;

	GpioButton.pGPIOx = GPIOB;
	GpioButton.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
	GpioButton.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	GpioButton.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioButton.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;

	GPIO_PeripheralClockControl(GPIOA, ENABLE);
	GPIO_PeripheralClockControl(GPIOB, ENABLE);
	GPIO_Init(&GpioLed);
	GPIO_Init(&GpioButton);

	while(1)
	{
		if (GPIO_ReadFromInputPin(GPIOB, GPIO_PIN_NO_12) == BTN_PRESSED)
		{
			GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_8);
			delay();
		}
	}
	return 0;
}
