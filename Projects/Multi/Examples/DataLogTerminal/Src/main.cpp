/**
 ******************************************************************************
 * @file    Projects/Multi/Examples/DataLogTerminal/Src/main.c
 * @author  CL
 * @version V2.1.0
 * @date    4-April-2016
 * @brief   Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; COPYRIGHT(c) 2016 STMicroelectronics</center></h2>
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *   1. Redistributions of source code must retain the above copyright notice,
 *      this list of conditions and the following disclaimer.
 *   2. Redistributions in binary form must reproduce the above copyright notice,
 *      this list of conditions and the following disclaimer in the documentation
 *      and/or other materials provided with the distribution.
 *   3. Neither the name of STMicroelectronics nor the names of its contributors
 *      may be used to endorse or promote products derived from this software
 *      without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/

#include <string.h> /* strlen */
#include <stdio.h>  /* sprintf */
#include <math.h>   /* trunc */
#include "main.h"
#include "UartInterface.h"
#include "SensorAccelReaderInterface.h"
#include "SensorGyroReaderInterface.h"
#include "SensorMagReaderInterface.h"
#include "SensorFusionInterface.h"
#include "SensorApplicationInterface.h"
#include "stm32f4xx_hal_conf.h"


/** @addtogroup X_NUCLEO_IKS01A1_Examples
  * @{
  */

/** @addtogroup DATALOG_TERMINAL
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static RTC_HandleTypeDef RtcHandle;


/* Private function prototypes -----------------------------------------------*/

static void RTC_Config( void );
static void RTC_TimeStampConfig( void );
static void floatToInt( float in, int32_t *out_int, int32_t *out_dec, int32_t dec_prec );
static void RTC_Handler( void );

/* Private functions ---------------------------------------------------------*/

/**
 * @brief  Main function is to show how to use sensor expansion board to send data from a Nucleo board
 *         using UART to a connected PC or Desktop and display it on generic applications like TeraTerm.
 *         After connection has been established:
 *         - the user can view the data from various on-board environment sensors like Temperature, Humidity, and Pressure.
 *         - the user can also view data from various on-board MEMS sensors as well like Accelerometer, Gyroscope, and Magnetometer.
 * @param  None
 * @retval Integer
 */

class Test
{
	public:

		Test()
		: m_Cnt( 0 )
		{}

		~Test(){}

		void SetCnt( uint8_t a_Val )
		{
			m_Cnt = a_Val;
		}

		uint8_t GetCnt() const
		{
			return m_Cnt;
		}

	private:

		uint8_t m_Cnt;

};

int main( void )
{
	Test myTestClassObj;

    // Power up the UART
    UartPowerUp();


    /* STM32F4xx HAL library initialization:
    - Configure the Flash prefetch, instruction and Data caches
    - Configure the Systick to generate an interrupt each 1 msec
    - Set NVIC Group Priority to 4
    - Global MSP (MCU Support Package) initialization
    */
    HAL_Init();

    /* Configure the system clock */
    SystemClock_Config();

    /* Initialize UART */
    USARTConfig();

    /* Initialize RTC */
    RTC_Config();
    RTC_TimeStampConfig();


    // Powerup the various modules
    UartInit();
    SensorFusionPowerUp();
    SensorAccelReaderPowerUp();
    SensorGyroReaderPowerUp();
    SensorMagReaderPowerUp();

    SensorApplicationPowerUp();

    // Init the various modules
    SensorFusionInit();
    SensorAccelReaderInit();
    SensorGyroReaderInit();
    SensorMagReaderInit();
    SensorApplicationInit();

    /* Start scheduler */
    osKernelStart();

    while (1)
    {
    }

}



/**
 * @brief  Splits a float into two integer values.
 * @param  in the float value as input
 * @param  out_int the pointer to the integer part as output
 * @param  out_dec the pointer to the decimal part as output
 * @param  dec_prec the decimal precision to be used
 * @retval None
 */
static void floatToInt( float in, int32_t *out_int, int32_t *out_dec, int32_t dec_prec )
{

  *out_int = (int32_t)in;
  if(in >= 0.0f)
  {
    in = in - (float)(*out_int);
  }
  else
  {
    in = (float)(*out_int) - in;
  }
  *out_dec = (int32_t)trunc(in * pow(10, dec_prec));
}



/**
 * @brief  Handles the time+date getting/sending
 * @param  None
 * @retval None
 */
static void RTC_Handler( void )
{

  uint8_t subSec = 0;
  RTC_DateTypeDef sdatestructureget;
  RTC_TimeTypeDef stimestructure;

  HAL_RTC_GetTime( &RtcHandle, &stimestructure, FORMAT_BIN );
  HAL_RTC_GetDate( &RtcHandle, &sdatestructureget, FORMAT_BIN );
  subSec = (((((( int )RTC_SYNCH_PREDIV) - (( int )stimestructure.SubSeconds)) * 100) / ( RTC_SYNCH_PREDIV + 1 )) & 0xff );

  //sprintf( dataOut, "\n\n\nTimeStamp: %02d:%02d:%02d.%02d\n", stimestructure.Hours, stimestructure.Minutes, stimestructure.Seconds, subSec );
  //HAL_UART_Transmit( &UartHandle, ( uint8_t *)dataOut, strlen( dataOut ), 5000 );
}

/**
 * @brief  Configures the RTC
 * @param  None
 * @retval None
 */
static void RTC_Config( void )
{

  /*##-1- Configure the RTC peripheral #######################################*/
  RtcHandle.Instance = RTC;

  /* Configure RTC prescaler and RTC data registers */
  /* RTC configured as follow:
     - Hour Format    = Format 12
     - Asynch Prediv  = Value according to source clock
     - Synch Prediv   = Value according to source clock
     - OutPut         = Output Disable
     - OutPutPolarity = High Polarity
     - OutPutType     = Open Drain */
  RtcHandle.Init.HourFormat     = RTC_HOURFORMAT_12;
  RtcHandle.Init.AsynchPrediv   = RTC_ASYNCH_PREDIV;
  RtcHandle.Init.SynchPrediv    = RTC_SYNCH_PREDIV;
  RtcHandle.Init.OutPut         = RTC_OUTPUT_DISABLE;
  RtcHandle.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
  RtcHandle.Init.OutPutType     = RTC_OUTPUT_TYPE_OPENDRAIN;

  if ( HAL_RTC_Init( &RtcHandle ) != HAL_OK )
  {

    /* Initialization Error */
    Error_Handler();
  }
}



/**
 * @brief  Configures the current time and date
 * @param  None
 * @retval None
 */
static void RTC_TimeStampConfig( void )
{

  RTC_DateTypeDef sdatestructure;
  RTC_TimeTypeDef stimestructure;

  /*##-3- Configure the Date using BCD format ################################*/
  /* Set Date: Monday January 1st 2000 */
  sdatestructure.Year    = 0x00;
  sdatestructure.Month   = RTC_MONTH_JANUARY;
  sdatestructure.Date    = 0x01;
  sdatestructure.WeekDay = RTC_WEEKDAY_MONDAY;

  if ( HAL_RTC_SetDate( &RtcHandle, &sdatestructure, FORMAT_BCD ) != HAL_OK )
  {

    /* Initialization Error */
    Error_Handler();
  }

  /*##-4- Configure the Time using BCD format#################################*/
  /* Set Time: 00:00:00 */
  stimestructure.Hours          = 0x00;
  stimestructure.Minutes        = 0x00;
  stimestructure.Seconds        = 0x00;
  stimestructure.TimeFormat     = RTC_HOURFORMAT12_AM;
  stimestructure.DayLightSaving = RTC_DAYLIGHTSAVING_NONE ;
  stimestructure.StoreOperation = RTC_STOREOPERATION_RESET;

  if ( HAL_RTC_SetTime( &RtcHandle, &stimestructure, FORMAT_BCD ) != HAL_OK )
  {

    /* Initialization Error */
    Error_Handler();
  }
}



/**
 * @brief  Configures the current time and date
 * @param  hh the hour value to be set
 * @param  mm the minute value to be set
 * @param  ss the second value to be set
 * @retval None
 */
void RTC_TimeRegulate( uint8_t hh, uint8_t mm, uint8_t ss )
{

  RTC_TimeTypeDef stimestructure;

  stimestructure.TimeFormat     = RTC_HOURFORMAT12_AM;
  stimestructure.Hours          = hh;
  stimestructure.Minutes        = mm;
  stimestructure.Seconds        = ss;
  stimestructure.SubSeconds     = 0;
  stimestructure.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
  stimestructure.StoreOperation = RTC_STOREOPERATION_RESET;

  if ( HAL_RTC_SetTime( &RtcHandle, &stimestructure, FORMAT_BIN ) != HAL_OK )
  {

    /* Initialization Error */
    Error_Handler();
  }
}

/**
 * @brief  EXTI line detection callbacks
 * @param  GPIO_Pin: Specifies the pins connected EXTI line
 * @retval None
 */
void HAL_GPIO_EXTI_Callback( uint16_t GPIO_Pin )
{

}

/**
 * @brief  This function is executed in case of error occurrence
 * @param  None
 * @retval None
 */
void Error_Handler( void )
{
  while (1)
  {}
}



#ifdef  USE_FULL_ASSERT

/**
 * @brief  Reports the name of the source file and the source line number
 *   where the assert_param error has occurred
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed( uint8_t *file, uint32_t line )
{

  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  while (1)
  {}
}

#endif

/**
 * @}
 */

/**
 * @}
 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
