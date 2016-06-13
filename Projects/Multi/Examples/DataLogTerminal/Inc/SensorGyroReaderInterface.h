/**
  ******************************************************************************
  * File Name          : SensorGyroReaderInterface.h
  * Description        : Header File for the Sensor Gyro Reader Interface
  ******************************************************************************
  *
  * COPYRIGHT(c) 2016 Vimal Mehta
  *
  ******************************************************************************
  */

#ifndef SENSOR_GYRO_READER_PUBLIC_INTERFACE_H
#define SENSOR_GYRO_READER_PUBLIC_INTERFACE_H

/* Public Includes -----------------------------------------------------------*/

#include "GeneralTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Private Includes ----------------------------------------------------------*/


/* Literal Constants ---------------------------------------------------------*/

/* Types ---------------------------------------------------------------------*/

/* Procedures ----------------------------------------------------------------*/

void SensorGyroReaderPowerUp
    ( void );

void SensorGyroReaderInit
    ( void );

void SensorGyroReaderPowerDown
    ( void );

#ifdef __cplusplus
}
#endif

#endif // SENSOR_GYRO_READER_PUBLIC_INTERFACE_H
