/*
 * TMR0_Config.h
 *
 *  Created on: Oct 27, 2023
 *      Author: Hazim Emad
 */

#ifndef MCAL_TMR0_HEADER_TMR0_CONFIG_H_
#define MCAL_TMR0_HEADER_TMR0_CONFIG_H_

/********************************************************
 *Choose Timer Mode
 *Options :
 *            1- TIMER0_Normal for normal mode
 *			  2- TIMER0_CTC    for compare on match mode
 *			  3- TIMER0_PWM    for pwm mode
 *  		  4- TIMER0_DELAY  for delay mode
 *  		  5- TIMER0_Counter
 ********************************************************/
#define TIMER0_Mode TIMER0_PWM
#define TIMER0_COM_ACTION	TIMER0_TOGGLE
#endif /* MCAL_TMR0_HEADER_TMR0_CONFIG_H_ */
