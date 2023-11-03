/*
 * USART_Imp.c
 *
 *  Created on: Oct 29, 2023
 *      Author: Hazim Emad
 */

#include "../../../Library/STD_types.h"
#include "../../../Library/Bit_Math.h"

#include "../Header/USART_Interface.h"


static void (*Global_UDRECallBack)(void)= NULL;
static void (*Global_RXCCallBack)(void)= NULL;


void USART_voidInit()
{
#if SPEED_OPERATION == USART_DOUBLE_SPEED_MODE
#define UBRR_VALUE (((f32)F_OSC/(8 * USART_BAUDRATE))-1)
	SET_BIT(UCSRA,UCSRA_U2X);    /* Configure UART double speed rate*/
#elif SPEED_OPERATION == USART_NORMAL_SPEED_MODE
#define UBRR_VALUE ((F_OSC/(16 * USART_BAUDRATE))-1)
#endif

	/******************** UCSRC Config ************************/
	/* URSEL  = 1 to enable writing on UCSRC
	 * UMSEL  = 0 (Asynchronous mode)
	 * UPM1:0 = 0 (Disable parity)
	 * USBS   = 0 (One bit stop bit)
	 * UCSZ1  = UCSZ0 = 1 (8-bit data size)
	 * UCPOL  = 0  (0 for Asynch. mode)
	 */
	SET_BIT(UCSRC, UCSRC_URSEL);

#if MODE_OF_OPERATION == USART_ASYNCHRONOUS
	CLR_BIT(UCSRC, UCSRC_UMSEL);
	CLR_BIT(UCSRC, UCSRC_UCPOL);
#else
#define UBRR_VALUE ((F_OSC/(2 * USART_BAUDRATE))-1)
#if CLOCK_POLARITY == USART_CLOCK_RISING
	SET_BIT(UCSRC, UCSRC_UCPOL);
#elif CLOCK_POLARITY == USART_CLOCK_FALLING
	CLR_BIT(UCSRC, UCSRC_UCPOL);
#endif
#endif

#if FRAME_SIZE == 8
//	UCSRC |= (1<< UCSRC_URSEL| 1 << UCSRC_UCSZ0 | UCSRC, 1 << UCSRC_UCSZ1);
	SET_BIT(UCSRC, UCSRC_UCSZ0);
	SET_BIT(UCSRC, UCSRC_UCSZ1);
#endif

#if PARITY_MODE == USART_PARITY_DISABLED
	CLR_BIT(UCSRC, UCSRC_UPM1);
	CLR_BIT(UCSRC, UCSRC_UPM0);
#endif

#if STOP_BIT_SELECT == USART_STOP_2BIT
	SET_BIT(UCSRC, UCSRC_USBS);
#elif STOP_BIT_SELECT == USART_STOP_1BIT
	CLR_BIT(UCSRC, UCSRC_USBS);
#endif

	/* Write data in UBRR*/
	CLR_BIT(UCSRC, UCSRC_URSEL);

	UCSRC = 0; // writing to UBRRH
	UBRRL = UBRR_VALUE;

	/******************** UCSRB Config ************************/
	/* RXCIE = TXCIE = UDRIE = 0  (No interrupt Mode)
	 * RXEN = TXEN = 1 (Enable receive and transmit)
	 * UCSZ2 = 0 (8-bit data size)
	 * RXB8 & TXB8 not used
	 */
	SET_BIT(UCSRB, UCSRB_RXEN);
	SET_BIT(UCSRB, UCSRB_TXEN);
}


void USART_voidEnableUDREInterrupt(){
	SET_BIT(UCSRB,UCSRB_UDRIE);
}

void USART_voidDisableUDREInterrupt(){
	CLR_BIT(UCSRB,UCSRB_UDRIE);
}

void USART_voidEnableRXCInterrupt(){
	SET_BIT(UCSRB,UCSRB_RXCIE);
}

void USART_voidDisableRXCInterrupt(){
	CLR_BIT(UCSRB,UCSRB_RXCIE);
}

void USART_voidSendByte(const u8 data)
{
	/*UDRE is 1 once UDR register is empty*/
	while(!GET_BIT(UCSRA,UCSRA_UDRE));
	/*Once polling finished (UDR is empty) load ur new data in the UDR register*/
	UDR = data;
}

void USART_voidSendInterruptByte(const u8 data){
	UDR = data;
}

u8 USART_u8ReceiveInterruptByte(){
	return UDR;
}

u8 USART_u8ReceiveByte()
{
	while(!GET_BIT(UCSRA, UCSRA_RXC));
	return UDR;
}

void USART_voidSendString(const u8* str)
{
	while(*str != '\0')
	{
		USART_voidSendByte(*str);
		str++;
	}
}

void USART_voidReceiveString(u8* str)
{
	u8 i = 0;
	while(str[i] != '\0')
	{
		str[i++] = USART_u8ReceiveByte();
	}
	str[i]= '\0';
}

void USART_voidRXCSetCallBack(void (*Copy_pvCallBackFunc)(void)){
	Global_RXCCallBack = Copy_pvCallBackFunc;
}

void USART_voidUDRESetCallBack(void (*Copy_pvCallBackFunc)(void)){
	Global_UDRECallBack = Copy_pvCallBackFunc;
}

void  __vector_13 (void)	__attribute__((signal));
void  __vector_13 (void)
{
	if(Global_RXCCallBack != NULL)
	{
		Global_RXCCallBack();
	}
	else
	{
		/*Do nothing*/
	}

}

void  __vector_14 (void)	__attribute__((signal));
void  __vector_14 (void)
{
	if(Global_UDRECallBack != NULL)
	{
		Global_UDRECallBack();
	}
	else
	{
		/*Do nothing*/
	}

}
