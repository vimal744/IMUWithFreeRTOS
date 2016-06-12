/* Includes ------------------------------------------------------------------*/

#include "adafruit_display.h"
#include "cmsis_os.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

static SPI_HandleTypeDef SPI1_Handle;

/**
 * @}
 */

/* Link function for sensor peripheral */
uint8_t Display_IO_Write( void *handle, uint8_t *pBuffer, uint16_t nBytesToWrite );
uint8_t Display_IO_Enable_Command( void *handle );
uint8_t Display_IO_Enable_Data( void *handle );
void Display_IO_Delay( uint32_t val );


static DrvContextTypeDef    Display_Handle;
static DISPLAY_Data_t       Display_Data;
static ILI9341_Data_t       ILI9341_0_Data;


static DrvStatusTypeDef BSP_ILI9341_DISPLAY_Init( void **handle );
static void SPI1_MspInit( void );
static void SPI1_Error( uint8_t Addr );
static uint8_t SPI1_Init( void );

void Display_IO_Delay( uint32_t val )
{
    osDelay( val );
}


DrvStatusTypeDef BSP_DISPLAY_Init( DISPLAY_ID_t id, void **handle )
{
   *handle = NULL;

    if( BSP_ILI9341_DISPLAY_Init(handle)  == COMPONENT_ERROR )
    {
        return COMPONENT_ERROR;
    }

    return COMPONENT_OK;
}

static DrvStatusTypeDef BSP_ILI9341_DISPLAY_Init( void **handle )
{
    DISPLAY_Drv_t *driver = NULL;

    if( Display_Handle.isInitialized )
    {
        return COMPONENT_ERROR;
    }

    if ( Display_IO_Init() == COMPONENT_ERROR )
    {
        return COMPONENT_ERROR;
    }

    /* Setup sensor handle. */
    Display_Handle.who_am_i         = 0;
    Display_Handle.address          = 0;
    Display_Handle.instance         = ILI9341_0;
    Display_Handle.isInitialized    = 0;
    Display_Handle.isEnabled        = 0;
    Display_Handle.isCombo          = 0;
    Display_Handle.pData            = ( void * )&Display_Data;
    Display_Handle.pVTable          = ( void * )&ILI9341_D_Drv;
    Display_Handle.pExtVTable       = 0;

    Display_Data.pComponentData   = ( void * )&ILI9341_0_Data;
    Display_Data.pExtData         = 0;

    *handle = (void *)&Display_Handle;

    driver = ( DISPLAY_Drv_t * )((DrvContextTypeDef *)(*handle))->pVTable;

    if( driver->Init == NULL )
    {
        memset((*handle), 0, sizeof(DrvContextTypeDef));
        *handle = NULL;
        return COMPONENT_ERROR;
    }

    if( driver->Init( (DrvContextTypeDef *)(*handle) ) == COMPONENT_ERROR )
    {
        memset((*handle), 0, sizeof(DrvContextTypeDef));
        *handle = NULL;
        return COMPONENT_ERROR;
    }

    return COMPONENT_OK;
}


DrvStatusTypeDef BSP_DISPLAY_DeInit( void **handle )
{

    DrvContextTypeDef *ctx = (DrvContextTypeDef *)(*handle);
    DISPLAY_Drv_t *driver = NULL;

    if(ctx == NULL)
    {
        return COMPONENT_ERROR;
    }

    driver = ( DISPLAY_Drv_t * )ctx->pVTable;

    if( driver->DeInit == NULL )
    {
        return COMPONENT_ERROR;
    }

    if( driver->DeInit( ctx ) == COMPONENT_ERROR )
    {
        return COMPONENT_ERROR;
    }

    memset(ctx, 0, sizeof(DrvContextTypeDef));

    *handle = NULL;

    return COMPONENT_OK;

}

DrvStatusTypeDef BSP_DISPLAY_Enable( void *handle )
{

    DrvContextTypeDef *ctx = (DrvContextTypeDef *)handle;
    DISPLAY_Drv_t *driver = NULL;

    if(ctx == NULL)
    {
        return COMPONENT_ERROR;
    }

    driver = ( DISPLAY_Drv_t * )ctx->pVTable;

    if ( driver->Display_Enable == NULL )
    {
        return COMPONENT_ERROR;
    }

    if ( driver->Display_Enable( ctx ) == COMPONENT_ERROR )
    {
        return COMPONENT_ERROR;
    }

    if ( driver->Display_FillRect( ctx , 0x0000, 0, 0, 240, 320, 240, 320 ) == COMPONENT_ERROR )
    {
      return COMPONENT_ERROR;
    }

    return COMPONENT_OK;

}

DrvStatusTypeDef BSP_DISPLAY_Fill_Screen( void *handle, uint16_t a_Color )
{
    DrvContextTypeDef *ctx = (DrvContextTypeDef *)handle;
    DISPLAY_Drv_t *driver = NULL;

    if(ctx == NULL)
    {
        return COMPONENT_ERROR;
    }

    driver = ( DISPLAY_Drv_t * )ctx->pVTable;

    if ( driver->Display_FillScrn( ctx , a_Color ) == COMPONENT_ERROR )
    {
      return COMPONENT_ERROR;
    }

    return COMPONENT_OK;
}

DrvStatusTypeDef BSP_DISPLAY_Write_Char( void *handle, unsigned char a_Char )
{
    DrvContextTypeDef *ctx = (DrvContextTypeDef *)handle;
    DISPLAY_Drv_t *driver = NULL;

    if(ctx == NULL)
    {
        return COMPONENT_ERROR;
    }

    driver = ( DISPLAY_Drv_t * )ctx->pVTable;

    if ( driver->Display_Write_Char( ctx , a_Char ) == COMPONENT_ERROR )
    {
      return COMPONENT_ERROR;
    }

    return COMPONENT_OK;
}

DrvStatusTypeDef BSP_DISPLAY_Printf( void *handle, char *buf, int size, char *format, ...)
{
    va_list args;
    int len;
    va_start(args, format);
    len = vsnprintf(buf, size, format, args);
    va_end(args);

    return BSP_DISPLAY_Write_String( handle, buf, len );
}

DrvStatusTypeDef BSP_DISPLAY_Write_String( void *handle, char* a_PtrString, uint8_t size )
{
    DrvContextTypeDef *ctx = (DrvContextTypeDef *)handle;
    DISPLAY_Drv_t *driver = NULL;
    uint8_t i;

    if(ctx == NULL)
    {
        return COMPONENT_ERROR;
    }

    driver = ( DISPLAY_Drv_t * )ctx->pVTable;

    for( i = 0; i < size; i++ )
    {
        if ( driver->Display_Write_Char( ctx , a_PtrString[i] ) == COMPONENT_ERROR )
        {
          return COMPONENT_ERROR;
        }
    }

    return COMPONENT_OK;
}


DrvStatusTypeDef BSP_DISPLAY_Set_Cursor( void *handle, uint16_t a_X, uint16_t a_Y )
{
    DrvContextTypeDef *ctx = (DrvContextTypeDef *)handle;
    DISPLAY_Drv_t *driver = NULL;

    if(ctx == NULL)
    {
        return COMPONENT_ERROR;
    }

    driver = ( DISPLAY_Drv_t * )ctx->pVTable;

    if ( driver->Display_Set_Cursor( ctx , a_X, a_Y ) == COMPONENT_ERROR )
    {
      return COMPONENT_ERROR;
    }

    return COMPONENT_OK;
}

DrvStatusTypeDef BSP_DISPLAY_Set_Text_Color( void *handle, uint16_t a_FC, uint16_t a_BC )
{
    DrvContextTypeDef *ctx = (DrvContextTypeDef *)handle;
    DISPLAY_Drv_t *driver = NULL;

    if(ctx == NULL)
    {
        return COMPONENT_ERROR;
    }

    driver = ( DISPLAY_Drv_t * )ctx->pVTable;

    if ( driver->Display_Set_Text_Color( ctx , a_FC, a_BC ) == COMPONENT_ERROR )
    {
      return COMPONENT_ERROR;
    }

    return COMPONENT_OK;
}



DrvStatusTypeDef BSP_DISPLAY_Disable( void *handle )
{

  DrvContextTypeDef *ctx = (DrvContextTypeDef *)handle;
  DISPLAY_Drv_t *driver = NULL;

  if(ctx == NULL)
  {
    return COMPONENT_ERROR;
  }

  driver = ( DISPLAY_Drv_t * )ctx->pVTable;

  if ( driver->Display_Disable == NULL )
  {
    return COMPONENT_ERROR;
  }

  if ( driver->Display_Disable( ctx ) == COMPONENT_ERROR )
  {
    return COMPONENT_ERROR;
  }

  return COMPONENT_OK;
}

DrvStatusTypeDef Display_IO_Init( void )
{

  if ( SPI1_Init() )
  {
    return COMPONENT_ERROR;
  }
  else
  {
    return COMPONENT_OK;
  }
}

/******************************* Link functions *******************************/

uint8_t Display_IO_Write( void *handle, uint8_t *pBuffer, uint16_t nBytesToWrite )
{
    uint8_t val = 0;

    HAL_GPIO_WritePin( GPIOB, GPIO_PIN_6, GPIO_PIN_RESET );

    if( HAL_OK == HAL_SPI_Transmit( &SPI1_Handle, pBuffer, nBytesToWrite, 1000 ) )
    {
        val = 1;
    }

    HAL_GPIO_WritePin( GPIOB, GPIO_PIN_6, GPIO_PIN_SET   );

    return val;
}

uint8_t Display_IO_Enable_Command( void *handle )
{
    HAL_GPIO_WritePin( GPIOC, GPIO_PIN_7, GPIO_PIN_RESET );
    return 1;
}

uint8_t Display_IO_Enable_Data( void *handle )
{
    HAL_GPIO_WritePin( GPIOC, GPIO_PIN_7, GPIO_PIN_SET   );
    return 1;
}

/******************************* SPI1 Routines *********************************/

/**
 * @brief  Configures SPI1 interface.
 * @param  None
 * @retval 0 in case of success
 * @retval 1 in case of failure
 */
static uint8_t SPI1_Init( void )
{
    if( HAL_SPI_STATE_RESET == HAL_SPI_GetState( &SPI1_Handle) )
    {
        /* SPI Config */
        SPI1_Handle.Instance = NUCLEO_SPI1;

        SPI1_Handle.Init.Direction          = SPI_DIRECTION_2LINES;
        SPI1_Handle.Init.Mode               = SPI_MODE_MASTER;
        SPI1_Handle.Init.NSS                = SPI_NSS_SOFT;

        SPI1_Handle.Init.DataSize           = SPI_DATASIZE_8BIT;
        SPI1_Handle.Init.FirstBit           = SPI_FIRSTBIT_MSB;
        SPI1_Handle.Init.CLKPolarity        = SPI_POLARITY_LOW;
        SPI1_Handle.Init.CLKPhase           = SPI_PHASE_1EDGE;
        SPI1_Handle.Init.BaudRatePrescaler  = SPI_BAUDRATEPRESCALER_32;

        SPI1_Handle.Init.CRCCalculation     = SPI_CRCCALCULATION_DISABLED;
        SPI1_Handle.Init.CRCPolynomial      = 7;
        SPI1_Handle.Init.TIMode             = SPI_TIMODE_DISABLED;

        SPI1_MspInit();

        HAL_SPI_Init(&SPI1_Handle);

    }

    if( HAL_SPI_GetState( &SPI1_Handle ) == HAL_SPI_STATE_READY )
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

/**
 * @brief  Manages error callback by re-initializing SPI1
 * @param  Addr SPI1 Address
 * @retval None
 */
static void SPI1_Error( uint8_t Addr )
{

  /* De-initialize the SPI1 comunication bus */
  HAL_SPI_DeInit( &SPI1_Handle );

  /* Re-Initiaize the SPI1 comunication bus */
  SPI1_Init();
}



/**
 * @brief SPI1 MSP Initialization
 * @param None
 * @retval None
 */

static void SPI1_MspInit( void )
{
    GPIO_InitTypeDef  GPIO_InitStruct;

    /*-------- Configure CS ChipSelect Pin PB6 --------*/

    NUCLEO_SPI1_CS_GPIO_CLK_ENABLE();
    GPIO_InitStruct.Pin         = NUCLEO_SPI1_CS_PIN;
    GPIO_InitStruct.Mode        = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull        = GPIO_PULLUP;
    GPIO_InitStruct.Speed       = GPIO_SPEED_FAST;
    HAL_GPIO_Init( GPIOB, &GPIO_InitStruct );


    /*-------- Configure DC Data/Command Pin PC7 --------*/

    NUCLEO_SPI1_DC_GPIO_CLK_ENABLE();
    GPIO_InitStruct.Pin         = NUCLEO_SPI1_DC_PIN;
    GPIO_InitStruct.Mode        = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull        = GPIO_PULLUP;
    GPIO_InitStruct.Speed       = GPIO_SPEED_FAST;
    HAL_GPIO_Init( GPIOC, &GPIO_InitStruct );


    /*** Configure the GPIOs ***/

    /* Enable GPIO clock */
    NUCLEO_SPI1_SCK_GPIO_CLK_ENABLE();
    NUCLEO_SPI1_MISO_MOSI_GPIO_CLK_ENABLE();

    /* Configure SPI SCK */
    GPIO_InitStruct.Pin         = NUCLEO_SPI1_SCK_PIN;
    GPIO_InitStruct.Mode        = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull        = GPIO_NOPULL;
    GPIO_InitStruct.Speed       = GPIO_SPEED_HIGH;
    GPIO_InitStruct.Alternate   = NUCLEO_SPI1_SCK_AF;
    HAL_GPIO_Init( NUCLEO_SPI1_SCK_GPIO_PORT, &GPIO_InitStruct );

    /* Configure SPI MISO and MOSI */
    GPIO_InitStruct.Pin         = NUCLEO_SPI1_MOSI_PIN;
    GPIO_InitStruct.Alternate   = NUCLEO_SPI1_MISO_MOSI_AF;

    HAL_GPIO_Init( NUCLEO_SPI1_MISO_MOSI_GPIO_PORT, &GPIO_InitStruct );

    GPIO_InitStruct.Pin         = NUCLEO_SPI1_MISO_PIN;
    GPIO_InitStruct.Alternate   = NUCLEO_SPI1_MISO_MOSI_AF;

    HAL_GPIO_Init( NUCLEO_SPI1_MISO_MOSI_GPIO_PORT, &GPIO_InitStruct );

    /*** Configure the SPI peripheral ***/
    /* Enable SPI clock */
    NUCLEO_SPI1_CLK_ENABLE();
}

/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

