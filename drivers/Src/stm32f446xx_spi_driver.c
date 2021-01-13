/*
 * stm32f446xx_spi_driver.c
 *
 *  Created on: 2021. 1. 13.
 *      Author: new_challenger
 */

/*
 * Configuration structure for SPIx peripheral
 */

#include"stm32f446xx.h"

typedef struct
{
	uint8_t SPI_DeviceMode;
	uint8_t SPI_BusConfig;
	uint8_t SPI_SclkSpeed;
	uint8_t SPI_DFF;
	uint8_t SPI_CPOL;
	uint8_t SPI_CPHA;
	uint8_t SPI_SSM;
}SPI_Config_t;

/*
 * Handle structure for SPIx peripheral
 */
typedef struct
{
	SPI_RegDef_t	*pSPIx;
	SPI_Config_t	SPIConfig;
}SPI_Handle_t;
