/************************************************/
/* Title       : LCD Program file               */
/* Author      : Diaa ElDeen Mohamed            */
/* Release     : 1.0                            */
/* Last Update : Sep 9, 2021                   */
/************************************************/
#include "STD_Types.h"
#include "BIT_MATH.h"
#include <util/delay.h>

#include "DIO_int.h"
#include "LCD_int.h"
#include "LCD_config.h"
#include "LCD_priv.h"

void LCD_vidInit(void)
{
	_delay_ms(30);
	LCD_vidWriteCommand(0b00111000); // 4 lines and 5×7 matrix
	_delay_ms(1);
	LCD_vidWriteCommand(0b00001110); // Display on, cursor blinking
	_delay_ms(1);
	LCD_vidWriteCommand(0b00000001); // clear screen
	_delay_ms(2);
	LCD_vidWriteCommand(0b00000110); // Increment cursor (shift cursor to right)


}

void LCD_vidWriteCharacter(u8 Copy_u8data)
{
	DIO_vid_SetPinValue( LCD_u8_PIN_RS ,  DIO_u8_HIGH); // RS high for data 
	LCD_SvidExecute(Copy_u8data);

}

void LCD_vidWriteCommand(u8 Copy_u8cmd)
{
	DIO_vid_SetPinValue( LCD_u8_PIN_RS ,  DIO_u8_LOW); // RS low for commands 
	LCD_SvidExecute(Copy_u8cmd);
}

void LCD_vidWriteString(u8 * Copy_pString)
{
	u8 Local_u8Index = 0 ;
	while(Copy_pString[Local_u8Index]  != '\0' )
	{
		LCD_vidWriteCharacter(Copy_pString[Local_u8Index]);
		Local_u8Index++ ;
	}

}

void LCD_vidGoToRowCol(u8 Copy_u8Row , u8 Copy_u8Col )
{
	u8 Local_u8Address ;
	switch(Copy_u8Row)
	{
	case 0 :
		Local_u8Address = 0x00 + Copy_u8Col ; // first row address
		break ;
	case 1 :
		Local_u8Address = 0x40 + Copy_u8Col ; // second row address
		break ;
	case 2 :
		Local_u8Address = 0x10 + Copy_u8Col ; // third row address
		break ;
	case 3 :
		Local_u8Address = 0x50 + Copy_u8Col ; // fourth row address
		break ;
	
	}
	LCD_vidWriteCommand(0x80|Local_u8Address ); // DDRAM address

}

void LCD_vidClearScreen()
{
	LCD_vidWriteCommand(0b00000001);

}

static void LCD_SvidExecute(u8 Copy_u8DataCmd)
{

	DIO_vid_SetPinValue( LCD_u8_PIN_RW ,  DIO_u8_LOW ); // means write
	_delay_ms(1);
	DIO_vid_SetPinValue( LCD_u8_PIN_E ,  DIO_u8_HIGH);
	_delay_ms(1);

	/*PIN0*/
	if( GET_BIT(Copy_u8DataCmd , 0)  )
	{
		DIO_vid_SetPinValue( LCD_u8_PIN_D0 ,  DIO_u8_HIGH);
	}
	else
	{
		DIO_vid_SetPinValue( LCD_u8_PIN_D0 ,  DIO_u8_LOW);
	}
	/*PIN1*/
	if( GET_BIT(Copy_u8DataCmd , 1) )
	{
		DIO_vid_SetPinValue( LCD_u8_PIN_D1 ,  DIO_u8_HIGH);
	}
	else
	{
		DIO_vid_SetPinValue( LCD_u8_PIN_D1 ,  DIO_u8_LOW);
	}
	/*PIN2*/
	if( GET_BIT(Copy_u8DataCmd , 2) )
	{
		DIO_vid_SetPinValue( LCD_u8_PIN_D2 ,  DIO_u8_HIGH);
	}
	else
	{
		DIO_vid_SetPinValue( LCD_u8_PIN_D2 ,  DIO_u8_LOW);
	}
	/*PIN3*/
	if( GET_BIT(Copy_u8DataCmd , 3) )
	{
		DIO_vid_SetPinValue( LCD_u8_PIN_D3 ,  DIO_u8_HIGH);
	}
	else
	{
		DIO_vid_SetPinValue( LCD_u8_PIN_D3 ,  DIO_u8_LOW);
	}
	/*PIN4*/
	if( GET_BIT(Copy_u8DataCmd , 4) )
	{
		DIO_vid_SetPinValue( LCD_u8_PIN_D4 ,  DIO_u8_HIGH);
	}
	else
	{
		DIO_vid_SetPinValue( LCD_u8_PIN_D4 ,  DIO_u8_LOW);
	}
	/*PIN5*/
	if( GET_BIT(Copy_u8DataCmd , 5) )
	{
		DIO_vid_SetPinValue( LCD_u8_PIN_D5 ,  DIO_u8_HIGH);
	}
	else
	{
		DIO_vid_SetPinValue( LCD_u8_PIN_D5 ,  DIO_u8_LOW);
	}
	/*PIN6*/
	if( GET_BIT(Copy_u8DataCmd , 6) )
	{
		DIO_vid_SetPinValue( LCD_u8_PIN_D6 ,  DIO_u8_HIGH);
	}
	else
	{
		DIO_vid_SetPinValue( LCD_u8_PIN_D6 ,  DIO_u8_LOW);
	}
	/*PIN7*/
	if( GET_BIT(Copy_u8DataCmd , 7) )
	{
		DIO_vid_SetPinValue( LCD_u8_PIN_D7 ,  DIO_u8_HIGH);
	}
	else
	{
		DIO_vid_SetPinValue( LCD_u8_PIN_D7 ,  DIO_u8_LOW);
	}


	_delay_ms(1);
	DIO_vid_SetPinValue( LCD_u8_PIN_E ,  DIO_u8_LOW);
	_delay_ms(1);


}
