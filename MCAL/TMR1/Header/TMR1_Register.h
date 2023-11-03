/*
 * TMR1_Register.h
 *
 *  Created on: Oct 27, 2023
 *      Author: Hazim Emad
 */

#ifndef MCAL_TMR1_HEADER_TMR1_REGISTER_H_
#define MCAL_TMR1_HEADER_TMR1_REGISTER_H_

#define OCR0 *((volatile u8*)0x5C)
#define OCR1A *((volatile u16*)0x4A)
#define OCR1B *((volatile u16*)0x48)

#define TCCR1A *((volatile u8*)0x4F)
#define TCCR1A_COM1A1 7
#define TCCR1A_COM1A0 6
#define TCCR1A_WGM11 1
#define TCCR1A_WGM10 0
#define TCCR1A_COM1B1 5
#define TCCR1A_COM1B0 4
#define TCCR1A_FOC1A 3
#define TCCR1A_FOC1B 2

#define TCCR1B *((volatile u8*)0x4E)
#define TCCR1B_WGM13 4
#define TCCR1B_WGM12 3
#define TCCR1B_CS12 2
#define TCCR1B_CS11 1
#define TCCR1B_CS10 0
#define TCCR1B_ICNC1 7
#define TCCR1B_ICES 6


#define TCCR0 *((volatile u8*)0x53)
#define TCCR0_WGM00 6
#define TCCR0_WGM01 3
#define TCCR0_COM00 4
#define TCCR0_COM01 5
#define TCCR0_CS00 0
#define TCCR0_CS01 1
#define TCCR0_CS02 2

#define ICR1 *((volatile u16*)0x46)

#define TIMSK         *((volatile u8*)0x59)          /*Timer mask*/
#define TIMSK_OCIE         1                         /*Output Compare 0 interrupt enable*/
#define TIMSK_TOIE         0
#define TIMSK_TICIE1	   5

#define TCNT1         *((volatile u16*)0x4C)

#endif /* MCAL_TMR1_HEADER_TMR1_REGISTER_H_ */
