/**
  * File Name          : GraphicsInterface.h
  * Refernce:  https://github.com/adafruit/Adafruit-GFX-Library
  */

#ifndef GRAPHICS_INTERFACE_H
#define GRAPHICS_INTERFACE_H

/* Public Includes -----------------------------------------------------------*/

#include "GeneralTypes.h"
#include <stddef.h>
#include <stdint.h>
#include <string.h>

class Graphics
{

 public:

  Graphics(int16_t w, int16_t h); // Constructor

  // These MAY be overridden by the subclass to provide device-specific
  // optimized code.  Otherwise 'generic' versions are used.
  virtual void DrawPixel(int16_t x0, int16_t y0, uint16_t color);
  virtual void DrawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);
  virtual void drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color);
  virtual void drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color);
  virtual void DrawRectangle(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
  virtual void FillRectangle(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
  virtual void FillScreen(uint16_t color);
  virtual void InvertDisplay(boolean i);

  virtual void DrawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
  virtual void DrawCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, uint16_t color);
  virtual void FillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
  virtual void FillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, int16_t delta, uint16_t color);

  virtual void DrawRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, uint16_t color);
  virtual void FillRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, uint16_t color);

  // These exist only with Graphics (no subclass overrides)

  virtual void DrawChar(int16_t x, int16_t y, unsigned char c, uint16_t color,  uint16_t bg, uint8_t size);
  virtual void SetCursor(int16_t x, int16_t y);
  virtual void SetTextColor(uint16_t c);
  virtual void SetTextColor(uint16_t c, uint16_t bg);
  virtual void SetTextSize(uint8_t s);
  virtual void SetTextWrap(boolean w);
  virtual void SetRotation(uint8_t r);
  virtual void cp437(boolean x=true);

  virtual void   Write(uint8_t);

  int16_t Height(void) const;
  int16_t Width(void) const;

  uint8_t GetRotation(void) const;

  // get current cursor position (get rotation safe maximum values, using: width() for x, height() for y)
  int16_t GetCursorX(void) const;
  int16_t GetCursorY(void) const;

  void swap( int16_t a, int16_t b );
  int PrintFormattedString( char *buf, int size, char *format, ...);
  void PrintString( const char *buf, int size );

 protected:
  const int16_t
    WIDTH, HEIGHT;   // This is the 'raw' display w/h - never changes
  int16_t
    _width, _height, // Display w/h as modified by current rotation
    cursor_x, cursor_y;
  uint16_t
    textcolor, textbgcolor;
  uint8_t
    textsize,
    rotation;
  boolean
    wrap,   // If set, 'wrap' text at right edge of display
    _cp437; // If set, use correct CP437 charset (default is off)
};

#endif // GRAPHICS_INTERFACE_H
