/**
 ******************************************************************************
 * @file    ILI9341_Driver.c
 */

/* Includes ------------------------------------------------------------------*/
#include "ILI9341_Driver.h"

#ifdef  USE_FULL_ASSERT_ILI9341
#include <stdio.h>
#endif

#define DELAY 0x80
#define MAX_WIDTH   240
#define MAX_HEIGHT  320

static  uint8_t spiBuffer[ILI9341_SPIBUFLEN];
static  uint8_t iSpiBuffer; /* current SPI buffer empty ascending point */

extern uint8_t Display_IO_Write( void *handle, uint8_t *pBuffer, uint16_t nBytesToWrite );
extern uint8_t Display_IO_Enable_Command( void *handle );
extern uint8_t Display_IO_Enable_Data( void *handle );
extern void Display_IO_Delay( uint32_t val );

static void Flush( void *handle );
static void WriteByte( void *handle, uint8_t c );
static void WriteCommand( void *handle, uint8_t c );
static void WriteData( void *handle, uint8_t c );

/**
* @brief  De initialization function for ILI9341.
*         This function put the ILI9341 in power down, make a memory boot and clear the data output flags.
* @param  *handle Device handle.
* @retval Error code [ILI9341_OK, ILI9341_ERROR].
*/
ILI9341_Error_et ILI9341_DeInit(void *handle)
{
    iSpiBuffer = 0;
    return ILI9341_ERROR;
}

/**
* @brief  Exit from power down mode.
* @param  *handle Device handle.
* @param  void.
* @retval Error code [ILI9341_OK, ILI9341_ERROR].
*/
ILI9341_Error_et ILI9341_Activate(void *handle)
{
    iSpiBuffer = 0;

    WriteCommand( handle, 0x01);
    Display_IO_Delay(10);


    WriteCommand( handle, ILI9341_PWCTR1);    //Power control
    WriteData( handle, 0x23);   //VRH[5:0]

    WriteCommand( handle, ILI9341_PWCTR2);    //Power control
    WriteData( handle, 0x10);   //SAP[2:0];BT[3:0]

    WriteCommand( handle, ILI9341_VMCTR1);    //VCM control
    WriteData( handle, 0x3e); //对比度调节
    WriteData( handle, 0x28);

    WriteCommand( handle, ILI9341_VMCTR2);    //VCM control2
    WriteData( handle, 0x86);  //--

    WriteCommand( handle, ILI9341_MADCTL);    // Memory Access Control
    WriteData( handle, 0x48);

    WriteCommand( handle, ILI9341_PIXFMT);
    WriteData( handle, 0x55);

    WriteCommand( handle, ILI9341_FRMCTR1);
    WriteData( handle, 0x00);
    WriteData( handle, 0x18);

    WriteCommand( handle, ILI9341_DFUNCTR);    // Display Function Control
    WriteData( handle, 0x08);
    WriteData( handle, 0x82);
    WriteData( handle, 0x27);

    WriteCommand( handle, 0xF2);    // 3Gamma Function Disable
    WriteData( handle, 0x00);

    WriteCommand( handle, ILI9341_GAMMASET);    //Gamma curve selected
    WriteData( handle, 0x01);

    WriteCommand( handle, ILI9341_GMCTRP1);    //Set Gamma
    WriteData( handle, 0x0F);
    WriteData( handle, 0x31);
    WriteData( handle, 0x2B);
    WriteData( handle, 0x0C);
    WriteData( handle, 0x0E);
    WriteData( handle, 0x08);
    WriteData( handle, 0x4E);
    WriteData( handle, 0xF1);
    WriteData( handle, 0x37);
    WriteData( handle, 0x07);
    WriteData( handle, 0x10);
    WriteData( handle, 0x03);
    WriteData( handle, 0x0E);
    WriteData( handle, 0x09);
    WriteData( handle, 0x00);

    WriteCommand( handle, ILI9341_GMCTRN1);    //Set Gamma
    WriteData( handle, 0x00);
    WriteData( handle, 0x0E);
    WriteData( handle, 0x14);
    WriteData( handle, 0x03);
    WriteData( handle, 0x11);
    WriteData( handle, 0x07);
    WriteData( handle, 0x31);
    WriteData( handle, 0xC1);
    WriteData( handle, 0x48);
    WriteData( handle, 0x08);
    WriteData( handle, 0x0F);
    WriteData( handle, 0x0C);
    WriteData( handle, 0x31);
    WriteData( handle, 0x36);
    WriteData( handle, 0x0F);

    WriteCommand( handle, ILI9341_SLPOUT);    //Exit Sleep
    Display_IO_Delay(120);
    WriteCommand( handle, ILI9341_DISPON);    //Display on

    return ILI9341_OK;
}

/**
* @brief  Put the sensor in power down mode.
* @param  *handle Device handle.
* @retval Error code [ILI9341_OK, ILI9341_ERROR].
*/
ILI9341_Error_et ILI9341_DeActivate(void *handle)
{
  return ILI9341_OK;
}

ILI9341_Error_et ILI9341_SetAddressWindow(void *handle, uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1)
{
    WriteCommand( handle,ILI9341_CASET); // Column addr set
    WriteData(handle,x0 >> 8);
    WriteData(handle,x0 & 0xFF);     // XSTART
    WriteData(handle,x1 >> 8);
    WriteData(handle,x1 & 0xFF);     // XEND

    WriteCommand( handle,ILI9341_PASET); // Row addr set
    WriteData(handle,y0>>8);
    WriteData(handle,y0);     // YSTART
    WriteData(handle,y1>>8);
    WriteData(handle,y1);     // YEND

    WriteCommand( handle,ILI9341_RAMWR); // write to RAM

    return ILI9341_OK;
}

ILI9341_Error_et ILI9341_PushColor(void *handle, uint16_t color)
{
    WriteData(handle,color >> 8);
    WriteData(handle,color);
    return ILI9341_OK;
}

// fill a rectangle
ILI9341_Error_et ILI9341_FillScreen
    (
    void *handle,
    uint16_t color
    )
{
    return ILI9341_FillRect( handle, color, 0, 0, MAX_WIDTH - 1, MAX_HEIGHT - 1 );
}


// fill a rectangle
ILI9341_Error_et ILI9341_FillRect
    (
    void *handle,
    uint16_t color,
    int16_t x,
    int16_t y,
    int16_t w,
    int16_t h
    )
{

    // rudimentary clipping (drawChar w/big text requires this)
    if((x >= MAX_WIDTH) || (y >= MAX_HEIGHT))
    {
        return ILI9341_ERROR;
    }

    if((x + w - 1) >= MAX_WIDTH)
    {
        w = MAX_WIDTH - x;
    }

    if((y + h - 1) >= MAX_HEIGHT)
    {
        h = MAX_HEIGHT - y;
    }

    ILI9341_SetAddressWindow(handle,x, y, x+w-1, y+h-1);

    uint8_t hi = color >> 8;
    uint8_t lo = color;

    for(y=h; y>0; y--)
    {
        for(x=w; x>0; x--)
        {
            WriteData(handle,hi);
            WriteData(handle,lo);
        }
    }

    return ILI9341_OK;
}

#ifdef  USE_FULL_ASSERT_ILI9341
/**
* @brief  Reports the name of the source file and the source line number
*         where the assert_param error has occurred.
* @param file: pointer to the source file name
* @param line: assert_param error line source number
* @retval : None
*/
void ILI9341_assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number */
  printf("Wrong parameters value: file %s on line %d\r\n", file, (int)line);

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

static void Flush( void *handle )
{
    Display_IO_Write( handle, spiBuffer, iSpiBuffer );
    iSpiBuffer = 0;
}


// Write the given byte to the SPI buffer.
static void WriteByte( void *handle, uint8_t c )
{
    spiBuffer[iSpiBuffer++] = c;
    if (iSpiBuffer >= ILI9341_SPIBUFLEN)
    {
        Flush( handle );
    }
}

static void WriteCommand( void *handle, uint8_t c )
{
    Flush( handle );

    Display_IO_Enable_Command( handle );

    WriteByte( handle, c );

    Flush( handle );
}

// Set DC high means sending data, CS low
// write the given byte
// Set CS high to deselect TFT chip
static void WriteData( void *handle, uint8_t c )
{
    Display_IO_Enable_Data( handle );
    WriteByte( handle, c );
}

