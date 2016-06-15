/**
  * File Name          : UserInterface.h
  * Refernce:  https://github.com/adafruit/Adafruit-GFX-Library
  */


#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include "GeneralTypes.h"
#include "GraphicsInterface.h"

class UI_Button
{

 public:
  UI_Button(void);
  void InitButton(Graphics *gfx, int16_t x, int16_t y,
              uint8_t w, uint8_t h,
              uint16_t outline, uint16_t fill, uint16_t textcolor,
              char *label, uint8_t textsize);
  void DrawButton(boolean inverted = false);

  void UpdateText
    (
    char*   label,
    boolean inverted = false
    );


  boolean Contains(int16_t x, int16_t y);

  void Press(boolean p);
  boolean IsPressed();
  boolean JustPressed();
  boolean JustReleased();

 private:
  Graphics *_gfx;
  int16_t _x, _y;
  uint16_t _w, _h;
  uint8_t _textsize;
  uint16_t _outlinecolor, _fillcolor, _textcolor;
  char _label[10];

  boolean currstate, laststate;

};

class UI_Label
{

 public:
  UI_Label(void);
  void InitLabel(Graphics *gfx, int16_t x, int16_t y,
              uint8_t w, uint8_t h,
              uint16_t outline, uint16_t fill, uint16_t textcolor,
              char *label, uint8_t textsize);

  void DrawLabel(boolean inverted = false);

  void UpdateText
    (
    char*   label,
    boolean inverted = false
    );

 private:
  Graphics *_gfx;
  int16_t _x, _y;
  uint16_t _w, _h;
  uint8_t _textsize;
  uint16_t _outlinecolor, _fillcolor, _textcolor;
  char _label[15];

  boolean currstate, laststate;

};

#endif // USER_INTERFACE_H
