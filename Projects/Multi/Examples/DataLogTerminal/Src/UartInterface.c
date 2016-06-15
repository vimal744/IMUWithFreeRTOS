/**
  ******************************************************************************
  * File Name          : UartInterface.c
  * Description        : Implementation for the Uart Interface
  ******************************************************************************
  *
  * COPYRIGHT(c) 2016 Vimal Mehta
  *
  ******************************************************************************
  */

/* Public Includes -----------------------------------------------------------*/

#include "UartInterface.h"
#include "GeneralTypes.h"
#include "com.h"
#include "stm32f4xx_hal.h"

/* Private Includes ----------------------------------------------------------*/

/* Literal Constants ---------------------------------------------------------*/

/* Memory Constants ----------------------------------------------------------*/

/* Types ---------------------------------------------------------------------*/

/* Global Variables ----------------------------------------------------------*/

//static USART_HandleTypeDef husart2;

/* Procedures ----------------------------------------------------------------*/

/**
* @brief Power up the uart interface
*/

void UartPowerUp
    (
    void
    )
{
    /* Initialize UART */
    USARTConfig();
}

/**
* @brief Init the UART
*/

void UartInit
    (
    void
    )
{
}

/**
* @brief Write data to the UART
*/

void UartWriteData
    (
    const uint8_t*  a_PtrData,
    uint32_t        a_DataSize,
    uint32_t        a_TimeOut_Ms
    )
{
    if( ( a_PtrData != NULL ) &&
        ( a_DataSize > 0    )
      )
    {
        HAL_UART_Transmit( &UartHandle, (uint8_t*)a_PtrData, a_DataSize, a_TimeOut_Ms );
    }
}
