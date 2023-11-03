/*
 * TMR2_Register.h
 *
 *  Created on: Oct 27, 2023
 *      Author: Hazim Emad
 */

#ifndef MCAL_TMR2_HEADER_TMR2_REGISTER_H_
#define MCAL_TMR2_HEADER_TMR2_REGISTER_H_

#define TCCR2         *((volatile u8*)0x45)          /*Timer2 control register*/
#define TCCR2_WGM20   6                              /*Waveform generation Mode bit0*/
#define TCCR2_WGM21   3                              /*Waveform generation Mode bit1*/
#define TCCR2_CS22    2                              /*Prescalar bit2*/
#define TCCR2_CS21    1                              /*Prescalar bit1*/
#define TCCR2_CS20    0                              /*Prescalar bit0*/
#define TCCR2_COM20   4                              /*COMPARE OUTPUT MODE BIT0*/
#define TCCR2_COM21   5                              /*COMPARE OUTPUT MODE BIT1*/

#define OCR2          *((volatile u8*)0x43)          /*Output Compare register 2*/

#define TIMSK         *((volatile u8*)0X59)          /*Timer mask*/
#define TIMSK_OCIE         1                         /*Output Compare 2 interrupt enable*/
#define TIMSK_TOIE2         6                         /*OVERFLOW 2 interrupt enable*/
#define TIFR		  *((volatile u8*)0x58)
#define TIFR_OCF2	  1

#define TCNT2         *((volatile u8*)0x44)

#endif /* MCAL_TMR2_HEADER_TMR2_REGISTER_H_ */
