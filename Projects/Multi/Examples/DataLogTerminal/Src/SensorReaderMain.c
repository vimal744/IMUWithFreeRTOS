/**
  ******************************************************************************
  * File Name          : SensorReaderInterface.h
  * Description        : Implementation for the Sensor Reader Interface
  ******************************************************************************
  *
  * COPYRIGHT(c) 2016 Vimal Mehta
  *
  ******************************************************************************
  */

/* Public Includes -----------------------------------------------------------*/

#include "GeneralTypes.h"
#include "SensorReaderInterface.h"
#include "SensorFusionInterface.h"

#include "x_nucleo_iks01a1.h"
#include "x_nucleo_iks01a1_accelero.h"
#include "x_nucleo_iks01a1_gyro.h"
#include "x_nucleo_iks01a1_magneto.h"

#include "GyroTypes.h"
#include "AccelTypes.h"
#include "CompassTypes.h"
#include "PrintUtility.h"

#include "FreeRTOS.h"
#include "task.h"

/* Private Includes ----------------------------------------------------------*/


/* Literal Constants ---------------------------------------------------------*/

/* Stack size for the sensor reader thread */
#define SENSOR_MAIN_STACK_SIZE      ( 256 )

/* Printf statement for debugging */
#define SensorReader_Debug_Printf( _args ) //Printf _args

/* Memory Constants ----------------------------------------------------------*/

static const char* c_ThreadName = "SensorReader_Main";

/* Global Variables ----------------------------------------------------------*/

static TaskHandle_t s_SensorReader_Main_Handle;


static void *LSM6DS0_X_0_handle = NULL;
static void *LSM6DS0_G_0_handle = NULL;
static void *LIS3MDL_0_handle   = NULL;

static void initializeAllSensors( void );
static void enableAllSensors( void );
static void disableAllSensors( void );

static void Accelero_Sensor_Handler
    (
    AccelDataType*  a_PtrAccelData,
    void            *handle
    );

static void Gyro_Sensor_Handler
    (
    GyroDataType*   a_PtrGyroData,
    void*           handle
    );
static void Magneto_Sensor_Handler
    (
    CompassDataType* a_PtrCmpsData,
    void*            handle
    );

/* Procedures ----------------------------------------------------------------*/

static void MainSensorReader
    (
    void* a_Ptr
    );

/**
* @brief Power up the sensor Reader thread
*/

void SensorReaderPowerUp
    ( void )
{
    initializeAllSensors();
    xTaskCreate( MainSensorReader, c_ThreadName, SENSOR_MAIN_STACK_SIZE, NULL, tskIDLE_PRIORITY, &s_SensorReader_Main_Handle );
}

/**
* @brief Init the sensor reader thread
*/

void SensorReaderInit
    ( void )
{
    enableAllSensors();
}

/**
* @brief Power down the sensor reader thread
*/

void SensorReaderPowerDown
    ( void )
{
     if( s_SensorReader_Main_Handle != NULL )
     {
         vTaskDelete( s_SensorReader_Main_Handle );
     }
}


/**
* @brief Main for the sensor Reader thread
*
* NOTE: Currently simulating the data because I could not get the sensor board to work
*
*/

static void MainSensorReader
    (
    void* a_Ptr
    )
{
    GyroDataType    gyroData;
    AccelDataType   accelData;
    CompassDataType cmpsData;

    for(;;)
    {
        // Populate Gyro Data
        Gyro_Sensor_Handler( &gyroData, LSM6DS0_G_0_handle );
        SensorReader_Debug_Printf(("SR: Tx Gyro x=%f, y=%f, z=%f\r\n", gyroData.meas[0], gyroData.meas[1], gyroData.meas[2] ));
        SensorFusionAddGyroData( &gyroData );

        // Send Accel data to Sensor Fusion thread
        Accelero_Sensor_Handler( &accelData, LSM6DS0_X_0_handle );
        SensorReader_Debug_Printf(("SR: Tx Accl x=%f, y=%f, z=%f\r\n", accelData.meas[0], accelData.meas[1], accelData.meas[2] ));
        SensorFusionAddAccelData( &accelData );


        // Populate Compass Data
        Magneto_Sensor_Handler( &cmpsData, LIS3MDL_0_handle );
        SensorReader_Debug_Printf(("SR: Tx Cmps x=%f, y=%f, z=%f\r\n", cmpsData.meas[0], cmpsData.meas[1], cmpsData.meas[2] ));
        SensorFusionAddCompassData( &cmpsData );

        osDelay(500);
    }
}

/**
 * @brief  Initialize all sensors
 * @param  None
 * @retval None
 */
static void initializeAllSensors( void )
{
    BSP_ACCELERO_Init( LSM6DS0_X_0, &LSM6DS0_X_0_handle );
    BSP_GYRO_Init( LSM6DS0_G_0, &LSM6DS0_G_0_handle );
    BSP_MAGNETO_Init( LIS3MDL_0, &LIS3MDL_0_handle );
}

/**
 * @brief  Enable all sensors
 * @param  None
 * @retval None
 */
static void enableAllSensors( void )
{
  BSP_ACCELERO_Sensor_Enable( LSM6DS0_X_0_handle );
  BSP_GYRO_Sensor_Enable( LSM6DS0_G_0_handle );
  BSP_MAGNETO_Sensor_Enable( LIS3MDL_0_handle );
}

/**
 * @brief  Disable all sensors
 * @param  None
 * @retval None
 */
static void disableAllSensors( void )
{
  BSP_ACCELERO_Sensor_Disable( LSM6DS0_X_0_handle );
  BSP_GYRO_Sensor_Disable( LSM6DS0_G_0_handle );
  BSP_MAGNETO_Sensor_Disable( LIS3MDL_0_handle );
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

  uint8_t who_am_i;
  float odr;
  float fullScale;
  uint8_t id;
  SensorAxes_t acceleration;
  uint8_t status;
  int32_t d1, d2;

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


    //sprintf( dataOut, "\nACC_X[%d]: %d, ACC_Y[%d]: %d, ACC_Z[%d]: %d\n", (int)id, (int)acceleration.AXIS_X, (int)id, (int)acceleration.AXIS_Y, (int)id, (int)acceleration.AXIS_Z );
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
    float           sensitivity;
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

/**
 * @brief  Handles the magneto axes data getting/sending
 * @param  handle the device handle
 * @retval None
 */
static void Magneto_Sensor_Handler
    (
    CompassDataType* a_PtrCmpsData,
    void*            handle
    )
{

    SensorAxes_t magnetic_field;
    uint8_t id;
    uint8_t status;

    BSP_MAGNETO_Get_Instance( handle, &id );

    BSP_MAGNETO_IsInitialized( handle, &status );

    if ( status == 1 )
    {
        if ( BSP_MAGNETO_Get_Axes( handle, &magnetic_field ) == COMPONENT_ERROR )
        {
          magnetic_field.AXIS_X = 0;
          magnetic_field.AXIS_Y = 0;
          magnetic_field.AXIS_Z = 0;
        }

        a_PtrCmpsData->meas[0] = (float)magnetic_field.AXIS_X;
        a_PtrCmpsData->meas[1] = (float)magnetic_field.AXIS_Y;
        a_PtrCmpsData->meas[2] = (float)magnetic_field.AXIS_Z;

        //sprintf( dataOut, "\nMAG_X[%d]: %d, MAG_Y[%d]: %d, MAG_Z[%d]: %d\n", (int)id, (int)magnetic_field.AXIS_X, (int)id, (int)magnetic_field.AXIS_Y, (int)id, (int)magnetic_field.AXIS_Z );
    }
}




