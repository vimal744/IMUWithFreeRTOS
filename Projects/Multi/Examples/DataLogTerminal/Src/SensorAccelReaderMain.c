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


#include "AccelTypes.h"
#include "PrintUtility.h"

#include "FreeRTOS.h"
#include "task.h"

/* Private Includes ----------------------------------------------------------*/


/* Literal Constants ---------------------------------------------------------*/

/* Stack size for the sensor reader thread */
#define SNSR_ACCL_READER_MAIN_STK_SZ      ( 512 )

/* Printf statement for debugging */
#define SensorAccelReader_Debug_Printf( _args ) //Printf _args

/* Memory Constants ----------------------------------------------------------*/

static const char* c_ThreadName = "SensorAccelReader_Main";

/* Global Variables ----------------------------------------------------------*/

static TaskHandle_t s_SensorAccelReader_Main_Handle;

static void *LSM6DS0_X_0_handle = NULL;
static boolean s_AccelEnabled = FALSE;
static AccelDataType                s_IntfAccelData;
static SemaphoreHandle_t            s_IntfAccelData_Mutex;



/* Procedures ----------------------------------------------------------------*/

static void initAccelerometer( void );
static void enableAccelerometer( void );
static void disableAccelerometer( void );
static void Accelero_Sensor_Handler( AccelDataType* a_PtrAccelData, void *handle );
static void MainSensorAccelReader( void* a_Ptr );
static void UpdateInterfaceAccelData( const AccelDataType* const a_PtrAccelData );

/**
* @brief Power up the sensor Reader thread
*/

void SensorAccelReaderPowerUp
    ( void )
{
    memset( (void*)&s_IntfAccelData, 0, sizeof( AccelDataType ) );
    s_AccelEnabled = FALSE;
}

/**
* @brief Init the sensor reader thread
*/

void SensorAccelReaderInit
    ( void )
{
    s_IntfAccelData_Mutex = xSemaphoreCreateRecursiveMutex();
    initAccelerometer();
    enableAccelerometer();
    xTaskCreate( MainSensorAccelReader, c_ThreadName, SNSR_ACCL_READER_MAIN_STK_SZ, NULL, SENSOR_ACCL_READER_TASK_PRI, &s_SensorAccelReader_Main_Handle );
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

void SensorAccelGetAccelData
    (
    AccelDataType* a_PtrAccelData
    )
{
xSemaphoreTake( s_IntfAccelData_Mutex, portMAX_DELAY );
*a_PtrAccelData = s_IntfAccelData;
xSemaphoreGive( s_IntfAccelData_Mutex );
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
        // Send Accel data to Sensor Fusion thread
        Accelero_Sensor_Handler( &accelData, LSM6DS0_X_0_handle );
        SensorAccelReader_Debug_Printf(("SR: Tx Accl x=%f, y=%f, z=%f\r\n", accelData.meas[0], accelData.meas[1], accelData.meas[2] ));
        SensorFusionAddAccelData( &accelData );
        UpdateInterfaceAccelData( &accelData );
        osDelay(10);
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
}

/**
 * @brief  Enable all sensors
 * @param  None
 * @retval None
 */
static void enableAccelerometer( void )
{
    if( !s_AccelEnabled )
    {
        BSP_ACCELERO_Sensor_Enable( LSM6DS0_X_0_handle );
        s_AccelEnabled = TRUE;
    }
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

        a_PtrAccelData->meas[0] = -(float)acceleration.AXIS_X / 1000.0f;
        a_PtrAccelData->meas[1] = -(float)acceleration.AXIS_Y / 1000.0f;
        a_PtrAccelData->meas[2] = -(float)acceleration.AXIS_Z / 1000.0f;
    }
}

static void UpdateInterfaceAccelData
    (
    const AccelDataType* const a_PtrAccelData
    )
{
xSemaphoreTake( s_IntfAccelData_Mutex, portMAX_DELAY );
s_IntfAccelData = *a_PtrAccelData;
xSemaphoreGive( s_IntfAccelData_Mutex );
}
