/*
 * USART_Interface.h
 *
 *  Created on: Oct 29, 2023
 *      Author: Hazim Emad
 */

#ifndef MCAL_USART_HEADER_USART_INTERFACE_H_
#define MCAL_USART_HEADER_USART_INTERFACE_H_

#include "USART_Register.h"
#include "USART_Private.h"
#include "USART_Config.h"


void USART_voidInit();
void USART_voidSendByte(const u8 data);
u8 USART_u8ReceiveByte();
void USART_voidSendString(const u8* str);
void USART_voidReceiveString(u8* str);

void USART_voidSendInterruptByte(const u8 data);
u8 USART_u8ReceiveInterruptByte();
void USART_voidEnableUDREInterrupt();
void USART_voidDisableUDREInterrupt();
void USART_voidEnableRXCInterrupt();
void USART_voidDisableRXCInterrupt();
void USART_voidRXCSetCallBack(void (*Copy_pvCallBackFunc)(void));
void USART_voidUDRESetCallBack(void (*Copy_pvCallBackFunc)(void));

#endif /* MCAL_USART_HEADER_USART_INTERFACE_H_ */
