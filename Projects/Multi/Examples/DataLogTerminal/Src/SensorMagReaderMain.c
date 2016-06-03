/**
  ******************************************************************************
  * File Name          : SensorMagReaderMain.h
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
#include "SensorMagReaderInterface.h"
#include "SensorFusionInterface.h"

#include "x_nucleo_iks01a1.h"
#include "x_nucleo_iks01a1_magneto.h"

#include "CompassTypes.h"
#include "PrintUtility.h"

#include "FreeRTOS.h"
#include "task.h"

/* Private Includes ----------------------------------------------------------*/


/* Literal Constants ---------------------------------------------------------*/

/* Stack size for the sensor reader thread */
#define SNSR_MAG_READER_MAIN_STK_SZ      ( 256 )

/* Printf statement for debugging */
#define SensorMagReader_Debug_Printf( _args ) //Printf _args

/* Memory Constants ----------------------------------------------------------*/

static const char* c_ThreadName = "SensorMagReader_Main";

/* Global Variables ----------------------------------------------------------*/

static TaskHandle_t     s_SensorMagReader_Main_Handle;
static void*            LIS3MDL_0_handle = NULL;

/* Procedures ----------------------------------------------------------------*/

static void initMag( void );
static void enableMag( void );
static void disableMag( void );
static void Mag_Sensor_Handler( CompassDataType* a_PtrCmpsData, void *handle );
static void MainSensorMagReader( void* a_Ptr );

/**
* @brief Power up the sensor Reader thread
*/

void SensorMagReaderPowerUp
    ( void )
{
    initMag();
    xTaskCreate( MainSensorMagReader, c_ThreadName, SNSR_MAG_READER_MAIN_STK_SZ, NULL, SENSOR_MAG_READER_TASK_PRI, &s_SensorMagReader_Main_Handle );
}

/**
* @brief Init the sensor reader thread
*/

void SensorMagReaderInit
    ( void )
{
    enableMag();
}

/**
* @brief Power down the sensor reader thread
*/

void SensorMagReaderPowerDown
    ( void )
{
    disableMag();

    if( s_SensorMagReader_Main_Handle != NULL )
    {
        vTaskDelete( s_SensorMagReader_Main_Handle );
    }
}


/**
* @brief Main for the sensor Reader thread
*
* NOTE: Currently simulating the data because I could not get the sensor board to work
*
*/

static void MainSensorMagReader
    (
    void* a_Ptr
    )
{
    CompassDataType cmpsData;

    for(;;)
    {
        // Populate Compass Data
    	Mag_Sensor_Handler( &cmpsData, LIS3MDL_0_handle );
    	SensorMagReader_Debug_Printf(("SR: Tx Cmps x=%f, y=%f, z=%f\r\n", cmpsData.meas[0], cmpsData.meas[1], cmpsData.meas[2] ));
        SensorFusionAddCompassData( &cmpsData );
        osDelay(1000);
    }
}

/**
 * @brief  Initialize all sensors
 * @param  None
 * @retval None
 */
static void initMag( void )
{
    BSP_MAGNETO_Init( LIS3MDL_0, &LIS3MDL_0_handle );
}

/**
 * @brief  Enable all sensors
 * @param  None
 * @retval None
 */
static void enableMag( void )
{
    BSP_MAGNETO_Sensor_Enable( LIS3MDL_0_handle );
}

/**
 * @brief  Disable all sensors
 * @param  None
 * @retval None
 */
static void disableMag( void )
{
    BSP_MAGNETO_Sensor_Disable( LIS3MDL_0_handle );
}

/**
 * @brief  Handles the magneto axes data getting/sending
 * @param  handle the device handle
 * @retval None
 */
static void Mag_Sensor_Handler
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

