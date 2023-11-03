/*
 * TMR0_Register.h
 *
 *  Created on: Oct 27, 2023
 *      Author: Hazim Emad
 */

#ifndef MCAL_TMR0_HEADER_TMR0_REGISTER_H_
#define MCAL_TMR0_HEADER_TMR0_REGISTER_H_

#define TCCR0         *((volatile u8*)0x53)          /*Timer0 control register*/
#define TCCR0_WGM00   6                              /*Waveform generation Mode bit0*/
#define TCCR0_WGM01   3                              /*Waveform generation Mode bit1*/
#define TCCR0_CS02    2                              /*Prescalar bit2*/
#define TCCR0_CS01    1                              /*Prescalar bit1*/
#define TCCR0_CS00    0                              /*Prescalar bit0*/
#define TCCR0_COM00   4                              /*COMPARE OUTPUT MODE BIT0*/
#define TCCR0_COM01   5                              /*COMPARE OUTPUT MODE BIT1*/

#define OCR0          *((volatile u8*)0x5C)          /*Output Compare register 0*/

#define TIMSK         *((volatile u8*)0X59)          /*Timer mask*/
#define TIMSK_OCIE         1                         /*Output Compare 0 interrupt enable*/
#define TIMSK_TOIE         0                         /*OVERFLOW 0 interrupt enable*/
#define TIFR		  *((volatile u8*)0x58)
#define TIFR_OCF0	  1

#define TCNT0         *((volatile u8*)0x52)
/*Define TIMER0 Mode options*/

#endif /* MCAL_TMR0_HEADER_TMR0_REGISTER_H_ */
