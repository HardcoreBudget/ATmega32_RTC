/*
 * EXTI_Interface.h
 *
 *  Created on: Oct 22, 2023
 *      Author: Hazim Emad
 */

#ifndef MCAL_EXTI_HEADER_EXTI_INTERFACE_H_
#define MCAL_EXTI_HEADER_EXTI_INTERFACE_H_

#include "EXTI_Config.h"
#include "EXTI_Private.h"
#include "EXTI_Registers.h"

//init the INT with sensing mood in preprocessing stage
void EXTI0_voidInit(void);
void EXTI1_voidInit(void);
void EXTI2_voidInit(void);

//enable EXTI
void EXTI0_voidEnable(void);
void EXTI1_voidEnable(void);
void EXTI2_voidEnable(void);

//disable EXTI
void EXTI0_voidDisable(void);
void EXTI1_voidDisable(void);
void EXTI2_voidDisable(void);

//change the INT with sensing mood in runtime
void EXTI0_voidSetSignalch(u8 SenseCpy);
void EXTI1_voidSetSignalch(u8 SenseCpy);
void EXTI2_voidSetSignalch(u8 SenseCpy);

//callback function
void EXTI0_VID_SET_CALL_BACK(void (*PTR)(void));
void EXTI1_VID_SET_CALL_BACK(void (*PTR)(void));
void EXTI2_VID_SET_CALL_BACK(void (*PTR)(void));

void __vector_1 (void) __attribute__ ((signal,used, externally_visible)); //to avoid optimization
void __vector_2 (void) __attribute__ ((signal,used, externally_visible)); //to avoid optimization
void __vector_3 (void) __attribute__ ((signal,used, externally_visible)); //to avoid optimization

#endif /* MCAL_EXTI_HEADER_EXTI_INTERFACE_H_ */
