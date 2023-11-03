/*
 * SPI_Interface.h
 *
 *  Created on: Oct 30, 2023
 *      Author: Hazim Emad
 */

#ifndef MCAL_SPI_HEADER_SPI_INTERFACE_H_
#define MCAL_SPI_HEADER_SPI_INTERFACE_H_
#include "SPI_Register.h"
#include "SPI_Private.h"
#include "SPI_Config.h"


void SPI_voidMasterInit(void);

void SPI_voidSlaveInit(void);

u8 SPI_u8Transfer(u8 Copy_Data);

void SPI_voidSetCallBack( void (*PtrToFunc) (void) );

u8 SPI_u8ReadDataISR(void);

void SPI_voidSendDataISR(u8 Copy_Data);


#endif /* MCAL_SPI_HEADER_SPI_INTERFACE_H_ */
