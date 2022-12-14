// set pin 
// clear pin
// set port
// clear port
// activate pull up resistor 
// get pin 
// get port 
// configure direction 
// set / clear / get nipple

/************************************************/
/* Title       : DIO peripheral interface file  */
/* Author      : Yahia Ahmed                    */
/* Release     : 1.0                            */
/* Last Update : Aug 15, 2021                   */
/************************************************/

#ifndef DIO_INT_H_
#define DIO_INT_H_

#define DIO_u8_PIN_0         0 
#define DIO_u8_PIN_1         1 
#define DIO_u8_PIN_2         2 
#define DIO_u8_PIN_3         3 
#define DIO_u8_PIN_4         4 
#define DIO_u8_PIN_5         5 
#define DIO_u8_PIN_6         6 
#define DIO_u8_PIN_7         7 

#define DIO_u8_PIN_8         8 
#define DIO_u8_PIN_9         9 
#define DIO_u8_PIN_10        10
#define DIO_u8_PIN_11        11
#define DIO_u8_PIN_12        12
#define DIO_u8_PIN_13        13
#define DIO_u8_PIN_14        14
#define DIO_u8_PIN_15        15

#define DIO_u8_PIN_16        16
#define DIO_u8_PIN_17        17
#define DIO_u8_PIN_18        18
#define DIO_u8_PIN_19        19
#define DIO_u8_PIN_20        20
#define DIO_u8_PIN_21        21
#define DIO_u8_PIN_22        22
#define DIO_u8_PIN_23        23

#define DIO_u8_PIN_24        24
#define DIO_u8_PIN_25        25
#define DIO_u8_PIN_26        26
#define DIO_u8_PIN_27        27
#define DIO_u8_PIN_28        28
#define DIO_u8_PIN_29        29
#define DIO_u8_PIN_30        30
#define DIO_u8_PIN_31        31

/*************************		PORTA		*****************/
#define DIO_u8_PORTA_PIN_0  				0
#define DIO_u8_PORTA_PIN_1             		1
#define DIO_u8_PORTA_PIN_2              	2
#define DIO_u8_PORTA_PIN_3              	3
#define DIO_u8_PORTA_PIN_4                	4
#define DIO_u8_PORTA_PIN_5               	5
#define DIO_u8_PORTA_PIN_6               	6
#define DIO_u8_PORTA_PIN_7               	7
/*************************		PORTB		*****************/
#define DIO_u8_PORTB_PIN_0  				8
#define DIO_u8_PORTB_PIN_1             		9
#define DIO_u8_PORTB_PIN_2              	10
#define DIO_u8_PORTB_PIN_3              	11
#define DIO_u8_PORTB_PIN_4                	12
#define DIO_u8_PORTB_PIN_5               	13
#define DIO_u8_PORTB_PIN_6               	14
#define DIO_u8_PORTB_PIN_7               	15
/*************************		PORTC		*****************/
#define DIO_u8_PORTC_PIN_0  				16
#define DIO_u8_PORTC_PIN_1             		17
#define DIO_u8_PORTC_PIN_2              	18
#define DIO_u8_PORTC_PIN_3              	19
#define DIO_u8_PORTC_PIN_4                	20
#define DIO_u8_PORTC_PIN_5               	21
#define DIO_u8_PORTC_PIN_6               	22
#define DIO_u8_PORTC_PIN_7               	23
/*************************		PORTD		*****************/
#define DIO_u8_PORTD_PIN_0  				24
#define DIO_u8_PORTD_PIN_1             		25
#define DIO_u8_PORTD_PIN_2              	26
#define DIO_u8_PORTD_PIN_3              	27
#define DIO_u8_PORTD_PIN_4                	28
#define DIO_u8_PORTD_PIN_5               	29
#define DIO_u8_PORTD_PIN_6               	30
#define DIO_u8_PORTD_PIN_7               	31

#define DIO_u8_HIGH          1
#define DIO_u8_LOW           0


#define DIO_u8_PORTA 		 0
#define DIO_u8_PORTB 		 1
#define DIO_u8_PORTC  		 2
#define DIO_u8_PORTD   		 3

void DIO_vid_Init(void);
void DIO_vid_SetPinValue(u8 Copy_u8_PinNo , u8 Copy_u8_PinValue);
u8   DIO_u8_GetPinValue(u8 Copy_u8_PinNo);
void DIO_vid_ActivatePullUpResistor(u8 Copy_u8_PinNo);
void DIO_vid_ClearPin(u8 Copy_u8_PinNo );
void DIO_vid_SetPORTValue(u8 Copy_u8_PORTN0  ,u8 Copy_u8_PORTValue );
u8	 DIO_u8_GetPORT( u8 Copy_u8_PORTN0 );


#endif
