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
#include "adafruit_display.h"

#include <queue.h>
#include <string.h>

/* Private Includes ----------------------------------------------------------*/


/* Literal Constants ---------------------------------------------------------*/

#define SENSOR_APP_MAIN_STACK_SIZE      ( 256 )

/* Memory Constants ----------------------------------------------------------*/

static const char* c_ThreadName = "SensorApp_Main";

/* Types ---------------------------------------------------------------------*/

/* Global Variables ----------------------------------------------------------*/

static TaskHandle_t     s_SensorApp_Main_Handle;
static boolean          s_DisplayEnabled = FALSE;
static void *Display_Handle = NULL;


/* Procedures ----------------------------------------------------------------*/

static void MainSensorApp
    (
    void* a_Ptr
    );


static void InitDisplay
    ( void );

static void EnableDisplay
    ( void );



/**
* @brief Power up the sensor application
*/

void SensorApplicationPowerUp
    ( void )
{
    InitDisplay();
    // Create the sensor application thread
    xTaskCreate( MainSensorApp, c_ThreadName, SENSOR_APP_MAIN_STACK_SIZE, NULL, SENSOR_APPLICATION_TASK_PRI, &s_SensorApp_Main_Handle );
}

/**
* @brief Init the sensor application
*/

void SensorApplicationInit
    ( void )
{

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
        BSP_DISPLAY_Fill_Screen( Display_Handle, 0x0000);
        BSP_DISPLAY_Write_Char( Display_Handle, 'A' );
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

    char buffer[64];

    for(;;)
    {
        EnableDisplay();

        SensorQuaternionDataType quaternionSensorData;

        // Get the Quaternion data from the sensor fusion interface
        SensorFusionGetQuaternionData(&quaternionSensorData);

        // Write the data to the console
        BSP_DISPLAY_Fill_Screen( Display_Handle, 0x0000);
        BSP_DISPLAY_Set_Cursor( Display_Handle, 0, 0 );
        BSP_DISPLAY_Set_Text_Color( Display_Handle, 0xFFFF, 0xFFFF );

        BSP_DISPLAY_Printf
            (
            Display_Handle,
            buffer,
			64,
            "Sensor App\n\n"
            );

        BSP_DISPLAY_Printf
            (
            Display_Handle,
            buffer,
			64,
            "  TS =%d\n\n",
            quaternionSensorData.TimeStamp
            );


        BSP_DISPLAY_Printf
            (
            Display_Handle,
            buffer,
			64,
            "  X =%0.3f\n\n",
            quaternionSensorData.MeasurementX
            );

        BSP_DISPLAY_Printf
            (
            Display_Handle,
            buffer,
			64,
            " Y =%0.3f\n\n",
            quaternionSensorData.MeasurementY
            );

        BSP_DISPLAY_Printf
            (
            Display_Handle,
            buffer,
			64,
            " Z =%0.3f\n\n",
            quaternionSensorData.MeasurementZ
            );

        BSP_DISPLAY_Printf
            (
            Display_Handle,
            buffer,
			64,
            " W =%0.3f\n\n",
            quaternionSensorData.MeasurementW
            );

        osDelay(500);
    }
}

