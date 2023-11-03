/*
 * GIE_Imp.c
 *
 *  Created on: Oct 22, 2023
 *      Author: Hazim Emad
 */

#include "../../../Library/STD_types.h"
#include "../../../Library/Bit_Math.h"
#include "../Header/GIE_Interface.h"

void GIE_voidEnable(){
	SET_BIT(SREG, SREG_I);
}

void GIE_voidDisable(){
	CLR_BIT(SREG, SREG_I);
}
