/**
  ******************************************************************************
  * File Name          : SensorApplicationInterface.h
  * Description        : Implementation for the Sensor Application
  ******************************************************************************
  *
  * COPYRIGHT(c) 2016 Vimal Mehta
  *
  ******************************************************************************
  */

/* Public Includes -----------------------------------------------------------*/

#include "GeneralTypes.h"
#include "DisplayInterface.h"
#include "adafruit_display.h"

/* Private Includes ----------------------------------------------------------*/


/* Literal Constants ---------------------------------------------------------*/

/* Types ---------------------------------------------------------------------*/

/* Global Variables ----------------------------------------------------------*/

static boolean          s_DisplayEnabled = FALSE;
static void *           Display_Handle = NULL;


/* Procedures ----------------------------------------------------------------*/

static void InitDisplay
    ( void );

static void EnableDisplay
    ( void );

/**
* @brief Power up the sensor application
*/

void DisplayPowerUp
    ( void )
{
    InitDisplay();
}

/**
* @brief Init the sensor application
*/

void DisplayInit
    ( void )
{
    EnableDisplay();
}

/**
* @brief Power down the sensor application
*/

void DisplayPowerDown
    ( void )
{

}

/**
* @brief Power up the sensor application
*/


static void InitDisplay
    ( void )
{
    // Create the sensor application thread
    BSP_DISPLAY_Init( ILI9341_0, &Display_Handle );
}

/**
* @brief Power up the sensor application
*/

static void EnableDisplay
    ( void )
{
    if( !s_DisplayEnabled )
    {
        s_DisplayEnabled = TRUE;
        BSP_DISPLAY_Enable( Display_Handle );
    }
}

void DisplayDrawPixel( int16_t x, int16_t y, uint16_t color )
{
    BSP_DISPLAY_Draw_Pixel( (void*)Display_Handle, x, y, color );
}

// Draw a character
void DisplayFillRectange( int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color )
{
    BSP_DISPLAY_Fill_Rect( Display_Handle, x, y, w, h, color );
}

void DisplayDrawVerticalLine( int16_t x, int16_t y, int16_t h, uint16_t color )
{
    BSP_DISPLAY_Draw_Vert_Line( Display_Handle, x, y, h, color );
}

void DisplayDrawHorizontalLine( int16_t x, int16_t y, int16_t w, uint16_t color )
{
    BSP_DISPLAY_Draw_Horz_Line( Display_Handle, x, y, w, color );
}
