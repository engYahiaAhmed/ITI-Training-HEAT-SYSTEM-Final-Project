/************************************************/
/* Title       : ADC Configuration file         */
/* Author      : Yahia Ahmed                    */
/* Release     : 1.0                            */
/* Last Update : Aug 20, 2021                   */
/************************************************/

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/* reference mode */
/*
//5v
#define ADC_AVCC       0
#define ADC_Internal   3
//external
#define ADC_Aref       7
*/
#define ADC_Mode_Voltage   ADC_Aref


/* ADC Prescaler

#define ADC_Prescaler_2     0
#define ADC_Prescaler_4		5
#define ADC_Prescaler_8		7
#define ADC_Prescaler_16	10
#define ADC_Prescaler_32	12
#define ADC_Prescaler_64	15
#define ADC_Prescaler_128	17

*/

#define ADC_Prescaler_Option  ADC_Prescaler_16

/*ADC Bit Mode*/
/*
#define Eight_Bit_Mode   8
#define Ten_Bit_Mode   15
*/

#define ADC_Mode  Ten_Bit_Mode






#endif
