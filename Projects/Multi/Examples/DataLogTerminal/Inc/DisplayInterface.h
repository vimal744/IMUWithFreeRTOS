/**
  ******************************************************************************
  * File Name          : DisplayInterface.h
  * Description        : Header File for the Sensor Application Interface
  ******************************************************************************
  *
  * COPYRIGHT(c) 2016 Vimal Mehta
  *
  ******************************************************************************
  */

#ifndef DISPLAY_INTERFACE_H
#define DISPLAY_INTERFACE_H

/* Public Includes -----------------------------------------------------------*/

#include "GeneralTypes.h"


#ifdef __cplusplus
extern "C" {
#endif

void DisplayPowerUp
    ( void );

void DisplayInit
    ( void );

void DisplayPowerDown
    ( void );

void DisplayDrawPixel( int16_t x, int16_t y, uint16_t color );

void DisplayFillRectange( int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color );

void DisplayDrawVerticalLine( int16_t x, int16_t y, int16_t h, uint16_t color );

void DisplayDrawHorizontalLine( int16_t x, int16_t y, int16_t w, uint16_t color );



#ifdef __cplusplus
}
#endif



#endif // DISPLAY_INTERFACE_H
