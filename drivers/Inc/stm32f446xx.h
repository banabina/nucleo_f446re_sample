/*
 * stm32f446xx.h
 *
 *  Created on: Jan 1, 2021
 *      Author: JKwan
 */

#ifndef INC_STM32F446XX_H_
#define INC_STM32F446XX_H_

#include <stdint.h>

#define __vo volatile
/*
 * base addresses of Flash and SRAM memories
 */
#define FLASH_BASEADDR				0x08000000U		// Main memory
#define SRAM1_BASEADDR				0x20000000U		// 112 KB = 0x1C000
#define SRAM2_BASEADDR				0x2001C000U
#define ROM							0x1FFF0000U		// system memory
#define SRAM 						SRAM1_BASEADDR

/*
 * AHBs and APBx Bus Peripheral base addresses
 */
#define PERIPH_BASEADDR				0x40000000U
#define APB1PERIPH_BASEADDR			PERIPH_BASE
#define APB2PERIPH_BASEADDR			0x40010000U
#define AHB1PERIPH_BASEADDR			0x40020000U
#define AHB2PERIPH_BASEADDR			0x50000000U

/*
 * Base addresses of peripherals which are hanging on AHB1 bus
 */
#define GPIOA_BASEADDR				(AHB1PERIPH_BASEADDR + 0x0000)
#define GPIOB_BASEADDR				(AHB1PERIPH_BASEADDR + 0x0400)
#define GPIOC_BASEADDR				(AHB1PERIPH_BASEADDR + 0x0800)
#define GPIOD_BASEADDR				(AHB1PERIPH_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR				(AHB1PERIPH_BASEADDR + 0x1000)
#define GPIOF_BASEADDR				(AHB1PERIPH_BASEADDR + 0x1400)
#define GPIOG_BASEADDR				(AHB1PERIPH_BASEADDR + 0x1800)
#define GPIOH_BASEADDR				(AHB1PERIPH_BASEADDR + 0x1C00)

/*
 * Base addresses of peripherals which are hanging on APB1 bus
 */
#define I2C1_BASEADDR				(APB1PERIPH_BASEADDR + 0x5400)
#define I2C2_BASEADDR				(APB1PERIPH_BASEADDR + 0x5800)
#define I2C3_BASEADDR				(APB1PERIPH_BASEADDR + 0x5C00)

#define SPI2_BASEADDR				(APB1PERIPH_BASEADDR + 0x3800)
#define SPI3_BASEADDR				(APB1PERIPH_BASEADDR + 0x3C00)

#define USART2_BASEADDR				(APB1PERIPH_BASEADDR + 0x4400)
#define USART3_BASEADDR				(APB1PERIPH_BASEADDR + 0x4800)
#define UART4_BASEADDR				(APB1PERIPH_BASEADDR + 0x4C00)
#define UART5_BASEADDR				(APB1PERIPH_BASEADDR + 0x5000)

/*
 * Base addresses of peripherals which are hanging on APB2 bus
 */
#define EXTI_BASEADDR				(AHB2PERIPH_BASEADDR + 0x3c00)
#define SPI1_BASEADDR				(APB2PERIPH_BASEADDR + 0x3000)
#define SPI4_BASEADDR				(APB2PERIPH_BASEADDR + 0x3400)
#define SYSCFG_BASEADDR				(APB2PERIPH_BASEADDR + 0x3800)
#define USART1_BASEADDR				(APB2PERIPH_BASEADDR + 0x1000)
#define USART6_BASEADDR				(APB2PERIPH_BASEADDR + 0x1400)

/****************************** peripheral register definition structures *****************************/

/*
 * Note : Registers of a peripheral are specific to MCU
 * please check your Device of Reference Manual
 */

typedef struct
{
	__vo uint32_t MODER;						/* GPIO port mode register 						offset : 0x00 */
	__vo uint32_t OTYPER;					/* GPIO port output type register 				offset : 0x04 */
	__vo uint32_t OSPEEDER;					/* GPIO port output speed register 				offset : 0x08 */
	__vo uint32_t PUPDR;						/* GPIO port pull-up/pull-down register 		offset : 0x0c */
	__vo uint32_t IDR;						/* GPIO port input data register 				offset : 0x10 */
	__vo uint32_t ODR;						/* GPIO port output data register 				offset : 0x14 */
	__vo uint32_t BSRR;						/* GPIO port bit set/reset register 			offset : 0x18 */
	__vo uint32_t LCKR;						/* GPIO port configuration lock register		offset : 0x1c */
	__vo uint32_t AFR[2]; 					/* GPIO alternate function low/high register	offset : 0x20 */
}GPIO_RegDef_t;


#endif /* INC_STM32F446XX_H_ */
