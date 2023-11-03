/*
 * ADC_Imp.c
 *
 *  Created on: Oct 23, 2023
 *      Author: Hazim Emad
 */
#include "../../../Library/STD_types.h"
#include "../../../Library/Bit_Math.h"
#include "../Header/ADC_Interface.h"

f32 Vref = 5;
void (*Global_ADC_CallBack)(void)= NULL;


void ADC_voidInit(){
#if VOLTAGE_REFERENCE == ADC_AVCC
	SET_BIT(ADMUX, ADMUX_REFS0);
	CLR_BIT(ADMUX, ADMUX_REFS1);
	Vref = 5;
#elif VOLTAGE_REFERENCE == ADC_AREF
	CLR_BIT(ADMUX, ADMUX_REFS0);
	CLR_BIT(ADMUX, ADMUX_REFS1);
	Vref = ADC_AREF_VALUE;

#elif VOLTAGE_REFERENCE == ADC_INTERNAL
	SET_BIT(ADMUX, ADMUX_REFS0);
	SET_BIT(ADMUX, ADMUX_REFS1);
	Vref = 2.56f;
#endif

#if ADJUSTMENT == LEFT_ADJUSTMENT
	SET_BIT(ADMUX, ADMUX_ADLAR);
#elif ADJUSTMENT == RIGHT_ADJUSTMENT
	CLR_BIT(ADMUX, ADMUX_ADLAR);
#endif

#if ADC_PRESCALLER == DIVISION_BY_128
	SET_BIT(ADCSRA, ADCSRA_ADPS0);
	SET_BIT(ADCSRA, ADCSRA_ADPS1);
	SET_BIT(ADCSRA, ADCSRA_ADPS2);
#elif ADC_PRESCALLER == DIVISION_BY_64
	CLR_BIT(ADCSRA, ADCSRA_ADPS0);
	SET_BIT(ADCSRA, ADCSRA_ADPS1);
	SET_BIT(ADCSRA, ADCSRA_ADPS2);
#elif ADC_PRESCALLER == DIVISION_BY_32
	SET_BIT(ADCSRA, ADCSRA_ADPS0);
	CLR_BIT(ADCSRA, ADCSRA_ADPS1);
	SET_BIT(ADCSRA, ADCSRA_ADPS2);
#elif ADC_PRESCALLER == DIVISION_BY_16
	CLR_BIT(ADCSRA, ADCSRA_ADPS0);
	CLR_BIT(ADCSRA, ADCSRA_ADPS1);
	SET_BIT(ADCSRA, ADCSRA_ADPS2);
#elif ADC_PRESCALLER == DIVISION_BY_8
	SET_BIT(ADCSRA, ADCSRA_ADPS0);
	SET_BIT(ADCSRA, ADCSRA_ADPS1);
	CLR_BIT(ADCSRA, ADCSRA_ADPS2);
#elif ADC_PRESCALLER == DIVISION_BY_4
	CLR_BIT(ADCSRA, ADCSRA_ADPS0);
	SET_BIT(ADCSRA, ADCSRA_ADPS1);
	CLR_BIT(ADCSRA, ADCSRA_ADPS2);
#elif ADC_PRESCALLER == DIVISION_BY_2
	SET_BIT(ADCSRA, ADCSRA_ADPS0);
	CLR_BIT(ADCSRA, ADCSRA_ADPS1);
	CLR_BIT(ADCSRA, ADCSRA_ADPS2);
#endif

#if ADC_AUTO_TRIGGER_SOURCE == FREE_RUNNING_MODE
	SET_BIT(ADCSRA, ADCSRA_ADATE);
#endif
}

void ADC_voidEnable(){
	SET_BIT(ADCSRA,ADCSRA_ADEN);
}

void ADC_voidInterrputEnable(){
	SET_BIT(ADCSRA,ADCSRA_ADIE);
}

void ADC_voidInterrputDisable(){
	CLR_BIT(ADCSRA,ADCSRA_ADIE);
}

void ADC_voidDisable(){
	CLR_BIT(ADCSRA,ADCSRA_ADEN);
}

u16 ADC_u16ReadADC(){
	u16 result = 0;
	result = (ADC * Vref)/1024;
	return result;
}

void ADC_voidStartConversion(u8 addresscpy){
	/*Clear first 5 bits in ADMUX register*/
	ADMUX &= 0b11100000;

	/*set required channel*/
	ADMUX |= addresscpy;
	/*Start conversion*/
	SET_BIT(ADCSRA,ADCSRA_ADSC);
	/*Busy waiting (polling) until the conversion is complete*/
	while((GET_BIT(ADCSRA,ADCSRA_ADIF))==0);

	/*clear the interrupt flag*/
	SET_BIT(ADCSRA,ADCSRA_ADIF);
}

void ADC_voidStartInterruptConversion(u8 addresscpy){
	/*Clear first 5 bits in ADMUX register*/
	ADMUX &= 0b11100000;
	/*set required channel*/
	ADMUX |= addresscpy;
	/*Start conversion*/
	SET_BIT(ADCSRA,ADCSRA_ADSC);
}

void ADC_voidChaining(u8 addresscpy){
	/*Clear first 5 bits in ADMUX register*/
	ADMUX &= 0b11100000;
	/*set required channel*/
	ADMUX |= addresscpy;
}

u16 ADC_u16ReadADCInMV(){
	u16 result = 0;
	result = (ADC * 1000UL * Vref)/1024;
	return result;
}


void ADC_voidSetCallback( void (*ptr) (void) ){
	Global_ADC_CallBack = ptr;
}

void __vector_16 (void){

	if(Global_ADC_CallBack != NULL){
		Global_ADC_CallBack();
	}
}


