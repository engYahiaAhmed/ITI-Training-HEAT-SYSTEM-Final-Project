/************************************************/
/* Title       : DIO peripheral program file    */
/* Author      : Yahia Ahmed                    */
/* Release     : 1.0                            */
/* Last Update : Aug 15, 2021                   */
/************************************************/
#include "STD_types.h"
#include "BIT_math.h"
#include "DIO_int.h"
#include "DIO_priv.h"
#include"DIO_config.h"




void DIO_vid_Init(void)
{
	DDRA = DIO_u8_PORTA_DIRECTION;
	DDRB = DIO_u8_PORTB_DIRECTION;
	DDRC = DIO_u8_PORTC_DIRECTION;
	DDRD = DIO_u8_PORTD_DIRECTION;
}
/*********************************Set Pin Value To PORTX***************************************/
void DIO_vid_SetPinValue(u8 Copy_u8_PinNo , u8 Copy_u8_PinValue)
{
	/*********************************SetPinValue FOR PORTA***************************************/
	if( (Copy_u8_PinNo >= DIO_u8_PORTA_START) && (Copy_u8_PinNo <= DIO_u8_PORTA_END) )
	{
		if(Copy_u8_PinValue == DIO_u8_HIGH )
		{
			SET_BIT(PORTA,Copy_u8_PinNo);
		}
		else if( Copy_u8_PinValue == DIO_u8_LOW )
		{
			CLEAR_BIT(PORTA,Copy_u8_PinNo);
		}
	}
	/*********************************SetPinValue FOR PORTB***************************************/
	if( (Copy_u8_PinNo >= DIO_u8_PORTB_START) && (Copy_u8_PinNo <= DIO_u8_PORTB_END) )
	{
		if(Copy_u8_PinValue == DIO_u8_HIGH)
		{
			SET_BIT(PORTB,Copy_u8_PinNo);
		}
		else if(Copy_u8_PinValue == DIO_u8_LOW )
		{
			CLEAR_BIT(PORTB,Copy_u8_PinNo);
		}
	}
	/*********************************SetPinValue FOR PORTC***************************************/
	if( (Copy_u8_PinNo >= DIO_u8_PORTC_START) && (Copy_u8_PinNo <= DIO_u8_PORTC_END) )
	{
		if(Copy_u8_PinValue == DIO_u8_HIGH)
		{
			SET_BIT(PORTC,Copy_u8_PinNo);
		}
		else if(Copy_u8_PinValue == DIO_u8_LOW )
		{
			CLEAR_BIT(PORTC,Copy_u8_PinNo);
		}
	}
	/*********************************SetPinValue FOR PORTD***************************************/
	if( (Copy_u8_PinNo >= DIO_u8_PORTD_START) && (Copy_u8_PinNo <= DIO_u8_PORTD_END) )
	{
		if(Copy_u8_PinValue == DIO_u8_HIGH)
		{
			SET_BIT(PORTD,Copy_u8_PinNo);
		}
		else if(Copy_u8_PinValue == DIO_u8_LOW )
		{
			CLEAR_BIT(PORTD,Copy_u8_PinNo);
		}
	}
}
/*********************************GetPinValue From PIN Register***************************************/
u8 DIO_u8_GetPinValue(u8 Copy_u8_PinNo)
{
	u8 Local_u8_Returnval;

	/*********************************GrtPinValue From PINA***************************************/
	if( (Copy_u8_PinNo >= DIO_u8_PORTA_START) && (Copy_u8_PinNo <= DIO_u8_PORTA_END) )
	{
	
		Local_u8_Returnval= (GET_BIT(PINA,Copy_u8_PinNo) == DIO_u8_HIGH ) ? DIO_u8_HIGH : DIO_u8_LOW ;
		
	}
	/*********************************GetPinValue From PINB***************************************/
	if( (Copy_u8_PinNo >= DIO_u8_PORTB_START) && (Copy_u8_PinNo <= DIO_u8_PORTB_END) )
	{
		
		Local_u8_Returnval=(GET_BIT(PINB,Copy_u8_PinNo) == DIO_u8_HIGH ) ? DIO_u8_HIGH : DIO_u8_LOW ;
		
	}
	/*********************************GrtPinValue From PINC***************************************/
	if( (Copy_u8_PinNo >= DIO_u8_PORTC_START) && (Copy_u8_PinNo <= DIO_u8_PORTC_END) )
	{
		Local_u8_Returnval= ( GET_BIT(PINC,Copy_u8_PinNo) == DIO_u8_HIGH ) ? DIO_u8_HIGH : DIO_u8_LOW ;
	}
	/*********************************GrtPinValue From PIND***************************************/
	if( (Copy_u8_PinNo >= DIO_u8_PORTD_START) && (Copy_u8_PinNo <= DIO_u8_PORTD_END) )
	{
		
		Local_u8_Returnval= (GET_BIT(PIND,Copy_u8_PinNo) == DIO_u8_HIGH ) ? DIO_u8_HIGH : DIO_u8_LOW ;
	}
	return Local_u8_Returnval;
}
/*******************************************Activate Pull Up Resistor*****************************/
void DIO_vid_ActivatePullUpResistor( u8 Copy_u8_PinNo)
{
	DIO_vid_SetPinValue( Copy_u8_PinNo , DIO_u8_HIGH);
}
/*******************************************Clear PinX***********************************************/
void DIO_vid_ClearPin(u8 Copy_u8_PinNo )
{
	DIO_vid_SetPinValue(Copy_u8_PinNo ,DIO_u8_LOW);
}
/*******************************************Set PORT*****************************/
void DIO_vid_SetPORTValue(u8 Copy_u8_PORTN0  ,u8 Copy_u8_PORTValue )
{
	switch(Copy_u8_PORTN0)
	{
		case DIO_u8_PORTA:
			SET_PORT(PORTA , Copy_u8_PORTValue);	break;
		case DIO_u8_PORTB:
			SET_PORT(PORTB , Copy_u8_PORTValue);	break;
		case DIO_u8_PORTC:
			SET_PORT(PORTC , Copy_u8_PORTValue);	break;
		case DIO_u8_PORTD:
			SET_PORT(PORTD , Copy_u8_PORTValue);	break;
		default:
			break;
	}

}
/*******************************************Get PORT*****************************/
u8 DIO_u8_GetPORT( u8 Copy_u8_PORTN0 )
{
	u8 Local_u8_ReturnPort;
	switch(Copy_u8_PORTN0)
	{
		case DIO_u8_PORTA:
			 Local_u8_ReturnPort= PORTA ;	break;
		case DIO_u8_PORTB:
			 Local_u8_ReturnPort= PORTB ;	break;
		case DIO_u8_PORTC:
			 Local_u8_ReturnPort= PORTC ;	break;
		case DIO_u8_PORTD:
			 Local_u8_ReturnPort= PORTD ;	break;
		default:
			break;
	}
	 return Local_u8_ReturnPort;
}

