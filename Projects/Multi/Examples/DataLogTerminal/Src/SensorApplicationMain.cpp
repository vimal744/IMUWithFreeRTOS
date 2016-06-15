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

#include "SensorApplicationInterface.h"
#include "SensorFusionInterface.h"
#include "ThreadPriorities.h"
#include "FreeRTOS.h"
#include "task.h"
#include "PrintUtility.h"
#include "GraphicsInterface.h"
#include "UserInterface.h"

#include "SensorAccelReaderInterface.h"

#include <queue.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>


/* Private Includes ----------------------------------------------------------*/

/* Literal Constants ---------------------------------------------------------*/

#define SENSOR_APP_MAIN_STACK_SIZE      ( 256 )



/* Memory Constants ----------------------------------------------------------*/

static const char* c_ThreadName = "SensorApp_Main";
static Graphics s_GraphicsObj = Graphics( 240, 320 );

static UI_Label s_Lbl_QuatHdg;
static UI_Label s_Lbl_QuatMeasHdg[5];
static UI_Label s_Lbl_QuatMeasVal[5];

char* Meas_Char_arr[5] = { "T:", "X:", "Y:", "Z:", "W:" };


/* Types ---------------------------------------------------------------------*/

/* Global Variables ----------------------------------------------------------*/

static TaskHandle_t     s_SensorApp_Main_Handle;


/* Procedures ----------------------------------------------------------------*/

static void MainSensorApp
    (
    void* a_Ptr
    );

static int FormatStringToBuf( char *buf, int size, char *format, ...);

/**
* @brief Power up the sensor application
*/

void SensorApplicationPowerUp
    ( void )
{
}

/**
* @brief Init the sensor application
*/

void SensorApplicationInit
    ( void )
{

// Build the UI objects
uint16_t hgd_x = 0;
uint16_t hgd_y = 0;

uint16_t val_x = 0;
uint16_t val_y = 0;


s_GraphicsObj.FillScreen(0x0000);

s_Lbl_QuatHdg.InitLabel( &s_GraphicsObj, 60, 30, 60, 50, 0x0000, 0x0000, 0xFFE0, "Quaternion", 2 );
s_Lbl_QuatHdg.DrawLabel();

hgd_x = 15;
hgd_y = 70;

val_x = hgd_x + 30;
val_y = hgd_y;

for( uint8_t i = 0; i < 5; ++i )
    {
    s_Lbl_QuatMeasHdg[i].InitLabel( &s_GraphicsObj, hgd_x, hgd_y, 20, 20, 0x0000, 0x0000, 0xFFE0, (char*)Meas_Char_arr[i], 2 );
    s_Lbl_QuatMeasHdg[i].DrawLabel();

    s_Lbl_QuatMeasVal[i].InitLabel( &s_GraphicsObj, hgd_x + 50, hgd_y, 20, 20, 0x0000, 0x0000, 0xFFE0, "0.000", 2 );
    s_Lbl_QuatMeasVal[i].DrawLabel();

    hgd_y += 30;
    }

// Create the sensor application thread
xTaskCreate( MainSensorApp, c_ThreadName, SENSOR_APP_MAIN_STACK_SIZE, NULL, SENSOR_APPLICATION_TASK_PRI, &s_SensorApp_Main_Handle );

}

/**
* @brief Power down the sensor application
*/

void SensorApplicationPowerDown
    ( void )
{
     if( s_SensorApp_Main_Handle != NULL )
     {
         vTaskDelete( s_SensorApp_Main_Handle );
     }
}

/**
* @brief Main for the sensor application thread
*/
static void MainSensorApp
    (
    void*           a_Ptr
    )
{
    char buff[15];

    for(;;)
    {
        SensorQuaternionDataType quaternionSensorData;

        // Get the Quaternion data from the sensor fusion interface
        SensorFusionGetQuaternionData(&quaternionSensorData);

        // Update the quaternion data to the display
        FormatStringToBuf( buff, 15, "%u", quaternionSensorData.TimeStamp );
        s_Lbl_QuatMeasVal[0].UpdateText( buff );

        FormatStringToBuf( buff, 15, "%0.3f", quaternionSensorData.MeasurementX );
        s_Lbl_QuatMeasVal[1].UpdateText( buff );

        FormatStringToBuf( buff, 15, "%0.3f", quaternionSensorData.MeasurementY );
        s_Lbl_QuatMeasVal[2].UpdateText( buff );

        FormatStringToBuf( buff, 15, "%0.3f", quaternionSensorData.MeasurementZ );
        s_Lbl_QuatMeasVal[3].UpdateText( buff );

        FormatStringToBuf( buff, 15, "%0.3f", quaternionSensorData.MeasurementW );
        s_Lbl_QuatMeasVal[4].UpdateText( buff );

        osDelay(500);
    }
}

static int FormatStringToBuf( char *buf, int size, char *format, ...)
{
    va_list args;
    int len;
    va_start(args, format);
    len = vsnprintf(buf, size, format, args);
    va_end(args);

    return len;

}


