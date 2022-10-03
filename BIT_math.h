/************************************************/
/* Title       : DIO peripheral BIT MATH file   */
/* Author      : Yahia Ahmed                    */
/* Release     : 1.0                            */
/* Last Update : Aug 15, 2021                   */
/************************************************/
 
#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(Var,BitNo)    Var = ( Var | (1 << (BitNo%8)) )

#define CLEAR_BIT(Var,BitNo)  Var = (Var & ~(1 << (BitNo%8))) 

#define SET_PORT(Var , Value)  Var=Value
#define GET_BIT(Var,BitNo) (Var & (1 <<(BitNo%8))) 
#define CONC_BIT(A7,A6,A5,A4,A3,A2,A1,A0)	CONC_HELP(A7,A6,A5,A4,A3,A2,A1,A0)
#define CONC_HELP(A7,A6,A5,A4,A3,A2,A1,A0)  0b##A7##A6##A5##A4##A3##A2##A1##A0
  
#endif
