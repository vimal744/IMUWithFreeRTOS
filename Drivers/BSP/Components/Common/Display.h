/**
 ******************************************************************************
 * @file    Display.h
 ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _DISPLAY_H
#define _DISPLAY_H

#ifdef __cplusplus
extern "C" {
#endif



/* Includes ------------------------------------------------------------------*/
#include <string.h>
#include "component.h"

/** @addtogroup BSP BSP
 * @{
 */

/** @addtogroup COMPONENTS COMPONENTS
 * @{
 */

/** @addtogroup COMMON COMMON
 * @{
 */

/** @addtogroup DISPLAY DISPLAY
 * @{
 */

/** @addtogroup DISPLAY_Public_Types DISPLAY Public types
 * @{
 */

/**
 * @brief  DISPLAY driver structure definition
 */
typedef struct
{
  DrvStatusTypeDef ( *Init                          ) ( DrvContextTypeDef*                                                                  );
  DrvStatusTypeDef ( *DeInit                        ) ( DrvContextTypeDef*                                                                  );
  DrvStatusTypeDef ( *Display_Enable                ) ( DrvContextTypeDef*                                                                  );
  DrvStatusTypeDef ( *Display_Disable               ) ( DrvContextTypeDef*                                                                  );
  DrvStatusTypeDef ( *Display_FillRect              ) ( DrvContextTypeDef*, uint16_t, int16_t, int16_t, int16_t, int16_t, int16_t, int16_t  );
  DrvStatusTypeDef ( *Display_FillScrn              ) ( DrvContextTypeDef*, uint16_t                                                        );
  DrvStatusTypeDef ( *Display_Write_Char            ) ( DrvContextTypeDef*, unsigned char                                                   );
  DrvStatusTypeDef ( *Display_Set_Cursor            ) ( DrvContextTypeDef*, int16_t,  int16_t                                               );
  DrvStatusTypeDef ( *Display_Set_Text_Color        ) ( DrvContextTypeDef*, uint16_t, uint16_t                                              );
} DISPLAY_Drv_t;

/**
 * @brief  DISPLAY data structure definition
 */
typedef struct
{
  void *pComponentData; /* Component specific data. */
  void *pExtData;       /* Other data. */
} DISPLAY_Data_t;

/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* _DISPLAY_H */
