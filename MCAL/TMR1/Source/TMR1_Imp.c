/*
 * TMR1_Imp.c
 *
 *  Created on: Oct 27, 2023
 *      Author: Hazim Emad
 */
#include"../../../Library/STD_types.h"
#include"../../../Library/Bit_Math.h"
#include "../Header/TMR1_Interface.h"

static void (*Global_pvTimerICUCallBack)(void)= NULL;

void TMR1_voidInit(){
	//Configure TIMER1
	TCCR1A = 0;
	TCCR1B = 0;
#if       TIMER1_Mode == TIMER1_NORMAL
	/*Choose Normal Mode*/
	CLR_BIT(TCCR1A, TCCR1A_WGM10);
	CLR_BIT(TCCR1A, TCCR1A_WGM11);
	CLR_BIT(TCCR1B, TCCR1B_WGM12);
	CLR_BIT(TCCR1B, TCCR1B_WGM13);


	/*Timer Over flow flag Enable*/
	SET_BIT(TIMSK, TIMSK_TOIE);

#elif     TIMER1_Mode == TIMER1_CTC
	/*Choose CTC Mode*/
	CLR_BIT(TCCR1A, TCCR1A_WGM10);
	CLR_BIT(TCCR1A, TCCR1A_WGM11);
	SET_BIT(TCCR1B, TCCR1B_WGM12);
	SET_BIT(TCCR1B, TCCR1B_WGM13);

	/*OUTPUT COMPARE MATCH INTERRUPT ENABLE*/
	SET_BIT(TIMSK, TIMSK_OCIE);

	/*Set compare match value to 250*/
	OCR0=250;
	OCR1A = 250;
	OCR1B = 250;
	/*Set PRESCALAR 8*/
	CLR_BIT(TCCR1B, TCCR1B_CS10);
	SET_BIT(TCCR1B, TCCR1B_CS11);
	CLR_BIT(TCCR1B, TCCR1B_CS12);
#elif TIMER1_Mode == TIMER1_PWM
#if PWM_MODE	== TIMER1_FPWM
#if INVERTING_MODE == TIMER1_Noninverting
	//NON Inverted PWM
	SET_BIT(TCCR1A,TCCR1A_COM1A1);
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	SET_BIT(TCCR1A,TCCR1A_COM1B1);
	CLR_BIT(TCCR1A,TCCR1A_COM1B0);

	//MODE 14(FAST PWM)
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);
#endif
#endif

#elif TIMER1_Mode == TIMER1_ICU
#if TIMER1_DefaultEdge == TIMER1_RISING
	SET_BIT(TCCR1B,TCCR1B_ICES);
#elif TIMER1_DefaultEdge == TIMER1_FALLING
	CLR_BIT(TCCR1B,TCCR1B_ICES);
#endif

#if TIMER1_NoiseOption == TIMER1_ACTIVENOISECANCELLER
	SET_BIT(TCCR1B,TCCR1B_ICNC1);
#elif TIMER1_NoiseOption == TIMER1_NONOISECANCELLER
	CLR_BIT(TCCR1B,TCCR1B_ICNC1);
#endif

	TCNT1 = 0; /*init timer1 counter 0*/
	ICR1 = 0;  /*init Input Capture register counter 0*/

	/* Enable ICU Interrupt*/
	SET_BIT(TIMSK,TIMSK_TICIE1);
#endif
	SET_BIT(TCCR1B,TCCR1B_CS10);
	CLR_BIT(TCCR1B,TCCR1B_CS11);
	SET_BIT(TCCR1B,TCCR1B_CS12);
}

void TMR1_voidSetICR(u16 value){
	ICR1 = value;
}

void TMR1_voidSetTimerValue(u16 value){
	TCNT1 = value;
}
u16 TMR1_u16ReadTimerValue(){
	return TCNT1;
}

void TMR1_voidSetDutyCycle(u16 duty){
	OCR1A = duty;
}

void TMR1_ICUsetEdgeDetectionMode(u8 edge)
{
	if(edge == TIMER1_RISING){
		SET_BIT(TCCR1B,TCCR1B_ICES);
	}
	else if(edge == TIMER1_FALLING){
		CLR_BIT(TCCR1B,TCCR1B_ICES);
	}
}

u16 TMR1_ICUgetInputCaptureValue()
{
	return ICR1;
}

void TMR1_ICUclearTimerValue()
{
	TCNT1 = 0;
}

void TMR1_ICUDeInit()
{
	TCCR1A = 0;
	TCCR1B = 0;
	TCNT1  = 0;
	ICR1   = 0;

	/* Disable the interrupt */
	CLR_BIT(TIMSK,TIMSK_TICIE1);
}

void TMR1_voidTimer1ICUSetCallBack(void (*Copy_pvCallBackFunc)(void)){
	Global_pvTimerICUCallBack = Copy_pvCallBackFunc;
}

void __vector_6(void) __attribute__((signal));
void __vector_6(void)
{
	if(Global_pvTimerICUCallBack != NULL){
		Global_pvTimerICUCallBack();
	}
}


