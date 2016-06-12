
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef ADAFRUIT_DISPLAY_H
#define ADAFRUIT_DISPLAY_H

#ifdef __cplusplus
extern "C" {
#endif


#include "ILI9341_Driver_HL.h"
#include "Display.h"



/* Includes ------------------------------------------------------------------*/
#ifdef USE_STM32F4XX_NUCLEO
#include "stm32f4xx_hal.h"
#endif

typedef enum
{
  DISPLAY_AUTO = -1,
  ILI9341_0
} DISPLAY_ID_t;

DrvStatusTypeDef Display_IO_Init( void );


/* SPI1 peripheral configuration defines */
#define NUCLEO_SPI1                                 SPI1
#define NUCLEO_SPI1_CLK_ENABLE()                    __HAL_RCC_SPI1_CLK_ENABLE()

#define NUCLEO_SPI1_SCK_GPIO_PORT                   GPIOA
#define NUCLEO_SPI1_SCK_AF                          GPIO_AF5_SPI1
#define NUCLEO_SPI1_SCK_PIN                         GPIO_PIN_5
#define NUCLEO_SPI1_SCK_GPIO_CLK_ENABLE()           __HAL_RCC_GPIOA_CLK_ENABLE()
#define NUCLEO_SPI1_SCK_GPIO_CLK_DISABLE()          __HAL_RCC_GPIOA_CLK_DISABLE()


#define NUCLEO_SPI1_MISO_MOSI_AF                    GPIO_AF5_SPI1
#define NUCLEO_SPI1_MISO_PIN                        GPIO_PIN_6
#define NUCLEO_SPI1_MOSI_PIN                        GPIO_PIN_7
#define NUCLEO_SPI1_MISO_MOSI_GPIO_PORT             GPIOA
#define NUCLEO_SPI1_MISO_MOSI_GPIO_CLK_ENABLE()     __HAL_RCC_GPIOA_CLK_ENABLE()
#define NUCLEO_SPI1_MISO_MOSI_GPIO_CLK_DISABLE()    __HAL_RCC_GPIOA_CLK_DISABLE()

#define NUCLEO_SPI1_CS_GPIO_PORT                    GPIOB
#define NUCLEO_SPI1_CS_PIN                          GPIO_PIN_6
#define NUCLEO_SPI1_CS_GPIO_CLK_ENABLE()  //         __HAL_RCC_GPIOB_CLK_ENABLE()
#define NUCLEO_SPI1_CS_GPIO_CLK_DISABLE() //         __HAL_RCC_GPIOB_CLK_DISABLE()

#define NUCLEO_SPI1_DC_GPIO_PORT                    GPIOC
#define NUCLEO_SPI1_DC_PIN                          GPIO_PIN_7
#define NUCLEO_SPI1_DC_GPIO_CLK_ENABLE()           __HAL_RCC_GPIOC_CLK_ENABLE()
#define NUCLEO_SPI1_DC_GPIO_CLK_DISABLE()          __HAL_RCC_GPIOC_CLK_DISABLE()

//#define NUCLEO_DC_LOW()                             HAL_GPIO_WritePin( NUCLEO_SPI1_DC_GPIO_PORT, NUCLEO_SPI1_DC_PIN, GPIO_PIN_RESET )
//#define NUCLEO_DC_HIGH()                            HAL_GPIO_WritePin( NUCLEO_SPI1_DC_GPIO_PORT, NUCLEO_SPI1_DC_PIN, GPIO_PIN_SET   )

/* Maximum Timeout values for flags waiting loops. These timeouts are not based
   on accurate values, they just guarantee that the application will not remain
   stuck if the SPI1 communication is corrupted.
   You may modify these timeout values depending on CPU frequency and application
   conditions (interrupts routines ...). */
#define NUCLEO_SPI1_TIMEOUT_MAX    0x1000 /*<! The value of the maximal timeout for BUS waiting loops */

DrvStatusTypeDef BSP_DISPLAY_Init( DISPLAY_ID_t id, void **handle );
DrvStatusTypeDef BSP_DISPLAY_DeInit( void **handle );
DrvStatusTypeDef BSP_DISPLAY_Enable( void *handle );
DrvStatusTypeDef BSP_DISPLAY_Disable( void *handle );
DrvStatusTypeDef BSP_DISPLAY_Fill_Screen( void *handle, uint16_t a_Color );
DrvStatusTypeDef BSP_DISPLAY_Write_Char( void* handle, unsigned char a_Char );
DrvStatusTypeDef BSP_DISPLAY_Set_Cursor( void *handle, int16_t a_X, int16_t a_Y );
DrvStatusTypeDef BSP_DISPLAY_Set_Text_Color( void *handle, uint16_t a_FC, uint16_t a_BC );
DrvStatusTypeDef BSP_DISPLAY_Write_String( void *handle, char* a_PtrString, uint8_t size );
DrvStatusTypeDef BSP_DISPLAY_Printf( void *handle, char *buf, int size, char *format, ...);


#ifdef __cplusplus
}
#endif

#endif /* ADAFRUIT_DISPLAY_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
