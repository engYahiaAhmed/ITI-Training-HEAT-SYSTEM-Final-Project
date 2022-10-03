/************************************************/
/* Title       : ADC Interface file             */
/* Author      : Yahia Ahmed                    */
/* Release     : 1.0                            */
/* Last Update : Aug 20, 2021                   */
/************************************************/


#ifndef ADC_INT_H_
#define ADC_INT_H_

#define NOK 0
#define OK 1

void ADC_voidInit(void);

void ADC_voidEnableInt(void);

void ADC_voidDisableInt(void);

void ADC_voidSetCallBack( void (*Copy_Ptr) (void) );

void ADC_voidEnableADC(void);

void ADC_voidDisableADC(void);

#if ADC_Mode == Eight_Bit_Mode
u8 ADC_u8GetConversionValue(u8 Channel, u8 * Result);
u8 ADC_u8GetLastValue(void);

#else
u16 ADC_u16GetConversionValue(u8 Channel, u16 * Result);
u16 ADC_u16GetLastValue(void) ;

#endif





#endif
