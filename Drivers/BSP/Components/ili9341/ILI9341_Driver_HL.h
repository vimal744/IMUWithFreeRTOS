/**
 * @file    ILI9341_Driver_HL.h
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __ILI9341_DRIVER_HL_H
#define __ILI9341_DRIVER_HL_H

#ifdef __cplusplus
extern "C" {
#endif



/* Includes ------------------------------------------------------------------*/
#include "Display.h"

/* Include sensor component drivers. */
#include "ILI9341_Driver.h"

typedef struct
{
    uint8_t dummy;

} ILI9341_Data_t;

extern DISPLAY_Drv_t        ILI9341_D_Drv;

#ifdef __cplusplus
}
#endif

#endif /* __ILI9341_DRIVER_HL_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
