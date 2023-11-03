#ifndef HAL_SEVSEG_SEVSEG_INTERFACE_H_
#define HAL_SEVSEG_SEVSEG_INTERFACE_H_

#include "SevSeg_Config.h"
#include "SevSeg_private.h"

void SevSeg_voidSingleInit();
void SevSeg_voidDoubleInit();
void SevSeg_voidDisplayNumber(u8 number);
void SevSeg_voidSingleAutoCounter();
void SevSeg_voidDoubleAutoCounter();
void SevSeg_voidSingleRangeCounter(s8 start,s8 end);
void SevSeg_voidDoubleRangeCounter(s8 start,s8 end);
void SevSeg_voidBCDDoubleDisplay(s8 start,s8 end);
void SevSeg_voidBCDDisplay(u8 port, u8 number);
void SevSeg_voidMulBCD(s8 start,s8 end);

#endif /* HAL_SEVSEG_SEVSEG_INTERFACE_H_ */
