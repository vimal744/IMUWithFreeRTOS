/**
  ******************************************************************************
  * File Name          : SensorGyroReaderMain.h
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

#include "SensorGyroReaderInterface.h"
#include "SensorFusionInterface.h"

#include "x_nucleo_iks01a1.h"
#include "x_nucleo_iks01a1_gyro.h"

#include "GyroTypes.h"
#include "PrintUtility.h"

#include "FreeRTOS.h"
#include "task.h"

/* Private Includes ----------------------------------------------------------*/


/* Literal Constants ---------------------------------------------------------*/

/* Stack size for the sensor reader thread */
#define SNSR_GYRO_READER_MAIN_STK_SZ      ( 256 )

/* Printf statement for debugging */
#define SensorGyroReader_Debug_Printf( _args ) //Printf _args

/* Memory Constants ----------------------------------------------------------*/

static const char* c_ThreadName = "SensorGyroReader_Main";

/* Global Variables ----------------------------------------------------------*/

static TaskHandle_t     s_SensorGyroReader_Main_Handle;
static void*            LSM6DS0_G_0_handle = NULL;
static boolean          s_GyroEnabled = FALSE;

/* Procedures ----------------------------------------------------------------*/

static void initGyro( void );
static void enableGyro( void );
static void disableGyro( void );
static void Gyro_Sensor_Handler( GyroDataType* a_PtrGyroData, void *handle );
static void MainSensorGyroReader( void* a_Ptr );

/**
* @brief Power up the sensor Reader thread
*/

void SensorGyroReaderPowerUp
    ( void )
{
    s_GyroEnabled = FALSE;
    initGyro();
    xTaskCreate( MainSensorGyroReader, c_ThreadName, SNSR_GYRO_READER_MAIN_STK_SZ, NULL, SENSOR_GYRO_READER_TASK_PRI, &s_SensorGyroReader_Main_Handle );
}

/**
* @brief Init the sensor reader thread
*/

void SensorGyroReaderInit
    ( void )
{

}

/**
* @brief Power down the sensor reader thread
*/

void SensorGyroReaderPowerDown
    ( void )
{
    disableGyro();

    if( s_SensorGyroReader_Main_Handle != NULL )
    {
        vTaskDelete( s_SensorGyroReader_Main_Handle );
    }
}


/**
* @brief Main for the sensor Reader thread
*
* NOTE: Currently simulating the data because I could not get the sensor board to work
*
*/

static void MainSensorGyroReader
    (
    void* a_Ptr
    )
{
    GyroDataType    gyroData;

    for(;;)
    {
        enableGyro();

        // Populate Gyro Data
        Gyro_Sensor_Handler( &gyroData, LSM6DS0_G_0_handle );
        SensorGyroReader_Debug_Printf(("SR: Tx Gyro x=%f, y=%f, z=%f\r\n", gyroData.meas[0], gyroData.meas[1], gyroData.meas[2] ));
        SensorFusionAddGyroData( &gyroData );
        osDelay(1);
    }
}

/**
 * @brief  Initialize all sensors
 * @param  None
 * @retval None
 */
static void initGyro( void )
{
    BSP_GYRO_Init( LSM6DS0_G_0, &LSM6DS0_G_0_handle );
}

/**
 * @brief  Enable all sensors
 * @param  None
 * @retval None
 */
static void enableGyro( void )
{
    if( !s_GyroEnabled )
    {
        BSP_GYRO_Sensor_Enable( LSM6DS0_G_0_handle );
        s_GyroEnabled = TRUE;
    }
}

/**
 * @brief  Disable all sensors
 * @param  None
 * @retval None
 */
static void disableGyro( void )
{
    if( s_GyroEnabled )
    {
        BSP_GYRO_Sensor_Disable( LSM6DS0_G_0_handle );
        s_GyroEnabled = TRUE;
    }
}

/**
 * @brief  Handles the gyroscope axes data getting/sending
 * @param  handle the device handle
 * @retval None
 */
static void Gyro_Sensor_Handler
    (
    GyroDataType*   a_PtrGyroData,
    void            *handle
    )
{
    SensorAxes_t    angular_velocity;
    uint8_t         id;
    uint8_t         status;

    BSP_GYRO_Get_Instance( handle, &id );

    BSP_GYRO_IsInitialized( handle, &status );

    if ( status == 1 )
    {
        if ( BSP_GYRO_Get_Axes( handle, &angular_velocity ) == COMPONENT_ERROR )
        {
            angular_velocity.AXIS_X = 0;
            angular_velocity.AXIS_Y = 0;
            angular_velocity.AXIS_Z = 0;
        }

        a_PtrGyroData->meas[0] = (float)angular_velocity.AXIS_X / 1000.0f;
        a_PtrGyroData->meas[1] = (float)angular_velocity.AXIS_Y / 1000.0f;
        a_PtrGyroData->meas[2] = (float)angular_velocity.AXIS_Z / 1000.0f;
    }
}
