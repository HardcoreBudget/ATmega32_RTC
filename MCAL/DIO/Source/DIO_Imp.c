/*
s * DIO_Imp.c
 *
 *  Created on: Oct 17, 2023
 *      Author: Hazim Emad
 */

#include "../../../Library/STD_types.h"
#include "../../../Library/Bit_Math.h"
#include "../Header/DIO_Interface.h"
#include "../Header/DIO_Register.h"

void DIO_voidInit(){
	DIO_voidSetPortDir(DIO_PortA,concate(DIO_PINA7, DIO_PINA6, DIO_PINA5, DIO_PINA4, DIO_PINA3, DIO_PINA2, DIO_PINA1, DIO_PINA0));
	DIO_voidSetPortDir(DIO_PortB,concate(DIO_PINB7, DIO_PINB6, DIO_PINB5, DIO_PINB4, DIO_PINB3, DIO_PINB2, DIO_PINB1, DIO_PINB0));
	DIO_voidSetPortDir(DIO_PortC,concate(DIO_PINC7, DIO_PINC6, DIO_PINC5, DIO_PINC4, DIO_PINC3, DIO_PINC2, DIO_PINC1, DIO_PINC0));
	DIO_voidSetPortDir(DIO_PortD,concate(DIO_PIND7, DIO_PIND6, DIO_PIND5, DIO_PIND4, DIO_PIND3, DIO_PIND2, DIO_PIND1, DIO_PIND0));
}

void DIO_voidSetPinDir(u8 Local_PortName,u8 Local_PinNumber,u8 Local_PinDir){
	if(Local_PortName <= DIO_PortD && Local_PortName >= DIO_PortA){
		if(Local_PinNumber <= DIO_PIN7 && Local_PinNumber >= DIO_PIN0){
			if(Local_PinDir == Output){
				switch(Local_PortName){
				case DIO_PortA:
					Set_Bit(DIO_DDRA,Local_PinNumber);
					break;
				case DIO_PortB:
					Set_Bit(DIO_DDRB,Local_PinNumber);
					break;
				case DIO_PortC:
					Set_Bit(DIO_DDRC,Local_PinNumber);
					break;
				case DIO_PortD:
					Set_Bit(DIO_DDRD,Local_PinNumber);
					break;
				}
			}
			else if(Local_PinDir == Input){
				switch(Local_PortName){
				case DIO_PortA:
					Clear_Bit(DIO_DDRA,Local_PinNumber);
					break;
				case DIO_PortB:
					Clear_Bit(DIO_DDRB,Local_PinNumber);
					break;
				case DIO_PortC:
					Clear_Bit(DIO_DDRC,Local_PinNumber);
					break;
				case DIO_PortD:
					Clear_Bit(DIO_DDRD,Local_PinNumber);
					break;
				}
			}
		}
	}
}

void DIO_voidSetPinValue(u8 Local_PortName,u8 Local_PinNumber,u8 Local_PinValue){
	if(Local_PortName <= DIO_PortD && Local_PortName >= DIO_PortA){
		if(Local_PinNumber <= DIO_PIN7 && Local_PinNumber >= DIO_PIN0){
			if(Local_PinValue == High){
				switch(Local_PortName){
				case DIO_PortA:
					Set_Bit(DIO_PORTA,Local_PinNumber);
					break;
				case DIO_PortB:
					Set_Bit(DIO_PORTB,Local_PinNumber);
					break;
				case DIO_PortC:
					Set_Bit(DIO_PORTC,Local_PinNumber);
					break;
				case DIO_PortD:
					Set_Bit(DIO_PORTD,Local_PinNumber);
					break;
				}
			}
			else if(Local_PinValue == Low){
				switch(Local_PortName){
				case DIO_PortA:
					Clear_Bit(DIO_PORTA,Local_PinNumber);
					break;
				case DIO_PortB:
					Clear_Bit(DIO_PORTB,Local_PinNumber);
					break;
				case DIO_PortC:
					Clear_Bit(DIO_PORTC,Local_PinNumber);
					break;
				case DIO_PortD:
					Clear_Bit(DIO_PORTD,Local_PinNumber);
					break;
				}
			}
		}
	}
}

u8 DIO_u8GetPinValue(u8 Local_PortName,u8 Local_PinNumber){
	if(Local_PortName <= DIO_PortD && Local_PortName >= DIO_PortA){
		if(Local_PinNumber <= DIO_PIN7 && Local_PinNumber >= DIO_PIN0){
			switch(Local_PortName){
			case DIO_PortA:
				return Get_Bit(DIO_PINA,Local_PinNumber);
			case DIO_PortB:
				return Get_Bit(DIO_PINB,Local_PinNumber);
			case DIO_PortC:
				return Get_Bit(DIO_PINC,Local_PinNumber);
			case DIO_PortD:
				return Get_Bit(DIO_PIND,Local_PinNumber);
			}
		}
	}
	return -1;
}

void DIO_voidTogglePin(u8 Local_PortName,u8 Local_PinNumber){
	if(Local_PortName <= DIO_PortD && Local_PortName >= DIO_PortA){
		if(Local_PinNumber <= DIO_PIN7 && Local_PinNumber >= DIO_PIN0){
			switch(Local_PortName){
			case DIO_PortA:
				Toggle_Bit(DIO_PORTA,Local_PinNumber);
				break;
			case DIO_PortB:
				Toggle_Bit(DIO_PORTB,Local_PinNumber);
				break;
			case DIO_PortC:
				Toggle_Bit(DIO_PORTC,Local_PinNumber);
				break;
			case DIO_PortD:
				Toggle_Bit(DIO_PORTD,Local_PinNumber);
				break;
			}
		}
	}
}

void DIO_voidSetPortDir(u8 Local_PortName,u8 Local_PortDir){
	if(Local_PortName <= DIO_PortD && Local_PortName >= DIO_PortA){
		switch(Local_PortName){
		case DIO_PortA:
			DIO_DDRA = Local_PortDir;
			break;
		case DIO_PortB:
			DIO_DDRB = Local_PortDir;
			break;
		case DIO_PortC:
			DIO_DDRC = Local_PortDir;
			break;
		case DIO_PortD:
			DIO_DDRD = Local_PortDir;
			break;
		}
	}
}

void DIO_voidSetPortValue(u8 Local_PortName,u8 Local_PortValue){
	if(Local_PortName <= DIO_PortD && Local_PortName >= DIO_PortA){
		switch(Local_PortName){
		case DIO_PortA:
			DIO_PORTA = Local_PortValue;
			break;
		case DIO_PortB:
			DIO_PORTB = Local_PortValue;
			break;
		case DIO_PortC:
			DIO_PORTC = Local_PortValue;
			break;
		case DIO_PortD:
			DIO_PORTD = Local_PortValue;
			break;
		}
	}
}
u8 DIO_u8GetPortValue(u8 Local_PortName){
	if(Local_PortName <= DIO_PortD && Local_PortName >= DIO_PortA){
		switch(Local_PortName){
		case DIO_PortA:
			return DIO_PORTA;
		case DIO_PortB:
			return DIO_PORTB;
		case DIO_PortC:
			return DIO_PORTC;
		case DIO_PortD:
			return DIO_PORTD;
		}
	}
	return -1;
}

void DIO_voidTogglePort(u8 Local_PortName){
	if(Local_PortName <= DIO_PortD && Local_PortName >= DIO_PortA){
			switch(Local_PortName){
			case DIO_PortA:
				DIO_PORTA ^= 0xFF;
				break;
			case DIO_PortB:
				DIO_PORTB ^= 0xFF;
				break;
			case DIO_PortC:
				DIO_PORTC ^= 0xFF;
				break;
			case DIO_PortD:
				DIO_PORTD ^= 0xFF;
				break;
			}
		}
}
