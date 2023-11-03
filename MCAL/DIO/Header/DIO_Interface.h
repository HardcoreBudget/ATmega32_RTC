/*
 * DIO_Interface.h
 *
 *  Created on: Oct 17, 2023
 *      Author: Hazim Emad
 */

#ifndef MCAL_DIO_HEADER_DIO_INTERFACE_H_
#define MCAL_DIO_HEADER_DIO_INTERFACE_H_

#include "DIO_Config.h"

#define DIO_PortA		1
#define DIO_PortB		2
#define DIO_PortC		3
#define DIO_PortD		4

#define DIO_PIN0		0
#define DIO_PIN1		1
#define DIO_PIN2		2
#define DIO_PIN3		3
#define DIO_PIN4		4
#define DIO_PIN5		5
#define DIO_PIN6		6
#define DIO_PIN7		7

#define Output			1
#define Input			0
#define High 			1
#define Low 			0

void DIO_voidInit();

void DIO_voidSetPinDir(u8 Local_PortName,u8 Local_PinNumber,u8 Local_PinDir);
void DIO_voidSetPinValue(u8 Local_PortName,u8 Local_PinNumber,u8 Local_PinValue);
u8 DIO_u8GetPinValue(u8 Local_PortName,u8 Local_PinNumber);
void DIO_voidTogglePin(u8 Local_PortName,u8 Local_PinNumber);

void DIO_voidSetPortDir(u8 Local_PortName,u8 Local_PortDir);
void DIO_voidSetPortValue(u8 Local_PortName,u8 Local_PortValue);
u8 DIO_u8GetPortValue(u8 Local_PortName);
void DIO_voidTogglePort(u8 Local_PortName);

#endif /* MCAL_DIO_HEADER_DIO_INTERFACE_H_ */
