/************************************************/
/* Title       : LCD Interface file             */
/* Author      : Diaa ElDeen Mohamed            */
/* Release     : 1.0                            */
/* Last Update : Sep 9, 2021                   */
/************************************************/

#ifndef LCD_INT_H_
#define LCD_INT_H_


void LCD_vidInit(void);

void LCD_vidWriteCharacter(u8 Copy_u8data);

void LCD_vidWriteCommand(u8 Copy_u8cmd);

void LCD_vidWriteString(u8 * Copy_pString);

void LCD_vidGoToRowCol(u8 Copy_u8Row , u8 Copy_u8Col );

void LCD_vidClearScreen();

#endif 
