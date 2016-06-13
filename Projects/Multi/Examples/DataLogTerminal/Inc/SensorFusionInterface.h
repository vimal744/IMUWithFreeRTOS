/**
  ******************************************************************************
  * File Name          : SensorFusionInterface.h
  * Description        : Header File for the Sensor Fusion Interface
  ******************************************************************************
  *
  * COPYRIGHT(c) 2016 Vimal Mehta
  *
  ******************************************************************************
  */

#ifndef SENSOR_FUSION_PUBLIC_INTERFACE_H
#define SENSOR_FUSION_PUBLIC_INTERFACE_H

/* Public Includes -----------------------------------------------------------*/

#include "GeneralTypes.h"

#include "GyroTypes.h"
#include "AccelTypes.h"
#include "CompassTypes.h"

/* Private Includes ----------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif

/* Literal Constants ---------------------------------------------------------*/

/* Types ---------------------------------------------------------------------*/

/* Quaternion Data Tyoe*/

typedef struct
    {
    uint32_t TimeStamp;
    float    MeasurementX;
    float    MeasurementY;
    float    MeasurementZ;
    float    MeasurementW;
    } SensorQuaternionDataType;

/* Procedures ----------------------------------------------------------------*/

void SensorFusionPowerUp
    ( void );

void SensorFusionInit
    ( void );

void SensorFusionPowerDown
    ( void );

void SensorFusionGetQuaternionData
    (
    const SensorQuaternionDataType* a_PtrData
    );

void SensorFusionSetQuaternionData
    (
    const SensorQuaternionDataType* const a_PtrData
    );


boolean SensorFusionAddGyroData
    (
    const GyroDataType* const a_PtrGyroData
    );

boolean SensorFusionAddAccelData
    (
    const AccelDataType* const a_PtrAccelData
    );

boolean SensorFusionAddCompassData
    (
    const CompassDataType* const a_PtrCmpsData
    );

#ifdef __cplusplus
}
#endif

#endif // SENSOR_FUSION_PUBLIC_INTERFACE_H
