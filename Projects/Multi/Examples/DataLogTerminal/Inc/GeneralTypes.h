/**
  ******************************************************************************
  * File Name          : GeneralTypes.h
  * Description        : Header File for the General Types
  ******************************************************************************
  *
  * COPYRIGHT(c) 2016 Vimal Mehta
  *
  ******************************************************************************
  */

#ifndef GENERAL_TYPES_H
#define GENERAL_TYPES_H

/* Public Includes -----------------------------------------------------------*/

#include <stdint.h>

/* Private Includes ----------------------------------------------------------*/


/* Literal Constants ---------------------------------------------------------*/

#define TRUE    1
#define FALSE   0

#define min_val( a,b ) ( ( (a) < (b) ) ? ( a ) : ( b ) )

/* Types ---------------------------------------------------------------------*/

typedef uint8_t boolean;

/* Procedures ----------------------------------------------------------------*/

#endif // GENERAL_TYPES_H
