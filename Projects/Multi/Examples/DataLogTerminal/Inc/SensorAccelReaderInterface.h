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

#endif // SENSOR_READER_PUBLIC_INTERFACE_H
