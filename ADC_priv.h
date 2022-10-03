/************************************************/
/* Title       : ADC Private file               */
/* Author      : Yahia Ahmed                    */
/* Release     : 1.0                            */
/* Last Update : Aug 20, 2021                   */
/************************************************/

#ifndef ADC_PRIV_H_
#define ADC_PRIV_H_

#define ADMUX (*( (volatile u8 *)0x27) )
#define ADCSRA (*( (volatile u8 *)0x26) )
#define SFIOR (*( (volatile u8 *)0x50) )
#define ADCL (*( (volatile u8 *)0x24) )
#define ADCH (*( (volatile u8 *)0x25) )

/*reference options*/

#define ADC_AVCC       0
#define ADC_Internal   3
#define ADC_Aref       7



/*Prescaler*/

#define ADC_Prescaler_2     0
#define ADC_Prescaler_4		5
#define ADC_Prescaler_8		7
#define ADC_Prescaler_16	10
#define ADC_Prescaler_32	12
#define ADC_Prescaler_64	15
#define ADC_Prescaler_128	17

/*ADC_Mode*/
#define Eight_Bit_Mode   8
#define Ten_Bit_Mode   15


#endif



