/**
 * @file    ILI9341_Driver.h
 * Refernce:  https://github.com/adafruit/Adafruit_ILI9341
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __ILI9341_DRIVER__H
#define __ILI9341_DRIVER__H

#include <stdint.h>

/* Uncomment the line below to expanse the "assert_param" macro in the drivers code */
#define USE_FULL_ASSERT_ILI9341

/* Exported macro ------------------------------------------------------------*/
#ifdef  USE_FULL_ASSERT_ILI9341

/**
* @brief  The assert_param macro is used for function's parameters check.
* @param  expr: If expr is false, it calls assert_failed function which reports
*         the name of the source file and the source line number of the call
*         that failed. If expr is true, it returns no value.
* @retval None
*/
#define ILI9341_assert_param(expr) ((expr) ? (void)0 : ILI9341_assert_failed((uint8_t *)__FILE__, __LINE__))
/* Exported functions ------------------------------------------------------- */
void ILI9341_assert_failed(uint8_t* file, uint32_t line);
#else
#define ILI9341_assert_param(expr) ((void)0)
#endif /* USE_FULL_ASSERT_ILI9341 */


#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup Environmental_Sensor
* @{
*/

/** @addtogroup ILI9341_DRIVER
* @{
*/

/* Exported Types -------------------------------------------------------------*/
/** @defgroup ILI9341_Exported_Types
* @{
*/


/**
* @brief  Error code type.
*/
typedef enum {ILI9341_OK = (uint8_t)0, ILI9341_ERROR = !ILI9341_OK} ILI9341_Error_et;

/**
* @brief  State type.
*/
typedef enum {ILI9341_DISABLE = (uint8_t)0, ILI9341_ENABLE = !ILI9341_DISABLE} ILI9341_State_et;
#define IS_ILI9341_State(MODE) ((MODE == ILI9341_ENABLE) || (MODE == ILI9341_DISABLE))

/**
* @brief  Bit status type.
*/
typedef enum {ILI9341_RESET = (uint8_t)0, ILI9341_SET = !ILI9341_RESET} ILI9341_BitStatus_et;
#define IS_ILI9341_BitStatus(MODE) ((MODE == ILI9341_RESET) || (MODE == ILI9341_SET))

/**
* @}
*/

#define ILI9341_TFTWIDTH  240
#define ILI9341_TFTHEIGHT 320

#define ILI9341_NOP     0x00
#define ILI9341_SWRESET 0x01
#define ILI9341_RDDID   0x04
#define ILI9341_RDDST   0x09

#define ILI9341_SLPIN   0x10
#define ILI9341_SLPOUT  0x11
#define ILI9341_PTLON   0x12
#define ILI9341_NORON   0x13

#define ILI9341_RDMODE  0x0A
#define ILI9341_RDMADCTL  0x0B
#define ILI9341_RDPIXFMT  0x0C
#define ILI9341_RDIMGFMT  0x0D
#define ILI9341_RDSELFDIAG  0x0F

#define ILI9341_INVOFF  0x20
#define ILI9341_INVON   0x21
#define ILI9341_GAMMASET 0x26
#define ILI9341_DISPOFF 0x28
#define ILI9341_DISPON  0x29

#define ILI9341_CASET   0x2A
#define ILI9341_PASET   0x2B
#define ILI9341_RAMWR   0x2C
#define ILI9341_RAMRD   0x2E

#define ILI9341_PTLAR   0x30
#define ILI9341_MADCTL  0x36
#define ILI9341_PIXFMT  0x3A

#define ILI9341_FRMCTR1 0xB1
#define ILI9341_FRMCTR2 0xB2
#define ILI9341_FRMCTR3 0xB3
#define ILI9341_INVCTR  0xB4
#define ILI9341_DFUNCTR 0xB6

#define ILI9341_PWCTR1  0xC0
#define ILI9341_PWCTR2  0xC1
#define ILI9341_PWCTR3  0xC2
#define ILI9341_PWCTR4  0xC3
#define ILI9341_PWCTR5  0xC4
#define ILI9341_VMCTR1  0xC5
#define ILI9341_VMCTR2  0xC7

#define ILI9341_RDID1   0xDA
#define ILI9341_RDID2   0xDB
#define ILI9341_RDID3   0xDC
#define ILI9341_RDID4   0xDD

#define ILI9341_GMCTRP1 0xE0
#define ILI9341_GMCTRN1 0xE1
/*
#define ILI9341_PWCTR6  0xFC

*/

// Color definitions
#define ILI9341_BLACK       0x0000      /*   0,   0,   0 */
#define ILI9341_NAVY        0x000F      /*   0,   0, 128 */
#define ILI9341_DARKGREEN   0x03E0      /*   0, 128,   0 */
#define ILI9341_DARKCYAN    0x03EF      /*   0, 128, 128 */
#define ILI9341_MAROON      0x7800      /* 128,   0,   0 */
#define ILI9341_PURPLE      0x780F      /* 128,   0, 128 */
#define ILI9341_OLIVE       0x7BE0      /* 128, 128,   0 */
#define ILI9341_LIGHTGREY   0xC618      /* 192, 192, 192 */
#define ILI9341_DARKGREY    0x7BEF      /* 128, 128, 128 */
#define ILI9341_BLUE        0x001F      /*   0,   0, 255 */
#define ILI9341_GREEN       0x07E0      /*   0, 255,   0 */
#define ILI9341_CYAN        0x07FF      /*   0, 255, 255 */
#define ILI9341_RED         0xF800      /* 255,   0,   0 */
#define ILI9341_MAGENTA     0xF81F      /* 255,   0, 255 */
#define ILI9341_YELLOW      0xFFE0      /* 255, 255,   0 */
#define ILI9341_WHITE       0xFFFF      /* 255, 255, 255 */
#define ILI9341_ORANGE      0xFD20      /* 255, 165,   0 */
#define ILI9341_GREENYELLOW 0xAFE5      /* 173, 255,  47 */
#define ILI9341_PINK        0xF81F

#define ILI9341_SPIBUFLEN   128

/* Exported Functions -------------------------------------------------------------*/
/** @defgroup ILI9341_Exported_Functions
* @{
*/

ILI9341_Error_et ILI9341_DeInit(void *handle);
ILI9341_Error_et ILI9341_Activate(void *handle);
ILI9341_Error_et ILI9341_DeActivate(void *handle);
ILI9341_Error_et ILI9341_SetAddressWindow(void *handle, uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1);
ILI9341_Error_et ILI9341_FillRect
    (
    void *handle,
    uint16_t color,
    int16_t x,
    int16_t y,
    int16_t w,
    int16_t h
    );

ILI9341_Error_et ILI9341_FillScreen
    (
    void *handle,
    uint16_t color
    );

ILI9341_Error_et ILI9341_PushColor(void *handle, uint16_t color);
ILI9341_Error_et ILI9341_DrawPixel(void *handle,  int16_t x, int16_t y, uint16_t color);
ILI9341_Error_et ILI9341_DrawFastVerticalLine(void *handle, int16_t x, int16_t y, int16_t h, uint16_t color);
ILI9341_Error_et ILI9341_DrawFastHorizontalLine(void *handle, int16_t x, int16_t y, int16_t w, uint16_t color);

#ifdef __cplusplus
}
#endif


/**
* @}
*/

/**
* @}
*/

/**
* @}
*/

#endif /* __ILI9341_DRIVER__H */

/******************* (C) COPYRIGHT 2013 STMicroelectronics *****END OF FILE****/
