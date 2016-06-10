/**
 * @file    ILI9341_Driver_HL.c
 */

/* Includes ------------------------------------------------------------------*/
#include "ILI9341_Driver_HL.h"
#include <math.h>



/** @addtogroup BSP BSP
 * @{
 */

/** @addtogroup COMPONENTS COMPONENTS
 * @{
 */

/** @addtogroup ILI9341 ILI9341
 * @{
 */

/** @addtogroup ILI9341_Callable_Private_FunctionPrototypes Callable private function prototypes
 * @{
 */

static DrvStatusTypeDef ILI9341_D_Init( DrvContextTypeDef *handle );
static DrvStatusTypeDef ILI9341_D_DeInit( DrvContextTypeDef *handle );
static DrvStatusTypeDef ILI9341_D_Display_Enable( DrvContextTypeDef *handle );
static DrvStatusTypeDef ILI9341_D_Display_Disable( DrvContextTypeDef *handle );
static DrvStatusTypeDef ILI9341_D_Display_Fill_Rectange
    (
    DrvContextTypeDef *handle,
    uint16_t color,
    int16_t x,
    int16_t y,
    int16_t w,
    int16_t h
    );
static DrvStatusTypeDef ILI9341_D_Display_Fill_Screen
    (
    DrvContextTypeDef *handle,
    uint16_t color
    );



/**
 * @}
 */

/** @addtogroup ILI9341_Private_Function_Prototypes Private function prototypes
 * @{
 */

static DrvStatusTypeDef ILI9341_Init( DrvContextTypeDef *handle );
static DrvStatusTypeDef ILI9341_Display_Enable( DrvContextTypeDef *handle );
static DrvStatusTypeDef ILI9341_Display_Disable( DrvContextTypeDef *handle );

/**
 * @}
 */

/** @addtogroup ILI9341_Private_Variables Private variables
 * @{
 */

/**
 * @brief ILI9341 humidity driver structure
 */
DISPLAY_Drv_t ILI9341_D_Drv =
{
  ILI9341_D_Init,
  ILI9341_D_DeInit,
  ILI9341_D_Display_Enable,
  ILI9341_D_Display_Disable,
  ILI9341_D_Display_Fill_Rectange,
  ILI9341_D_Display_Fill_Screen,
};

/**
 * @brief Initialize the ILI9341 humidity sensor
 * @param handle the device handle
 * @retval COMPONENT_OK in case of success
 * @retval COMPONENT_ERROR in case of failure
 */
static DrvStatusTypeDef ILI9341_D_Init( DrvContextTypeDef *handle )
{
  if( !handle->isInitialized )
  {
    if(ILI9341_Init(handle) == COMPONENT_ERROR)
    {
      return COMPONENT_ERROR;
    }
  }

  handle->isInitialized = 1;

  return COMPONENT_OK;
}


/**
 * @brief Deinitialize the ILI9341 humidity sensor
 * @param handle the device handle
 * @retval COMPONENT_OK in case of success
 * @retval COMPONENT_ERROR in case of failure
 */
static DrvStatusTypeDef ILI9341_D_DeInit( DrvContextTypeDef *handle )
{

    if( handle->isInitialized )
    {
        if(ILI9341_D_Display_Disable(handle) == COMPONENT_ERROR)
        {
        return COMPONENT_ERROR;
        }
    }

    handle->isInitialized = 0;

    return COMPONENT_OK;
}

/**
 * @brief Enable the ILI9341 humidity sensor
 * @param handle the device handle
 * @retval COMPONENT_OK in case of success
 * @retval COMPONENT_ERROR in case of failure
 */
static DrvStatusTypeDef ILI9341_D_Display_Enable( DrvContextTypeDef *handle )
{

    /* Check if the component is already enabled */
    if( handle->isEnabled == 1 )
    {
        return COMPONENT_OK;
    }

    if(ILI9341_Display_Enable(handle) == COMPONENT_ERROR)
    {
        return COMPONENT_ERROR;
    }

    handle->isEnabled = 1;

    return COMPONENT_OK;
}

/**
 * @brief Disable the ILI9341 humidity sensor
 * @param handle the device handle
 * @retval COMPONENT_OK in case of success
 * @retval COMPONENT_ERROR in case of failure
 */
static DrvStatusTypeDef ILI9341_D_Display_Disable( DrvContextTypeDef *handle )
{

  /* Check if the component is already disabled */
    if( handle->isEnabled == 0 )
    {
        return COMPONENT_OK;
    }

    if(ILI9341_Display_Disable(handle) == COMPONENT_ERROR)
    {
        return COMPONENT_ERROR;
    }

    handle->isEnabled = 0;

    return COMPONENT_OK;
}

static DrvStatusTypeDef ILI9341_D_Display_Fill_Rectange
    (
    DrvContextTypeDef *handle,
    uint16_t color,
    int16_t x,
    int16_t y,
    int16_t w,
    int16_t h
    )
{
  /* Check if the component is already disabled */
    if( handle->isEnabled == 0 )
    {
        return COMPONENT_ERROR;
    }

    if( ILI9341_FillRect(handle, color, x,y,w,h ) == ILI9341_ERROR )
    {
        return COMPONENT_ERROR;
    }

    return COMPONENT_OK;
}

static DrvStatusTypeDef ILI9341_D_Display_Fill_Screen
    (
    DrvContextTypeDef *handle,
    uint16_t color
    )
{
  /* Check if the component is already disabled */
    if( handle->isEnabled == 0 )
    {
        return COMPONENT_ERROR;
    }

    if( ILI9341_FillScreen( handle, color ) == ILI9341_ERROR )
    {
        return COMPONENT_ERROR;
    }

    return COMPONENT_OK;
}

/** @addtogroup ILI9341_Private_Functions Private functions
 * @{
 */

/**
 * @brief Initialize the ILI9341 sensor
 * @param handle the device handle
 * @retval COMPONENT_OK in case of success
 * @retval COMPONENT_ERROR in case of failure
 */
static DrvStatusTypeDef ILI9341_Init( DrvContextTypeDef *handle )
{

  /* Power down the device */
  if ( ILI9341_DeActivate( (void *)handle ) == ILI9341_ERROR )
  {
    return COMPONENT_ERROR;
  }

  return COMPONENT_OK;
}

/**
 * @brief Enable the ILI9341 sensor
 * @param handle the device handle
 * @retval COMPONENT_OK in case of success
 * @retval COMPONENT_ERROR in case of failure
 */
static DrvStatusTypeDef ILI9341_Display_Enable( DrvContextTypeDef *handle )
{

  /* Power up the device */
  if ( ILI9341_Activate( (void *)handle ) == ILI9341_ERROR )
  {
    return COMPONENT_ERROR;
  }

  return COMPONENT_OK;
}

/**
 * @brief Disable the ILI9341 sensor
 * @param handle the device handle
 * @retval COMPONENT_OK in case of success
 * @retval COMPONENT_ERROR in case of failure
 */
static DrvStatusTypeDef ILI9341_Display_Disable( DrvContextTypeDef *handle )
{

  /* Power down the device */
  if ( ILI9341_DeActivate( (void *)handle ) == ILI9341_ERROR )
  {
    return COMPONENT_ERROR;
  }

  return COMPONENT_OK;
}
