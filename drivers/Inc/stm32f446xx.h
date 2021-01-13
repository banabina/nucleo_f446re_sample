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

/* **************************************START: Processor Specific Details *************************************************/
/*
 * ARM Cortex Mx processor NVIC ISERx register addresses
 */

#define NVIC_ISER0					( (__vo uint32_t*)0xE000E100 )
#define NVIC_ISER1					( (__vo uint32_t*)0xE000E104 )
#define NVIC_ISER2					( (__vo uint32_t*)0xE000E108 )
#define NVIC_ISER3					( (__vo uint32_t*)0xE000E10c )

#define NVIC_ICER0					( (__vo uint32_t*)0XE000E180 )
#define NVIC_ICER1					( (__vo uint32_t*)0XE000E184 )
#define NVIC_ICER2					( (__vo uint32_t*)0XE000E188 )
#define NVIC_ICER3					( (__vo uint32_t*)0XE000E18c )

/*
 * ARM Cortex Mx Processor Priority Register Address Calculation
 */
#define NVIC_PR_BASE_ADDR			( (__vo uint32_t*)0xE000E400 )

/*
 * ARM Cortex Mx Processor number of Priority bits implemented in Priority Register
 */
#define  NO_PR_BITS_IMPLEMENTED		4

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
#define RCC_BASEADDR				(AHB1PERIPH_BASEADDR + 0x3800)

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
	__vo uint32_t OTYPER;						/* GPIO port output type register 				offset : 0x04 */
	__vo uint32_t OSPEEDR;						/* GPIO port output speed register 				offset : 0x08 */
	__vo uint32_t PUPDR;						/* GPIO port pull-up/pull-down register 		offset : 0x0c */
	__vo uint32_t IDR;							/* GPIO port input data register 				offset : 0x10 */
	__vo uint32_t ODR;							/* GPIO port output data register 				offset : 0x14 */
	__vo uint32_t BSRR;							/* GPIO port bit set/reset register 			offset : 0x18 */
	__vo uint32_t LCKR;							/* GPIO port configuration lock register		offset : 0x1c */
	__vo uint32_t AFR[2]; 						/* GPIO alternate function low/high register	offset : 0x20 */
} GPIO_RegDef_t;

typedef struct
{
	__vo uint32_t CR;							/* RCC clock control register 						offset : 0x00 */
	__vo uint32_t PLL_CFGR;						/* RCC PLL configuration register 					offset : 0x04 */
	__vo uint32_t CFGR;							/* RCC clock configuration register					offset : 0x08 */
	__vo uint32_t CIR;							/* RCC clock interrupt register						offset : 0x0C */
	__vo uint32_t AHB1RSTR;						/* RCC AHB1 peripheral reset register 				offset : 0x10 */
	__vo uint32_t AHB2RSTR;						/* RCC AHB2 peripheral reset register				offset : 0x14 */
	__vo uint32_t AHB3RSTR;						/* RCC AHB3 peripheral reset register				offset : 0x18 */
	__vo uint32_t RESERVED0;					/* Reserved */
	__vo uint32_t APB1RSTR;						/* RCC APB1 peripheral reset register 				offset : 0x20 */
	__vo uint32_t APB2RSTR;						/* RCC APB2 peripheral reset register				offset : 0x24 */
	__vo uint32_t RESERVED1[2];					/* Reserved[2] */
	__vo uint32_t AHB1ENR;						/* RCC AHB1 peripheral clock enable register		offset : 0x30 */
	__vo uint32_t AHB2ENR;						/* RCC AHB2 peripheral clock enable register		offset : 0x34 */
	__vo uint32_t AHB3ENR;						/* RCC AHB3 peripheral clock enable register		offset : 0x38 */
	__vo uint32_t RESERVED2;					/* Reserved */
	__vo uint32_t APB1ENR;						/* RCC APB1 peripheral clock enable register		offset : 0x40 */
	__vo uint32_t APB2ENR;						/* RCC APB2 peripheral clock enable register		offset : 0x44 */
	__vo uint32_t RESERVED3[2];					/* Reserved[2] */
	__vo uint32_t AHB1LPENR;					/* RCC AHB1 peripheral clock enable in low power mode register 		offset : 0x50 */
	__vo uint32_t AHB2LPENR;					/* RCC AHB2 peripheral clock enable in low power mode register		offset : 0x54 */
	__vo uint32_t AHB3LPENR;					/* RCC AHB3 peripheral clock enable in low power mode register		offset : 0x58 */
	__vo uint32_t RESERVED4;					/* Reserved*/
	__vo uint32_t APB1LPENR;					/* RCC APB1 peripheral clock enable in low power mode register 		offset : 0x60 */
	__vo uint32_t APB2LPENR;					/* RCC APB2 peripheral clock enable in low power mode register 		offset : 0x64 */
	__vo uint32_t RESERVED5[2];					/* Reserved[2]  */
	__vo uint32_t BDCR;							/* RCC Backup domain control register 				offset : 0x70 */
	__vo uint32_t CSR;							/* RCC clock control & status register 				offset : 0x74 */
	__vo uint32_t RESERVED6[2];					/* RCC clock control register 						offset : 0x00 */
	__vo uint32_t SSCGR;						/* RCC spread spectrum clock generation register 	offset : 0x80 */
	__vo uint32_t PLL_I2S_CFGR;					/* RCC PLLI2S configuration register				offset : 0x84 */
	__vo uint32_t PLL_SAI_CFGR;					/* RCC PLL configuration register					offset : 0x88 */
	__vo uint32_t DCK_CFGR;						/* RCC Dedicated Clock Configuration Register		offset : 0x8c */
	__vo uint32_t CK_GATENR;					/* RCC clocks gated enable register 				offset : 0x90 */
	__vo uint32_t DCK_CFGR2;					/* RCC dedicated clocks configuration register 2	offset : 0x94 */
} RCC_RegDef_t;

/*
 * peripheral register definition structure for EXTI
 */
typedef struct
{
	__vo uint32_t IMR;							/* Interrupt mask register							offset : 0x00	*/
	__vo uint32_t EMR;							/* Event mask register								offset : 0x04	*/
	__vo uint32_t RTSR;							/* Rising trigger selection register				offset : 0x08	*/
	__vo uint32_t FTSR;							/* Falling trigger selection register				offset : 0x0C	*/
	__vo uint32_t SWIER;						/* Software interrupt event register				offset : 0x10	*/
	__vo uint32_t PR;							/* Pending register									offset : 0x14	*/
} EXTI_RegDef_t;

/*
 * peripheral register definition structure for SYSCFG
 */
typedef struct
{
	__vo uint32_t MEMRMP;						/* SYSCFG memory remap register							offset : 0x00	*/
	__vo uint32_t PMC;							/* SYSCFG peripheral mode configuration register		offset : 0x04	*/
	__vo uint32_t EXTICR[4];					/* SYSCFG external interrupt configuration register	offset : 0x08-0x14 */
	uint32_t 	  RESERVED1[2];
	__vo uint32_t CMPCR;						/* Compensation cell control register					offset : 0x20	*/
	uint32_t 	  RESERVED2[2];
	__vo uint32_t CFGR;							/* SYSCFG configuration register 						offset : 0x2C	*/

} SYSCFG_RegDef_t;


/*
 * peripheral register definition structure for SPI
 */
typedef struct
{
	__vo uint32_t CR1;							/* SPI control register 1 (not used in I2S mode)		offset : 0x00	*/
	__vo uint32_t CR2;							/* SPI control register 2 (not used in I2S mode)		offset : 0x04	*/
	__vo uint32_t SR;							/* SPI status register									offset : 0x08	*/
	__vo uint32_t DR;							/* SPI data register									offset : 0x0C   */
	__vo uint32_t CRCPR;						/* SPI CRC polynomial register(not used in I2S mode)	offset : 0x10	*/
	__vo uint32_t RXCRCR;						/* SPI RX CRC register (not used in I2S mode)			offset : 0x14	*/
	__vo uint32_t TXCRCR;						/* SPI TX CRC register (not used in I2S mode)			offset : 0x18	*/
	__vo uint32_t I2SCFGR;						/* SPI_I2S configuration register						offset : 0x1C	*/
	__vo uint32_t I2SPR;						/* SPI_I2S prescaler register							offset : 0x20	*/
} SPI_RegDef_t;



/*
 * peripheral definitions ( Peripheral base addresses typecasted to xxx_RegDef_t )
 */

#define GPIOA 						((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB 						((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC 						((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD 						((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE 						((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF 						((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG 						((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define GPIOH 						((GPIO_RegDef_t*)GPIOH_BASEADDR)

#define RCC							((RCC_RegDef_t*)RCC_BASEADDR)

#define EXTI						((EXTI_RegDef_t*)EXTI_BASEADDR)

#define SYSCFG						((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)

#define SPI1						((SPI_RegDef_t*) SPI1_BASEADDR)
#define SPI2						((SPI_RegDef_t*) SPI2_BASEADDR)
#define SPI3						((SPI_RegDef_t*) SPI3_BASEADDR)
#define SPI4						((SPI_RegDef_t*) SPI4 _BASEADDR)

/*
 * Clock Enable Macros for Gpiox peripherals
 */
#define GPIOA_PCLK_EN()	( RCC->AHB1ENR |= ( 1 << 0) )
#define GPIOB_PCLK_EN()	( RCC->AHB1ENR |= ( 1 << 1) )
#define GPIOC_PCLK_EN()	( RCC->AHB1ENR |= ( 1 << 2) )
#define GPIOD_PCLK_EN()	( RCC->AHB1ENR |= ( 1 << 3) )
#define GPIOE_PCLK_EN()	( RCC->AHB1ENR |= ( 1 << 4) )
#define GPIOF_PCLK_EN()	( RCC->AHB1ENR |= ( 1 << 5) )
#define GPIOG_PCLK_EN()	( RCC->AHB1ENR |= ( 1 << 6) )
#define GPIOH_PCLK_EN()	( RCC->AHB1ENR |= ( 1 << 7) )

/*
 * Clock Enable Macros for I2C peripherals
 */
#define I2C1_PCLK_EN()	( RCC->APB1ENR |= ( 1 << 21 ) )
#define I2C2_PCLK_EN()	( RCC->APB1ENR |= ( 1 << 22 ) )
#define I2C3_PCLK_EN()	( RCC->APB1ENR |= ( 1 << 23 ) )


/*
 * Clock Enable Macros for SPIx peripherals
 */
#define SPI1_PCLK_EN()	( RCC->APB2ENR |= ( 1 << 12 ) )
#define SPI4_PCLK_EN()	( RCC->APB2ENR |= ( 1 << 13 ) )

#define SPI2_PCLK_EN()	( RCC->APB1ENR |= ( 1 << 14 ) )
#define SPI3_PCLK_EN()	( RCC->APB1ENR |= ( 1 << 15 ) )


/*
 * Clock Enable Macros for USARTx peripherals
 */
#define USART2_PCLK_EN()	( RCC->APB1ENR |= ( 1 << 17 ) )
#define USART3_PCLK_EN()	( RCC->APB1ENR |= ( 1 << 18 ) )
#define UART4_PCLK_EN()		( RCC->APB1ENR |= ( 1 << 19 ) )
#define UART5_PCLK_EN()		( RCC->APB1ENR |= ( 1 << 20 ) )

#define USART1_PCLK_EN()	( RCC->APB2ENR |= ( 1 << 4 ) )
#define USART6_PCLK_EN()	( RCC->APB2ENR |= ( 1 << 5 ) )


/*
 * Clock Enable Macros for SYSCFG peripherals
 */
#define SYSCFG_PCLK_EN()	( RCC->APB2ENR |= ( 1 << 14 ) )

/*
 * Clock Disable Macros for Gpiox peripherals
 */
#define GPIOA_PCLK_DI()	( RCC->AHB1ENR &= ~( 1 << 0) )
#define GPIOB_PCLK_DI()	( RCC->AHB1ENR &= ~( 1 << 1) )
#define GPIOC_PCLK_DI()	( RCC->AHB1ENR &= ~( 1 << 2) )
#define GPIOD_PCLK_DI()	( RCC->AHB1ENR &= ~( 1 << 3) )
#define GPIOE_PCLK_DI()	( RCC->AHB1ENR &= ~( 1 << 4) )
#define GPIOF_PCLK_DI()	( RCC->AHB1ENR &= ~( 1 << 5) )
#define GPIOG_PCLK_DI()	( RCC->AHB1ENR &= ~( 1 << 6) )
#define GPIOH_PCLK_DI()	( RCC->AHB1ENR &= ~( 1 << 7) )

/*
 * Clock Disable Macros for I2C peripherals
 */
#define I2C1_PCLK_DI()	( RCC->APB1ENR &= ~( 1 << 21 ) )
#define I2C2_PCLK_DI()	( RCC->APB1ENR &= ~( 1 << 22 ) )
#define I2C3_PCLK_DI()	( RCC->APB1ENR &= ~( 1 << 23 ) )


/*
 * Clock Disable Macros for SPIx peripherals
 */
#define SPI1_PCLK_DI()	( RCC->APB2ENR &= ~( 1 << 12 ) )
#define SPI4_PCLK_DI()	( RCC->APB2ENR &= ~( 1 << 13 ) )

#define SPI2_PCLK_DI()	( RCC->APB1ENR &= ~( 1 << 14 ) )
#define SPI3_PCLK_DI()	( RCC->APB1ENR &= ~( 1 << 15 ) )


/*
 * Clock Disable Macros for USARTx peripherals
 */
#define USART2_PCLK_DI()	( RCC->APB1ENR &= ~( 1 << 17 ) )
#define USART3_PCLK_DI()	( RCC->APB1ENR &= ~( 1 << 18 ) )
#define UART4_PCLK_DI()		( RCC->APB1ENR &= ~( 1 << 19 ) )
#define UART5_PCLK_DI()		( RCC->APB1ENR &= ~( 1 << 20 ) )

#define USART1_PCLK_DI()	( RCC->APB2ENR &= ~( 1 << 4 ) )
#define USART6_PCLK_DI()	( RCC->APB2ENR &= ~( 1 << 5 ) )


/*
 * Clock Disable Macros for SYSCFG peripherals
 */
#define SYSCFG_PCLK_DI()	( RCC->APB2ENR &= ~( 1 << 14 ) )

/*
 * Macros to reset GPIOx peripherals
 */
#define GPIOA_REG_RESET()	do { (RCC->AHB1RSTR |= (1 << 0)); (RCC->AHB1RSTR |= ~(1 << 0)); } while(0)
#define GPIOB_REG_RESET()	do { (RCC->AHB1RSTR |= (1 << 1)); (RCC->AHB1RSTR |= ~(1 << 1)); } while(0)
#define GPIOC_REG_RESET()	do { (RCC->AHB1RSTR |= (1 << 2)); (RCC->AHB1RSTR |= ~(1 << 2)); } while(0)
#define GPIOD_REG_RESET()	do { (RCC->AHB1RSTR |= (1 << 3)); (RCC->AHB1RSTR |= ~(1 << 3)); } while(0)
#define GPIOE_REG_RESET()	do { (RCC->AHB1RSTR |= (1 << 4)); (RCC->AHB1RSTR |= ~(1 << 4)); } while(0)
#define GPIOF_REG_RESET()	do { (RCC->AHB1RSTR |= (1 << 5)); (RCC->AHB1RSTR |= ~(1 << 5)); } while(0)
#define GPIOG_REG_RESET()	do { (RCC->AHB1RSTR |= (1 << 6)); (RCC->AHB1RSTR |= ~(1 << 6)); } while(0)
#define GPIOH_REG_RESET()	do { (RCC->AHB1RSTR |= (1 << 7)); (RCC->AHB1RSTR |= ~(1 << 7)); } while(0)

// some generic macros
#define ENABLE 				1
#define DISABLE 			0
#define SET					ENABLE
#define RESET				DISABLE
#define GPIO_PIN_SET		SET
#define GPIO_PIN_RESET		RESET

#define GPIO_BASEADDR_TO_CODE(x)	  ( (x == GPIOA) ? 0 : \
										(x == GPIOB) ? 1 : \
										(x == GPIOC) ? 2 : \
										(x == GPIOD) ? 3 : \
										(x == GPIOE) ? 4 : \
										(x == GPIOF) ? 5 : \
										(x == GPIOG) ? 6 : \
										(x == GPIOH) ? 7 : 0 )

/*
 * IRQ(Interrupt Request) Numbers of STM32F446xx MCU
 */

#define IRQ_NO_EXTI0		6
#define IRQ_NO_EXTI1		7
#define IRQ_NO_EXTI2		8
#define IRQ_NO_EXTI3		9
#define IRQ_NO_EXTI4		10
#define IRQ_NO_EXTI9_5		23
#define IRQ_NO_EXTI15_10	40

/*
 * macros for all the possible priority levels
 */

#define NVIC_IRQ_PRI0		0
#define NVIC_IRQ_PRI1		1
#define NVIC_IRQ_PRI2		2
#define NVIC_IRQ_PRI3		3
#define NVIC_IRQ_PRI4		4
#define NVIC_IRQ_PRI5		5
#define NVIC_IRQ_PRI6		6
#define NVIC_IRQ_PRI7		7
#define NVIC_IRQ_PRI8		8
#define NVIC_IRQ_PRI9		9
#define NVIC_IRQ_PRI10		10
#define NVIC_IRQ_PRI11		11
#define NVIC_IRQ_PRI12		12
#define NVIC_IRQ_PRI13		13
#define NVIC_IRQ_PRI14		14
#define NVIC_IRQ_PRI15		15

#include "stm32f446xx_gpio_driver.h"

#endif /* INC_STM32F446XX_H_ */
