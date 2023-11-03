/*
 * ADC_Interface.h
 *
 *  Created on: Oct 23, 2023
 *      Author: Hazim Emad
 */

#ifndef MCAL_ADC_HEADER_ADC_INTERFACE_H_
#define MCAL_ADC_HEADER_ADC_INTERFACE_H_
#include "ADC_Register.h"
#include "ADC_Private.h"
#include "ADC_Config.h"

void ADC_voidInit();
void ADC_voidEnable();
void ADC_voidInterrputEnable();
void ADC_voidInterrputDisable();
void ADC_voidDisable();
u16 ADC_u16ReadADC();
void ADC_voidChaining(u8 addresscpy);
void ADC_voidStartConversion(u8 addresscpy);
void ADC_voidStartInterruptConversion(u8 addresscpy);
u16 ADC_u16ReadADCInMV();
void ADC_voidSetCallback( void (*ptr) (void) );
void __vector_16 (void) __attribute__ ((signal,used, externally_visible)); //to avoid optimization


#endif /* MCAL_ADC_HEADER_ADC_INTERFACE_H_ */
