/*
 * main.c
 *
 *  Created on: Oct 17, 2023
 *      Author: Hazim Emad
 */
#include "../Library/STD_types.h"
#include "../Library/Bit_Math.h"
#include "../MCAL/DIO/Header/DIO_Interface.h"
#include "../HAL/LCD/Header/LCD_Interface.h"
#include "../MCAL/I2C/Header/I2C_Interface.h"
#include "util/delay.h"

#define SLAVE_ADDRESS				0xD0 //1010 XXXX
#define TIME_REGISTER_ADDRESS		0x00 //XXXX Address
#define CALENDAR_REGISTER_ADDRESS	0x03 //XXXX Address
#define INITIAL_HOUR	3
#define INITIAL_MINUTE	2
#define INITIAL_SECOND	0
#define INITIAL_DATE	3
#define INITIAL_MONTH	11
#define INITIAL_YEAR	23
#define INITIAL_DAY		5


volatile u8 second =INITIAL_SECOND;
volatile u8 minute = INITIAL_MINUTE;
volatile u8 hour = INITIAL_HOUR;

volatile u8 day = INITIAL_DAY;
volatile u8 date = INITIAL_DATE;
volatile u8 month = INITIAL_MONTH;
volatile u8 year = INITIAL_YEAR;

u8* days[7]= {(u8*)"Sun",(u8*)"Mon",(u8*)"Tue",(u8*)"Wed",(u8*)"Thu",(u8*)"Fri",(u8*)"Sat"};

void RTC_Clock_Write(u8 _hour, u8 _minute, u8 _second);
void RTC_Calendar_Write(u8 _day, u8 _date, u8 _month, u8 _year);
void RTC_Read_Clock();
void RTC_Read_Calendar();
u8 ConvertToRTC(u8 num);
u8 ConvertFromRTC(u8 num);
int main(){
	DIO_voidInit();
	DIO_voidSetPinValue(DIO_PortC,DIO_PIN0, High);
	DIO_voidSetPinValue(DIO_PortC,DIO_PIN1, High);
	LCD_voidInit();
	I2C_Master_voidInit();

	minute =ConvertToRTC(minute);
	second = ConvertToRTC(second);
	hour = ConvertToRTC(hour);

	RTC_Clock_Write(hour, minute, second);

	date = ConvertToRTC(date);
	month = ConvertToRTC(month);
	year = ConvertToRTC(year);

	RTC_Calendar_Write(day, date, month, year);

	while(1){
		RTC_Read_Clock();	/* Read clock with second add. i.e location is 0 */
		second = ConvertFromRTC(second);
		minute = ConvertFromRTC(minute);
		hour = ConvertFromRTC(hour);

		LCD_voidGoToPosition(0,0);
		if(hour < 10){
			LCD_voidWriteChar('0');
		}
		LCD_voidWriteIntData(hour);
		LCD_voidWriteChar(':');
		if(minute < 10){
			LCD_voidWriteChar('0');
		}
		LCD_voidWriteIntData(minute);
		LCD_voidWriteChar(':');
		if(second < 10){
			LCD_voidWriteChar('0');
		}
		LCD_voidWriteIntData(second);

		RTC_Read_Calendar();	/* Read calendar with day address i.e location is 3 */
		date = ConvertFromRTC(date);
		month = ConvertFromRTC(month);
		year = ConvertFromRTC(year);

		LCD_voidGoToPosition(1,0);
		if(date < 10){
			LCD_voidWriteChar('0');
		}
		LCD_voidWriteIntData(date);
		LCD_voidWriteChar('/');
		if(month < 10){
			LCD_voidWriteChar('0');
		}
		LCD_voidWriteIntData(month);
		LCD_voidWriteChar('/');
		if(year < 10){
			LCD_voidWriteChar('0');
		}
		LCD_voidWriteIntData(year);
		LCD_voidWriteChar(' ');
		LCD_voidWriteString(days[day]);
	}
	return 0;
}


/* function for clock */
void RTC_Clock_Write(u8 _hour, u8 _minute, u8 _second){
	I2C_Master_enuSendStartCond();
	I2C_Master_enuSendSlaveAddressWithWrite(SLAVE_ADDRESS);
	I2C_Master_enuSendu8Data(TIME_REGISTER_ADDRESS);
	I2C_Master_enuSendu8Data(_second);
	I2C_Master_enuSendu8Data(_minute);
	I2C_Master_enuSendu8Data(_hour);
	I2C_Master_enuSendStopCond();
}

/* function for calendar */
void RTC_Calendar_Write(u8 _day, u8 _date, u8 _month, u8 _year){
	I2C_Master_enuSendStartCond();
	I2C_Master_enuSendSlaveAddressWithWrite(SLAVE_ADDRESS);
	I2C_Master_enuSendu8Data(CALENDAR_REGISTER_ADDRESS);
	I2C_Master_enuSendu8Data(_day);
	I2C_Master_enuSendu8Data(_date);
	I2C_Master_enuSendu8Data(_month);
	I2C_Master_enuSendu8Data(_year);
	I2C_Master_enuSendStopCond();
}

void RTC_Read_Clock(){
	I2C_Master_enuSendStartCond();
	I2C_Master_enuSendSlaveAddressWithWrite(SLAVE_ADDRESS);
	I2C_Master_enuSendu8Data(TIME_REGISTER_ADDRESS);
	I2C_Master_enuSendRepeatedStartCond();
	I2C_Master_enuSendSlaveAddressWithRead(SLAVE_ADDRESS);
	I2C_Master_enuReadu8Data(&second);
	I2C_Master_enuReadu8Data(&minute);
	I2C_Master_enuReadu8Data(&hour);
	I2C_Master_voidFlush();
	I2C_Master_enuSendStopCond();
}

void RTC_Read_Calendar(){
	I2C_Master_enuSendStartCond();
	I2C_Master_enuSendSlaveAddressWithWrite(SLAVE_ADDRESS);
	I2C_Master_enuSendu8Data(CALENDAR_REGISTER_ADDRESS);
	I2C_Master_enuSendRepeatedStartCond();
	I2C_Master_enuSendSlaveAddressWithRead(SLAVE_ADDRESS);
	I2C_Master_enuReadu8Data(&day);
	I2C_Master_enuReadu8Data(&date);
	I2C_Master_enuReadu8Data(&month);
	I2C_Master_enuReadu8Data(&year);
	I2C_Master_voidFlush();
	I2C_Master_enuSendStopCond();
}

u8 ConvertToRTC(u8 num){
	u8 _L = num%10;
	u8 _H = (num/10)<<4;
	return (_H | _L);
}

u8 ConvertFromRTC(u8 num){
	return ((num>>4) * 10 + (num&0x0F));
}


