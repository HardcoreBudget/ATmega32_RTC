/*
 * ADC_Register.h
 *
 *  Created on: Oct 23, 2023
 *      Author: Hazim Emad
 */

#ifndef MCAL_ADC_HEADER_ADC_REGISTER_H_
#define MCAL_ADC_HEADER_ADC_REGISTER_H_

#define ADMUX                *((volatile u8*)0x27)		/*ADC multilpexer selection register*/
#define ADMUX_REFS1			 7                           /*Reference selection Bit1*/
#define ADMUX_REFS0			 6                           /*Reference selection Bit0*/
#define ADMUX_ADLAR			 5                           /*Left adjust result*/

#define ADCSRA               *((volatile u8*)0x26)		/*ADC control and status registerA*/
#define ADCSRA_ADEN			 7                          /*Enable*/
#define ADCSRA_ADSC			 6                          /*Start conversion*/
#define ADCSRA_ADATE		 5                          /*Auto trigger enable*/
#define ADCSRA_ADIF			 4                          /*Interrupt flag*/
#define ADCSRA_ADIE			 3                          /*Interrupt enable*/
#define ADCSRA_ADPS2		 2                          /*PS2*/
#define ADCSRA_ADPS1		 1                         	/*PS1*/
#define ADCSRA_ADPS0		 0                          /*PS0*/


#define ADCH                 *((volatile u8*)0x25)		/*Data high register*/
#define ADCL                 *((volatile u8*)0x24)		/*Data low register*/
#define ADC					 *((volatile u16*)0x24)

#endif /* MCAL_ADC_HEADER_ADC_REGISTER_H_ */
