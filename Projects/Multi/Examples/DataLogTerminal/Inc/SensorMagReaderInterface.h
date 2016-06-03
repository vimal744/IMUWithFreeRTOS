/**
  ******************************************************************************
  * File Name          : SensorMagReaderInterface.h
  * Description        : Header File for the Sensor Mag Reader Interface
  ******************************************************************************
  *
  * COPYRIGHT(c) 2016 Vimal Mehta
  *
  ******************************************************************************
  */

#ifndef SENSOR_MAG_READER_PUBLIC_INTERFACE_H
#define SENSOR_MAG_READER_PUBLIC_INTERFACE_H

/* Public Includes -----------------------------------------------------------*/

#include "GeneralTypes.h"

/* Private Includes ----------------------------------------------------------*/


/* Literal Constants ---------------------------------------------------------*/

/* Types ---------------------------------------------------------------------*/

/* Procedures ----------------------------------------------------------------*/

void SensorMagReaderPowerUp
    ( void );

void SensorMagReaderInit
    ( void );

void SensorMagReaderPowerDown
    ( void );

#endif // SENSOR_MAG_READER_PUBLIC_INTERFACE_H
