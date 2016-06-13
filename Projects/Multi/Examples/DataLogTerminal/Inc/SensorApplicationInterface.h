/**
  ******************************************************************************
  * File Name          : SensorApplicationInterface.h
  * Description        : Header File for the Sensor Application Interface
  ******************************************************************************
  *
  * COPYRIGHT(c) 2016 Vimal Mehta
  *
  ******************************************************************************
  */

#ifndef SENSOR_APPLICATION_PUBLIC_INTERFACE_H
#define SENSOR_APPLICATION_PUBLIC_INTERFACE_H

/* Public Includes -----------------------------------------------------------*/

#include "GeneralTypes.h"

/* Private Includes ----------------------------------------------------------*/


/* Literal Constants ---------------------------------------------------------*/

/* Types ---------------------------------------------------------------------*/

/* Procedures ----------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

void SensorApplicationPowerUp
    ( void );

void SensorApplicationInit
    ( void );

void SensorApplicationPowerDown
    ( void );

#ifdef __cplusplus
}
#endif

#endif // SENSOR_APPLICATION_PUBLIC_INTERFACE_H
