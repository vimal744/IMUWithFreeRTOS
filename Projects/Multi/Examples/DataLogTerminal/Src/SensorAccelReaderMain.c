/**
  ******************************************************************************
  * File Name          : SensorAccelReaderMain.c
  * Description        : Implementation for the Sensor Reader Interface
  ******************************************************************************
  *
  * COPYRIGHT(c) 2016 Vimal Mehta
  *
  ******************************************************************************
  */

/* Public Includes -----------------------------------------------------------*/

#include "GeneralTypes.h"
#include "ThreadPriorities.h"
#include "SensorAccelReaderInterface.h"
#include "SensorFusionInterface.h"

#include "x_nucleo_iks01a1.h"
#include "x_nucleo_iks01a1_accelero.h"
#include "adafruit_display.h"


#include "AccelTypes.h"
#include "PrintUtility.h"

#include "FreeRTOS.h"
#include "task.h"

/* Private Includes ----------------------------------------------------------*/


/* Literal Constants ---------------------------------------------------------*/

/* Stack size for the sensor reader thread */
#define SNSR_ACCL_READER_MAIN_STK_SZ      ( 512 )

/* Printf statement for debugging */
#define SensorAccelReader_Debug_Printf( _args ) Printf _args

/* Memory Constants ----------------------------------------------------------*/

static const char* c_ThreadName = "SensorAccelReader_Main";

/* Global Variables ----------------------------------------------------------*/

static TaskHandle_t s_SensorAccelReader_Main_Handle;

static void *LSM6DS0_X_0_handle = NULL;
static void *Display_Handle = NULL;
static boolean     s_AccelEnabled;


/* Procedures ----------------------------------------------------------------*/

static void initAccelerometer( void );
static void enableAccelerometer( void );
static void disableAccelerometer( void );
static void Accelero_Sensor_Handler( AccelDataType* a_PtrAccelData, void *handle );
static void MainSensorAccelReader( void* a_Ptr );

/**
* @brief Power up the sensor Reader thread
*/

void SensorAccelReaderPowerUp
    ( void )
{
	s_AccelEnabled = FALSE;
    initAccelerometer();
    xTaskCreate( MainSensorAccelReader, c_ThreadName, SNSR_ACCL_READER_MAIN_STK_SZ, NULL, SENSOR_ACCL_READER_TASK_PRI, &s_SensorAccelReader_Main_Handle );
}

/**
* @brief Init the sensor reader thread
*/

void SensorAccelReaderInit
    ( void )
{
}

/**
* @brief Power down the sensor reader thread
*/

void SensorAccelReaderPowerDown
    ( void )
{
    disableAccelerometer();

    if( s_SensorAccelReader_Main_Handle != NULL )
    {
        vTaskDelete( s_SensorAccelReader_Main_Handle );
    }
}


/**
* @brief Main for the sensor Reader thread
*
* NOTE: Currently simulating the data because I could not get the sensor board to work
*
*/

static void MainSensorAccelReader
    (
    void* a_Ptr
    )
{
    AccelDataType   accelData;
    for(;;)
    {
    	if( !s_AccelEnabled )
    	{
    		s_AccelEnabled = TRUE;
    		enableAccelerometer();
    	}

        // Send Accel data to Sensor Fusion thread
        Accelero_Sensor_Handler( &accelData, LSM6DS0_X_0_handle );
        SensorAccelReader_Debug_Printf(("SR: Tx Accl x=%f, y=%f, z=%f\r\n", accelData.meas[0], accelData.meas[1], accelData.meas[2] ));
        //SensorFusionAddAccelData( &accelData );
        osDelay(1000);
    }
}

/**
 * @brief  Initialize all sensors
 * @param  None
 * @retval None
 */
static void initAccelerometer( void )
{
    BSP_ACCELERO_Init( LSM6DS0_X_0, &LSM6DS0_X_0_handle );
    BSP_DISPLAY_Init( ILI9341_0, &Display_Handle );
}

/**
 * @brief  Enable all sensors
 * @param  None
 * @retval None
 */
static void enableAccelerometer( void )
{
  BSP_ACCELERO_Sensor_Enable( LSM6DS0_X_0_handle );
  BSP_DISPLAY_Enable( Display_Handle );
  BSP_DISPLAY_Fill_Screen( Display_Handle, 0x0000);
}

/**
 * @brief  Disable all sensors
 * @param  None
 * @retval None
 */
static void disableAccelerometer( void )
{
   BSP_ACCELERO_Sensor_Disable( LSM6DS0_X_0_handle );
}

/**
 * @brief  Handles the accelerometer axes data getting/sending
 * @param  handle the device handle
 * @retval None
 */
static void Accelero_Sensor_Handler
    (
    AccelDataType*  a_PtrAccelData,
    void            *handle
    )
{

    uint8_t         id;
    SensorAxes_t    acceleration;
    uint8_t         status;

    BSP_ACCELERO_Get_Instance( handle, &id );

    BSP_ACCELERO_IsInitialized( handle, &status );

    if ( status == 1 )
    {
        if ( BSP_ACCELERO_Get_Axes( handle, &acceleration ) == COMPONENT_ERROR )
        {
            acceleration.AXIS_X = 0;
            acceleration.AXIS_Y = 0;
            acceleration.AXIS_Z = 0;
        }


        a_PtrAccelData->meas[0] = (float)acceleration.AXIS_X / 1000.0f;
        a_PtrAccelData->meas[1] = (float)acceleration.AXIS_Y / 1000.0f;
        a_PtrAccelData->meas[2] = (float)acceleration.AXIS_Z / 1000.0f;
    }
}
