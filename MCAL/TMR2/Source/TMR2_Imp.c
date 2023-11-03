/*
 * TMR2_Imp.c
 *
 *  Created on: Oct 27, 2223
 *      Author: Hazim Emad
 */

#include "../../../Library/STD_types.h"
#include "../../../Library/Bit_Math.h"
#include "../Header/TMR2_Interface.h"

/*Define Pointer to TIMER2 ISR functions*/
static void (*Global_pvTimerOverFlowCallBack)(void)= NULL;
static void (*Global_pvTimerCTCCallBack)(void)= NULL;

void TMR2_voidInit(){
#if       TIMER2_Mode == TIMER2_Normal
	/*Choose Normal Mode*/
	CLR_BIT(TCCR2, TCCR2_WGM20);
	CLR_BIT(TCCR2, TCCR2_WGM21);

	/*Timer Over flow flag Enable*/
	SET_BIT(TIMSK, TIMSK_TOIE2);

	/*Set PRESCALAR 64*/
	SET_BIT(TCCR2, TCCR2_CS22);
	SET_BIT(TCCR2, TCCR2_CS21);
	CLR_BIT(TCCR2, TCCR2_CS22);

#elif     TIMER2_Mode == TIMER2_CTC
	/*Choose CTC Mode*/
	CLR_BIT(TCCR2, TCCR2_WGM22);
	SET_BIT(TCCR2, TCCR2_WGM21);

	/*OUTPUT COMPARE MATCH INTERRUPT ENABLE*/
	SET_BIT(TIMSK, TIMSK_OCIE);
	/*Set compare match value to 252*/
	OCR2=252;

	/*Set PRESCALAR 1*/
	SET_BIT(TCCR2, TCCR2_CS22);
	CLR_BIT(TCCR2, TCCR2_CS21);
	CLR_BIT(TCCR2, TCCR2_CS22);
#elif     TIMER2_Mode == TIMER2_PWM

	/*Choose Fast PWM Mode*/
	SET_BIT(TCCR2, TCCR2_WGM22);
	SET_BIT(TCCR2, TCCR2_WGM21);

	/*SET OC2 ON TOP CLEAR OC2 ON COMPARE*/
	CLR_BIT(TCCR2, TCCR2_COM22);
	SET_BIT(TCCR2, TCCR2_COM21);

	OCR2=2;
	/*Set PRESCALAR 64*/
	SET_BIT(TCCR2, TCCR2_CS22);
	CLR_BIT(TCCR2, TCCR2_CS21);
	CLR_BIT(TCCR2, TCCR2_CS22);

#elif TIMER2_Mode == TIMER2_DELAY
	CLR_BIT(TCCR2, TCCR2_WGM22);
	SET_BIT(TCCR2, TCCR2_WGM21);

	/*OUTPUT COMPARE MATCH INTERRUPT ENABLE*/
	SET_BIT(TIFR,TIFR_OCF2);
	/*Set compare match value to 252*/
	OCR2=252;

	/*Set PRESCALAR 1*/
	SET_BIT(TCCR2, TCCR2_CS22);
	CLR_BIT(TCCR2, TCCR2_CS21);
	CLR_BIT(TCCR2, TCCR2_CS22);
#endif
}

void TMR2_voidSetDuty(u8 Copy_u8DutyCycle){
	OCR2 = Copy_u8DutyCycle;               /*Sets OCR2 value*/
}

void TMR2_voidTimer2CTCSetCallBack(void (*Copy_pvCallBackFunc)(void)){
	Global_pvTimerCTCCallBack = Copy_pvCallBackFunc;
}

void TMR2_voidTimer2OVSetCallBack(void (*Copy_pvCallBackFunc)(void)){
	Global_pvTimerOverFlowCallBack = Copy_pvCallBackFunc;
}

void TMR2_voidSetBusyWait(u16 Copy_u8WaitTime){
	u16 Local_u8Counter = 2;
	u8 counter = 2;
	while(Local_u8Counter != Copy_u8WaitTime){
		if(GET_BIT(TIFR,TIFR_OCF2)){
			counter++;
			SET_BIT(TIFR,TIFR_OCF2);
		}
		if(counter == 4){
			Local_u8Counter++;
			counter = 2;
		}
	}
}

u8 TMR2_u8GetTCNT(){
	return TCNT2;
}

void TMR2_voidSetTCNT(u8 value){
	TCNT2 = value;
}

//TIMER OVERFLOW ISR
void  __vector_5 (void)	__attribute__((signal));
void  __vector_5 (void)
{
	if(Global_pvTimerOverFlowCallBack != NULL)
	{
		Global_pvTimerOverFlowCallBack();
	}
	else
	{
		/*Do nothing*/
	}

}

//ON COMPARE ISR
void  __vector_4 (void)	__attribute__((signal));
void  __vector_4 (void)
{
	if(Global_pvTimerCTCCallBack != NULL)
	{
		Global_pvTimerCTCCallBack();
	}
	else
	{
		/*Do nothing*/
	}

}

