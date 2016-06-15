/**
  ******************************************************************************
  * File Name          : ThreadPriorities.h
  * Description        : Header File for the General Types
  ******************************************************************************
  *
  * COPYRIGHT(c) 2016 Vimal Mehta
  *
  ******************************************************************************
  */

#ifndef THREAD_PRIORITIES_H
#define THREAD_PRIORITIES_H

/* Public Includes -----------------------------------------------------------*/

/* Private Includes ----------------------------------------------------------*/


/* Literal Constants ---------------------------------------------------------*/

/* Types ---------------------------------------------------------------------*/

#define SENSOR_FUSION_TASK_PRI          ( 4 )
#define SENSOR_ACCL_READER_TASK_PRI     ( 3 )
#define SENSOR_GYRO_READER_TASK_PRI     ( 3 )
#define SENSOR_MAG_READER_TASK_PRI      ( 3 )
#define SENSOR_APPLICATION_TASK_PRI     ( 5 )

/* Procedures ----------------------------------------------------------------*/

#endif // THREAD_PRIORITIES_H
