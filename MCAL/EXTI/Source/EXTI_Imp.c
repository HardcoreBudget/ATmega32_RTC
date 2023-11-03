/*
 * EXTI_Imp.c
 *
 *  Created on: Oct 22, 2023
 *      Author: Hazim Emad
 */

#include "../../../Library/STD_types.h"
#include "../../../Library/Bit_Math.h"
#include "../Header/EXTI_Interface.h"

void (*Global_EXTI0_CallBack)(void)= NULL;
void (*Global_EXTI1_CallBack)(void)= NULL;
void (*Global_EXTI2_CallBack)(void)= NULL;

//init the INT with sensing mood in preprocessing stage
void EXTI0_voidInit(void){
	/*Check sense control of Pin INT0*/
#if 	INT0_SENSE == EXTI_LOW

	CLR_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC00);
	CLR_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC01);

#elif 	INT0_SENSE == EXTI_IOC

	SET_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC00);
	CLR_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC01);

#elif 	INT0_SENSE == EXTI_FALLING

	CLR_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC00);
	SET_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC01);

#elif 	INT0_SENSE == EXTI_RISING

	SET_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC00);
	SET_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC01);

#else
#error "WRONG SENSE CONTROL CONFIGURATION FOR INT0"
#endif
}
void EXTI1_voidInit(void){
	/*Check sense control of Pin INT0*/
#if 	INT1_SENSE == EXTI_LOW

	CLR_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC10);
	CLR_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC11);

#elif 	INT1_SENSE == EXTI_IOC

	SET_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC10);
	CLR_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC11);

#elif 	INT1_SENSE == EXTI_FALLING

	CLR_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC10);
	SET_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC11);

#elif 	INT1_SENSE == EXTI_RISING

	SET_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC10);
	SET_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC11);

#else
#error "WRONG SENSE CONTROL CONFIGURATION FOR INT0"
#endif
}
void EXTI2_voidInit(void){
	/*Check sense control of Pin INT0*/
#if 	INT2_SENSE == EXTI_FALLING
	CLR_BIT(EXTI_MCUCSR,EXTI_MCUCSR_ISC2);

#elif 	INT2_SENSE == EXTI_RISING
	SET_BIT(EXTI_MCUCSR,EXTI_MCUCSR_ISC2);

#else
#error "WRONG SENSE CONTROL CONFIGURATION FOR INT0"
#endif
}

//enable EXTI
void EXTI0_voidEnable(void){
	SET_BIT(EXTI_GICR,EXTI_GICR_INT0);
}
void EXTI1_voidEnable(void){
	SET_BIT(EXTI_GICR,EXTI_GICR_INT1);
}
void EXTI2_voidEnable(void){
	SET_BIT(EXTI_GICR,EXTI_GICR_INT2);
}

//disable EXTI
void EXTI0_voidDisable(void){
	CLR_BIT(EXTI_GICR,EXTI_GICR_INT0);
}
void EXTI1_voidDisable(void){
	CLR_BIT(EXTI_GICR,EXTI_GICR_INT1);
}
void EXTI2_voidDisable(void){
	CLR_BIT(EXTI_GICR,EXTI_GICR_INT2);
}

//change the INT with sensing mood in runtime
void EXTI0_voidSetSignalch(u8 SenseCpy){
	switch(SenseCpy){
	case EXTI_FALLING:
		CLR_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC00);
		SET_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC01);
		break;
	case EXTI_RISING:
		SET_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC00);
		SET_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC01);
		break;
	case EXTI_IOC:
		SET_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC00);
		CLR_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC01);
		break;
	case EXTI_LOW:
		CLR_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC00);
		CLR_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC01);
		break;
	}
}
void EXTI1_voidSetSignalch(u8 SenseCpy){
	switch(SenseCpy){
	case EXTI_FALLING:
		CLR_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC10);
		SET_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC11);
		break;
	case EXTI_RISING:
		SET_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC10);
		SET_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC11);
		break;
	case EXTI_IOC:
		SET_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC10);
		CLR_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC11);
		break;
	case EXTI_LOW:
		CLR_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC10);
		CLR_BIT(EXTI_MCUCR,EXTI_MCUCR_ISC11);
		break;
	}
}
void EXTI2_voidSetSignalch(u8 SenseCpy){
	switch(SenseCpy){
	case EXTI_FALLING:
		CLR_BIT(EXTI_MCUCSR,EXTI_MCUCSR_ISC2);
		break;
	case EXTI_RISING:
		SET_BIT(EXTI_MCUCSR,EXTI_MCUCSR_ISC2);
		break;
	}
}

//callback function
void EXTI0_VID_SET_CALL_BACK(void (*PTR)(void)){
	Global_EXTI0_CallBack = PTR;
}
void EXTI1_VID_SET_CALL_BACK(void (*PTR)(void)){
	Global_EXTI1_CallBack = PTR;
}
void EXTI2_VID_SET_CALL_BACK(void (*PTR)(void)){
	Global_EXTI2_CallBack = PTR;
}

void __vector_1 (void){
	if(Global_EXTI0_CallBack != NULL){
		Global_EXTI0_CallBack();
	}
}
void __vector_2 (void){
	if(Global_EXTI1_CallBack != NULL){
		Global_EXTI1_CallBack();
	}
}
void __vector_3 (void){
	if(Global_EXTI2_CallBack != NULL){
		Global_EXTI2_CallBack();
	}
}
