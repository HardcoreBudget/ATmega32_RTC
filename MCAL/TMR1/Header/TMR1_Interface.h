/*
 * TMR1_Interface.h
 *
 *  Created on: Oct 27, 2023
 *      Author: Hazim Emad
 */

#ifndef MCAL_TMR1_HEADER_TMR1_INTERFACE_H_
#define MCAL_TMR1_HEADER_TMR1_INTERFACE_H_
#include "TMR1_Register.h"
#include "TMR1_Private.h"
#include "TMR1_Config.h"


void TMR1_voidInit();
void TMR1_voidSetICR(u16 value);
void TMR1_voidSetDutyCycle(u16 duty);
void TMR1_ICUsetEdgeDetectionMode(u8 edge);
u16 TMR1_ICUgetInputCaptureValue();
void TMR1_ICUclearTimerValue();
void TMR1_voidSetTimerValue(u16 value);
u16 TMR1_u16ReadTimerValue();
void TMR1_ICUDeInit();
void TMR1_voidTimer1ICUSetCallBack(void (*Copy_pvCallBackFunc)(void));

#endif /* MCAL_TMR1_HEADER_TMR1_INTERFACE_H_ */
