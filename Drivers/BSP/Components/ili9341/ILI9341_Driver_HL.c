/**
 * @file    ILI9341_Driver_HL.c
 * Refernce:  https://github.com/adafruit/Adafruit_ILI9341
 */

/* Includes ------------------------------------------------------------------*/
#include "ILI9341_Driver_HL.h"
#include <math.h>


#ifndef min
    #define min(a,b) ((a < b) ? a : b)
#endif

#ifndef abs
    #define abs(a) ((a) < 0 ? -(a) : (a))
#endif

#define pgm_read_byte(addr) (*(const unsigned char *)(addr))


static DrvStatusTypeDef ILI9341_D_Init( DrvContextTypeDef *handle );
static DrvStatusTypeDef ILI9341_D_DeInit( DrvContextTypeDef *handle );
static DrvStatusTypeDef ILI9341_D_Display_Enable( DrvContextTypeDef *handle );
static DrvStatusTypeDef ILI9341_D_Display_Disable( DrvContextTypeDef *handle );
static DrvStatusTypeDef ILI9341_D_Display_Fill_Rectange
    (
    DrvContextTypeDef *handle,
    int16_t x,
    int16_t y,
    int16_t w,
    int16_t h,
    uint16_t color
    );
static DrvStatusTypeDef ILI9341_D_Display_Fill_Screen
    (
    DrvContextTypeDef *handle,
    uint16_t color
    );

static DrvStatusTypeDef ILI9341_D_Display_Set_Pixel( DrvContextTypeDef *handle, int16_t x, int16_t y, uint16_t color );
static DrvStatusTypeDef ILI9341_D_Display_Draw_Vert_Line( DrvContextTypeDef *handle, int16_t x, int16_t y, int16_t h, uint16_t color );
static DrvStatusTypeDef ILI9341_D_Display_Draw_Horz_Line( DrvContextTypeDef *handle, int16_t x, int16_t y, int16_t w, uint16_t color );



static void swap( int16_t a, int16_t b );
static void DrawLine( void *handle, int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);
static void DrawFastVerticalLine( void* handle, int16_t x, int16_t y, int16_t h, uint16_t color);
static void DrawFastHorizontalLine( void* handle, int16_t x, int16_t y, int16_t w, uint16_t color);

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
  ILI9341_D_Display_Set_Pixel,
  ILI9341_D_Display_Draw_Vert_Line,
  ILI9341_D_Display_Draw_Horz_Line,

};

static DrvStatusTypeDef ILI9341_D_Display_Set_Pixel( DrvContextTypeDef *handle, int16_t x, int16_t y, uint16_t color )
{
    if( !handle->isInitialized )
    {
        return COMPONENT_ERROR;
    }

    ILI9341_DrawPixel( (void*)handle, x, y, color);

    return COMPONENT_OK;
}

static DrvStatusTypeDef ILI9341_D_Display_Draw_Vert_Line( DrvContextTypeDef *handle, int16_t x, int16_t y, int16_t h, uint16_t color )
{
    if( !handle->isInitialized )
    {
        return COMPONENT_ERROR;
    }

    ILI9341_DrawFastVerticalLine( (void*)handle, x, y, h, color);

    return COMPONENT_OK;
}

static DrvStatusTypeDef ILI9341_D_Display_Draw_Horz_Line( DrvContextTypeDef *handle, int16_t x, int16_t y, int16_t w, uint16_t color )
{
    if( !handle->isInitialized )
    {
        return COMPONENT_ERROR;
    }

    ILI9341_DrawFastHorizontalLine( (void*)handle, x, y, w, color);

    return COMPONENT_OK;
}

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
    int16_t x,
    int16_t y,
    int16_t w,
    int16_t h,
    uint16_t color
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



// Bresenham's algorithm - thx wikpedia
static void DrawLine( void *handle, int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color)
{
      int16_t steep = abs(y1 - y0) > abs(x1 - x0);
      if (steep) {
        swap(x0, y0);
        swap(x1, y1);
      }

      if (x0 > x1) {
        swap(x0, x1);
        swap(y0, y1);
      }

      int16_t dx, dy;
      dx = x1 - x0;
      dy = abs(y1 - y0);

      int16_t err = dx / 2;
      int16_t ystep;

      if (y0 < y1) {
        ystep = 1;
      } else {
        ystep = -1;
      }

      for (; x0<=x1; x0++) {
        if (steep) {
            ILI9341_DrawPixel(handle, y0, x0, color);
        } else {
            ILI9341_DrawPixel(handle, x0, y0, color);
        }
        err -= dy;
        if (err < 0) {
          y0 += ystep;
          err += dx;
        }
      }
}



static void swap( int16_t a, int16_t b )
{
    int16_t c;

    c = b;
    b = a;
    a = c;
}


static void DrawFastVerticalLine( void* handle, int16_t x, int16_t y, int16_t h, uint16_t color)
{
    // Update in subclasses if desired!
    DrawLine(handle , x, y, x, y+h-1, color);
}

static void DrawFastHorizontalLine( void* handle, int16_t x, int16_t y, int16_t w, uint16_t color)
{
    // Update in subclasses if desired!
    DrawLine(handle, x, y, x+w-1, y, color);
}

