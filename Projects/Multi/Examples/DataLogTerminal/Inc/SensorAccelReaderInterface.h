/**
  ******************************************************************************
  * File Name          : SensorAccelReaderInterface.h
  * Description        : Header File for the Sensor Accel Reader Interface
  ******************************************************************************
  *
  * COPYRIGHT(c) 2016 Vimal Mehta
  *
  ******************************************************************************
  */

#ifndef SENSOR_ACCEL_READER_PUBLIC_INTERFACE_H
#define SENSOR_ACCEL_READER_PUBLIC_INTERFACE_H

/* Public Includes -----------------------------------------------------------*/

#include "GeneralTypes.h"
#include "AccelTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Private Includes ----------------------------------------------------------*/


/* Literal Constants ---------------------------------------------------------*/

/* Types ---------------------------------------------------------------------*/

/* Procedures ----------------------------------------------------------------*/

void SensorAccelReaderPowerUp
    ( void );

void SensorAccelReaderInit
    ( void );

void SensorAccelReaderPowerDown
    ( void );

void SensorAccelGetAccelData
    (
    AccelDataType* a_PtrAccelData
    );

#ifdef __cplusplus
}
#endif

#endif // SENSOR_READER_PUBLIC_INTERFACE_H
