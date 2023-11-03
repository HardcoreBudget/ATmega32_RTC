/*
 * TMR0_Interface.h
 *
 *  Created on: Oct 27, 2023
 *      Author: Hazim Emad
 */

#ifndef MCAL_TMR0_HEADER_TMR0_INTERFACE_H_
#define MCAL_TMR0_HEADER_TMR0_INTERFACE_H_
#include "TMR0_Register.h"
#include "TMR0_Config.h"
#include "TMR0_Private.h"

void TMR0_voidInit();
u8 TMR0_u8GetTCNT();
void TMR0_voidSetTCNT(u8 value);
void TMR0_voidSetDuty(u8 Copy_u8DutyCycle);
void TMR0_voidTimer0CTCSetCallBack(void (*Copy_pvCallBackFunc)(void));
void TMR0_voidTimer0OVSetCallBack(void (*Copy_pvCallBackFunc)(void));
void TMR0_voidSetBusyWait(u16 Copy_u8WaitTime);

#endif /* MCAL_TMR0_HEADER_TMR0_INTERFACE_H_ */
