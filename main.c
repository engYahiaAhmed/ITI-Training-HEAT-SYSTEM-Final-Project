/*********************************************************************/
/* Title       : HEAT SYSTEM                                        */
/* Author      : Yahia Ahmed AND Diaa ElDeen Mohamed               */
/* Release     : 1.0                                              */
/* Last Update : Sep 9, 2021                                    */
/****************************************************************/

#include "STD_types.h"
#include "BIT_math.h"
#include "util/delay.h"
#include "DIO_int.h"
#include "LCD_int.h"
#include "ADC_int.h"
#include<stdlib.h>
#include<string.h>
void LCD_intgerToString(u16 data);
int main(void)
{
	u16  MyPointer ;//it's a varible that hold the ADC conversion value 
	u16 Analog ;   // it's a varible that hold the ADC Actual value
	DIO_vid_Init();
	ADC_voidInit();
	LCD_vidInit();
	_delay_ms(100);
	u16 last_val=0;
	while(1)
	{

		DIO_vid_SetPinValue(DIO_u8_PIN_13,0);
		ADC_u16GetConversionValue(0 , &MyPointer);
		 Analog = (u16) (   (u32)(  (u32)MyPointer * (u32)500) / (u16)1024 );//heat sensor equation

		 while(Analog>=40) //over heat warrning
			{
	 	 		DIO_vid_SetPinValue(DIO_u8_PIN_13,1);
		 		_delay_ms(10);
		 		LCD_vidWriteString("Warning OverHeat");
		 		LCD_vidGoToRowCol(1,0);
		 		DIO_vid_ClearPin(DIO_u8_PORTD_PIN_6);//System2 Pin
		 		DIO_vid_ClearPin(DIO_u8_PORTD_PIN_7);//System1 Pin

		 		ADC_u16GetConversionValue(0 , &MyPointer);
		 		 Analog = (u16) (   (u32)(  (u32)MyPointer * (u32)500) / (u16)1024 );
		 		 if(Analog !=last_val){
		 			
		 			 LCD_intgerToString( Analog );
		 			 last_val=Analog;
			 	 }
			}
		 	 DIO_vid_SetPinValue(DIO_u8_PIN_13,0);

		 if(Analog !=last_val){

			 LCD_intgerToString( Analog );
			 last_val=Analog;
		 	 }
			if(Analog>=40)
			{
				DIO_vid_SetPinValue(DIO_u8_PIN_13,1);
				_delay_ms(10);
			}

				DIO_vid_SetPinValue(DIO_u8_PIN_13,0);

			DIO_vid_SetPinValue(DIO_u8_PIN_13,0);
			if(Analog<20)
			{

				DIO_vid_ClearPin(DIO_u8_PIN_30);
				DIO_vid_SetPinValue(DIO_u8_PIN_31,1);

			}
			else if (Analog>25)
			{
				DIO_vid_ClearPin(DIO_u8_PIN_31);
				DIO_vid_SetPinValue(DIO_u8_PIN_30,1);
				_delay_ms(10);

			}
			else
			{
				DIO_vid_ClearPin(DIO_u8_PORTD_PIN_6);
				DIO_vid_ClearPin(DIO_u8_PORTD_PIN_7);
			}
			}

	return 0 ;

}
void LCD_intgerToString(u16 data)
{
	LCD_vidClearScreen();
	LCD_vidWriteString("temperature=");

   u8 buff[4]; /* String to hold the ascii result */
   itoa(data,buff,10); /* 10 for decimal */
 
   LCD_vidWriteString(buff);
   LCD_vidWriteString(" C");
   _delay_ms(20);
   if(data<20)
   {
	   _delay_ms(10);
	   LCD_vidGoToRowCol(2,5);
	   LCD_vidWriteString("System1 stable..");
	
   }
   else if(data>25 && data<40)
   {
	   _delay_ms(10);
	   LCD_vidGoToRowCol(2,5);
	   LCD_vidWriteString("System2 stable..");

   }
   else if(data>=20 && data<=25)
   {
	   _delay_ms(10);
	   LCD_vidGoToRowCol(2,5);
	   LCD_vidWriteString("Free System...");
 	 
   }

}
