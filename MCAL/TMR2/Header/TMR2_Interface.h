/*
 * TMR2_Interface.h
 *
 *  Created on: Oct 27, 2023
 *      Author: Hazim Emad
 */

#ifndef MCAL_TMR2_HEADER_TMR2_INTERFACE_H_
#define MCAL_TMR2_HEADER_TMR2_INTERFACE_H_

#include "TMR2_Register.h"
#include "TMR2_Config.h"
#include "TMR2_Private.h"

void TMR2_voidInit();
u8 TMR2_u8GetTCNT();
void TMR2_voidSetTCNT(u8 value);
void TMR2_voidSetDuty(u8 Copy_u8DutyCycle);
void TMR2_voidTimer0CTCSetCallBack(void (*Copy_pvCallBackFunc)(void));
void TMR2_voidTimer0OVSetCallBack(void (*Copy_pvCallBackFunc)(void));
void TMR2_voidSetBusyWait(u16 Copy_u8WaitTime);

#endif /* MCAL_TMR2_HEADER_TMR2_INTERFACE_H_ */
