/**
  * File Name          : UserInterface.cpp
  * Refernce:  https://github.com/adafruit/Adafruit-GFX-Library
  */

/* Public Includes -----------------------------------------------------------*/
#include "GeneralTypes.h"
#include "UserInterface.h"
#include <string.h>

/***************************************************************************/
// code for the GFX button UI element

#define BUTTONBUFSIZE 16
char buttonBuf[BUTTONBUFSIZE];


UI_Button::UI_Button(void)
{
   _gfx = 0;
}

void UI_Button::InitButton(Graphics *gfx,
                      int16_t x, int16_t y,
                      uint8_t w, uint8_t h,
                      uint16_t outline, uint16_t fill,
                      uint16_t textcolor,
                      char *label, uint8_t textsize)
{
  _x = x;
  _y = y;
  _w = w;
  _h = h;
  _outlinecolor = outline;
  _fillcolor = fill;
  _textcolor = textcolor;
  _textsize = textsize;
  _gfx = gfx;
  strncpy(_label, label, 9);
  _label[9] = 0;
}



void UI_Button::DrawButton(boolean inverted) {
   uint16_t fill, outline, text;

   if (! inverted) {
     fill = _fillcolor;
     outline = _outlinecolor;
     text = _textcolor;
   } else {
     fill =  _textcolor;
     outline = _outlinecolor;
     text = _fillcolor;
   }

   _gfx->FillRoundRect(_x - (_w/2), _y - (_h/2), _w, _h, min_val(_w,_h)/4, fill);
   _gfx->DrawRoundRect(_x - (_w/2), _y - (_h/2), _w, _h, min_val(_w,_h)/4, outline);


   _gfx->SetCursor(_x - strlen(_label)*3*_textsize, _y-4*_textsize);
   _gfx->SetTextColor(text);
   _gfx->SetTextSize(_textsize);

   _gfx->PrintFormattedString(buttonBuf, BUTTONBUFSIZE, "%s", _label);

 }

 void UI_Button::UpdateText
    (
    char*   label,
    boolean inverted
    )
{
    if( 0 != strncmp(_label, label, 9) )
    {
        uint16_t fill, outline, text;

        if (! inverted)
        {
            fill = _fillcolor;
            outline = _outlinecolor;
            text = _textcolor;
        }
        else
        {
            fill =  _textcolor;
            outline = _outlinecolor;
            text = _fillcolor;
        }

        _gfx->FillRoundRect(_x - (_w/2), _y - (_h/2), _w, _h, min_val(_w,_h)/4, fill);
        _gfx->DrawRoundRect(_x - (_w/2), _y - (_h/2), _w, _h, min_val(_w,_h)/4, outline);

        strncpy(_label, label, 9);

        _gfx->SetCursor(_x - strlen(_label)*3*_textsize, _y-4*_textsize);
        _gfx->SetTextColor(text);
        _gfx->SetTextSize(_textsize);

        _gfx->PrintFormattedString(buttonBuf, BUTTONBUFSIZE, "%s", _label);
    }

   //while(1); // Need to implement print
 }

boolean UI_Button::Contains(int16_t x, int16_t y) {
   if ((x < (_x - _w/2)) || (x > (_x + _w/2))) return false;
   if ((y < (_y - _h/2)) || (y > (_y + _h/2))) return false;
   return true;
 }


 void UI_Button::Press(boolean p) {
   laststate = currstate;
   currstate = p;
 }

 boolean UI_Button::IsPressed() { return currstate; }
 boolean UI_Button::JustPressed() { return (currstate && !laststate); }
 boolean UI_Button::JustReleased() { return (!currstate && laststate); }


UI_Label::UI_Label(void)
{
   _gfx = 0;
}

void UI_Label::InitLabel(Graphics *gfx,
                      int16_t x, int16_t y,
                      uint8_t w, uint8_t h,
                      uint16_t outline, uint16_t fill,
                      uint16_t textcolor,
                      char *label, uint8_t textsize)
{
  _x = x;
  _y = y;
  _w = w;
  _h = h;
  _outlinecolor = outline;
  _fillcolor = fill;
  _textcolor = textcolor;
  _textsize = textsize;
  _gfx = gfx;
  strncpy(_label, label, 14);
  _label[14] = 0;
}



void UI_Label::DrawLabel(boolean inverted) {
   uint16_t fill, outline, text;

   if (! inverted) {
     fill = _fillcolor;
     outline = _outlinecolor;
     text = _textcolor;
   } else {
     fill =  _textcolor;
     outline = _outlinecolor;
     text = _fillcolor;
   }

   _gfx->FillRoundRect(_x - (_w/2), _y - (_h/2), _w, _h, min_val(_w,_h)/4, fill);
   _gfx->DrawRoundRect(_x - (_w/2), _y - (_h/2), _w, _h, min_val(_w,_h)/4, outline);


   _gfx->SetCursor(_x - strlen(_label)*3*_textsize, _y-4*_textsize);
   _gfx->SetTextColor(text);
   _gfx->SetTextSize(_textsize);

   _gfx->PrintFormattedString(buttonBuf, BUTTONBUFSIZE, "%s", _label);

 }

 void UI_Label::UpdateText
    (
    char*   label,
    boolean inverted
    )
{
    if( 0 != strncmp(_label, label, 9) )
    {
        uint16_t fill, outline, text;

        if (! inverted)
        {
            fill = _fillcolor;
            outline = _outlinecolor;
            text = _textcolor;
        }
        else
        {
            fill =  _textcolor;
            outline = _outlinecolor;
            text = _fillcolor;
        }

        _gfx->FillRectangle(_x - strlen(_label)*3*_textsize , _y-4*_textsize, _x + _w , _h + _y , 0x0000 );

        //_gfx->FillRoundRect(_x - (_w/2), _y - (_h/2), _w, _h, min_val(_w,_h)/4, fill);
        //_gfx->DrawRoundRect(_x - (_w/2), _y - (_h/2), _w, _h, min_val(_w,_h)/4, outline);

        strncpy(_label, label, 9);

        _gfx->SetCursor(_x - strlen(_label)*3*_textsize, _y-4*_textsize);
        _gfx->SetTextColor(text);
        _gfx->SetTextSize(_textsize);

        _gfx->PrintFormattedString(buttonBuf, BUTTONBUFSIZE, "%s", _label);
    }

   //while(1); // Need to implement print
 }

