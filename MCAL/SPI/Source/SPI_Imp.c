/*
 * SPI_Imp.c
 *
 *  Created on: Oct 30, 2023
 *      Author: Hazim Emad
 */
#include "../../../Library/STD_types.h"
#include "../../../Library/Bit_Math.h"
#include "../Header/SPI_Interface.h"

static void (*Global_pvSPICallBack)(void)= NULL;

void SPI_voidMasterInit(void){
	SET_BIT(SPCR,SPCR_MSTR);
	SET_BIT(SPCR,SPCR_SPE);
#if INTERRUPT_MODE == ENABLE_INTERRUPT
	SET_BIT(SPCR,SPCR_SPIE);
#endif

#if CLOCK_POLARITY == IDLE_LOW
	CLR_BIT(SPCR,SPCR_CPOL);
#elif CLOCK_POLARITY == IDLE_HIGH
	SET_BIT(SPCR,SPCR_CPOL);
#endif

#if CLOCK_PHASE == SPI_ZERO
	CLR_BIT(SPCR,SPCR_CPHA);
#elif CLOCK_PHASE == SPI_ONE
	SET_BIT(SPCR,SPCR_CPHA);
#endif


#if DATA_ORDER == LSB_FIRST
	SET_BIT(SPCR,SPCR_DORD);
#elif DATA_ORDER == MSB_FIRST
	CLR_BIT(SPCR,SPCR_DORD);
#endif

#if SPI_FREQUENCY == QUARTER_FREQ
	CLR_BIT(SPSR,SPSR_SPI2X);
	CLR_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
#elif SPI_FREQUENCY == HALF_FREQ
	SET_BIT(SPSR,SPSR_SPI2X);
	CLR_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
#endif
}

void SPI_voidSlaveInit(void){
	CLR_BIT(SPCR,SPCR_MSTR);
	SET_BIT(SPCR,SPCR_SPE);
#if INTERRUPT_MODE == ENABLE_INTERRUPT
	SET_BIT(SPCR,SPCR_SPIE);
#endif

#if DATA_ORDER == LSB_FIRST
	SET_BIT(SPCR,SPCR_DORD);
#elif DATA_ORDER == MSB_FIRST
	CLR_BIT(SPCR,SPCR_DORD);
#endif
}

u8 SPI_u8Transfer(u8 Copy_Data){
	/* Start transmission */
	SPDR = Copy_Data;
	/* Wait for transmission complete */
	while(!GET_BIT(SPSR,SPSR_SPIF));

	return SPDR;
}

void SPI_voidSetCallBack( void (*PtrToFunc) (void) ){
	Global_pvSPICallBack = PtrToFunc;
}

u8 SPI_u8ReadDataISR(void){
	return SPDR;
}

void SPI_voidSendDataISR(u8 Copy_Data){
	SPDR = Copy_Data;
}

void  __vector_12 (void)	__attribute__((signal));
void  __vector_12 (void)
{
	if(Global_pvSPICallBack != NULL)
	{
		Global_pvSPICallBack();
	}
	else
	{
		/*Do nothing*/
	}

}
