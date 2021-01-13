/*
 * stm32f446xx_spi_driver.c
 *
 *  Created on: 2021. 1. 13.
 *      Author: new_challenger
 */
#include "stm32f446xx_spi_driver.h"

/*
 * Peripheral Clock setup
 */
/*********************************************************************
 * @fn				- SPI_PeripheralClockControl
 *
 * @ brief			- This function enables or disables peripheral clock for the given GPIO port
 *
 * @param[in]		- base address of the spi peripheral
 * @param[in] 		- ENABLE or DISABLE macros
 *
 * @return			- none
 *
   @Note			- none
 */
void SPI_PeripheralClockControl(SPI_RegDef_t* pSPIx, uint8_t EnorDi)
{

}

/*
 * Init and De-init
 */
/*********************************************************************
 * @fn				- SPI_Init
 *
 * @ brief			- This function enables or disables peripheral clock for the given GPIO port
 *
 * @param[in]		- base address of the spi peripheral
 * @param[in] 		- ENABLE or DISABLE macros
 *
 * @return			- none
 *
   @Note			- none
 */
void SPI_Init(SPI_Handle_t* pSPIHandle)
{

}

/*********************************************************************
 * @fn				- SPI_DeInit
 *
 * @ brief			- This function enables or disables peripheral clock for the given GPIO port
 *
 * @param[in]		- base address of the spi peripheral
 * @param[in] 		- ENABLE or DISABLE macros
 *
 * @return			- none
 *
   @Note			- none
 */
void SPI_DeInit(SPI_RegDef_t* pSPIx)
{

}


/*
 * Data send and Receive
 */
/*********************************************************************
 * @fn				- SPI_DeInit
 *
 * @ brief			- This function enables or disables peripheral clock for the given GPIO port
 *
 * @param[in]		- base address of the spi peripheral
 * @param[in] 		- ENABLE or DISABLE macros
 *
 * @return			- none
 *
   @Note			- none
 */
void SPI_SendData(SPI_RegDef_t* pSPIx, uint8_t* pTxBuffer, uint32_t Len)
{

}


/*********************************************************************
 * @fn				- SPI_DeInit
 *
 * @ brief			- This function enables or disables peripheral clock for the given GPIO port
 *
 * @param[in]		- base address of the spi peripheral
 * @param[in] 		- ENABLE or DISABLE macros
 *
 * @return			- none
 *
   @Note			- none
 */
void SPI_ReceiveData(SPI_RegDef_t* pSPIx, uint8_t* pRxBuffer, uint32_t Len)
{

}

/*
 * IRQ Configuration ans ISR handling
 */

/*********************************************************************
 * @fn				- SPI_DeInit
 *
 * @ brief			- This function enables or disables peripheral clock for the given GPIO port
 *
 * @param[in]		- base address of the spi peripheral
 * @param[in] 		- ENABLE or DISABLE macros
 *
 * @return			- none
 *
   @Note			- none
 */
void SPI_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi)
{

}

/*********************************************************************
 * @fn				- SPI_DeInit
 *
 * @ brief			- This function enables or disables peripheral clock for the given GPIO port
 *
 * @param[in]		- base address of the spi peripheral
 * @param[in] 		- ENABLE or DISABLE macros
 *
 * @return			- none
 *
   @Note			- none
 */
void SPI_IRQPriorityConfig(uint8_t IRQNumber, uint8_t IRQPriority)
{

}

/*********************************************************************
 * @fn				- SPI_DeInit
 *
 * @ brief			- This function enables or disables peripheral clock for the given GPIO port
 *
 * @param[in]		- base address of the spi peripheral
 * @param[in] 		- ENABLE or DISABLE macros
 *
 * @return			- none
 *
   @Note			- none
 */
void SPI_IRQHandling(SPI_Handle_t *pHandle)
{

}

