#include "../../../Library/STD_types.h"
#include "../../../MCAL/DIO/Header/DIO_Interface.h"
#include "util/delay.h"

#include "../Header/SevSeg_Interface.h"

u8 MulBCDArr[10] = {
		0b00000, // 0
		0b00001, // 1
		0b00010, // 2
		0b00011, // 3
		0b00100, // 4
		0b00101, // 5
		0b00110, // 6
		0b00111, // 7
		0b10000, // 8
		0b10001  // 9
};

void SevSeg_voidSingleInit(){
	DIO_voidSetPortDir(Sev_PORT,0x7F);
}

void SevSeg_voidDoubleInit(){
	DIO_voidSetPortDir(Sev_PORT,0x7F);
	DIO_voidSetPortDir(Sev_PORT2,0x7F);
}

void SevSeg_voidDisplayNumber(u8 number){
	s8 Sev_numbers[] = Sev_Array;
	if(number < 10 && number >= 0){
		DIO_voidSetPortValue(Sev_PORT,Sev_numbers[number]);
	}
}

void SevSeg_voidSingleAutoCounter(){

	s8 Sev_numbers[] = Sev_Array;
	s32 Local_Counter1 = 0;

	for(Local_Counter1 =0;Local_Counter1 <10; Local_Counter1++){

		DIO_voidSetPortValue(Sev_PORT,Sev_numbers[Local_Counter1]);
		_delay_ms(Sev_DELAY);
	}

}

void SevSeg_voidDoubleAutoCounter(){
	s8 Sev_numbers[] = Sev_Array;
	s32 Local_Counter1 = 0;
	s32 Local_Counter2 = 0;

	for(Local_Counter1 =0; Local_Counter1 < 10; Local_Counter1++){

		DIO_voidSetPortValue(Sev_PORT2,Sev_numbers[Local_Counter1]);

		for(Local_Counter2 =0;Local_Counter2 <10; Local_Counter2++){

			DIO_voidSetPortValue(Sev_PORT,Sev_numbers[Local_Counter2]);
			_delay_ms(Sev_DELAY);
		}
	}
}

void SevSeg_voidSingleRangeCounter(s8 start, s8 end){
	s8 Sev_numbers[] = Sev_Array;
	s32 Local_Counter2 = 0;
	if(start >= 0 && start < 10 && end < 10 && end >= 0){

		if(start < end){
			for(Local_Counter2 = start; Local_Counter2 <end; Local_Counter2++){
				DIO_voidSetPortValue(Sev_PORT,Sev_numbers[Local_Counter2]);
				_delay_ms(Sev_DELAY);
			}
		}
		else{
			for(Local_Counter2 = start; Local_Counter2 >= end; Local_Counter2--){

				DIO_voidSetPortValue(Sev_PORT,Sev_numbers[Local_Counter2]);
				_delay_ms(Sev_DELAY);
			}
		}
	}
}

void SevSeg_voidDoubleRangeCounter(s8 start,s8 end){
	s8 Sev_numbers[] = Sev_Array;

	s8 Local_SevSegTwoStart = start / 10;
	s8 Local_SevSegOneStart = start % 10;

	s8 Local_SevSegTwoEnd = end / 10;
	s8 Local_SevSegOneEnd = end % 10;

	s32 Local_Counter1 = 0;
	s32 Local_Counter2 = 0;

	if(Local_SevSegTwoStart >= 0 && Local_SevSegTwoStart < 10 && Local_SevSegTwoEnd < 10 && Local_SevSegTwoEnd >= 0){

		if(start < end){
			for(Local_Counter1 = Local_SevSegTwoStart; Local_Counter1 <= Local_SevSegTwoEnd; Local_Counter1++){
				DIO_voidSetPortValue(Sev_PORT2,Sev_numbers[Local_Counter1]);

				for(Local_Counter2 =Local_SevSegOneStart;Local_Counter2 <10; Local_Counter2++){
					DIO_voidSetPortValue(Sev_PORT,Sev_numbers[Local_Counter2]);
					_delay_ms(Sev_DELAY);

					if(Local_Counter2 == Local_SevSegOneEnd && Local_Counter1 == Local_SevSegTwoEnd){
						return;
					}
				}

				Local_SevSegOneStart = 0;
			}
		}
		else{
			for(Local_Counter1 = Local_SevSegTwoStart; Local_Counter1 >= Local_SevSegTwoEnd; Local_Counter1--){

				DIO_voidSetPortValue(Sev_PORT2,Sev_numbers[Local_Counter1]);

				for(Local_Counter2 =Local_SevSegOneStart;Local_Counter2 >= 0; Local_Counter2--){

					DIO_voidSetPortValue(Sev_PORT,Sev_numbers[Local_Counter2]);
					_delay_ms(Sev_DELAY);

					if(Local_Counter2 == Local_SevSegOneEnd && Local_Counter1 == Local_SevSegTwoEnd){
						return;
					}
				}

				Local_SevSegOneStart = 9;
			}
		}
	}
}

void SevSeg_voidBCDDisplay(u8 port, u8 number){
	DIO_voidSetPortValue(port, number);
}

void SevSeg_voidBCDDoubleDisplay(s8 start,s8 end){
	s8 Local_SevSegTwoStart = start / 10;
	s8 Local_SevSegOneStart = start % 10;

	s8 Local_SevSegTwoEnd = end / 10;
	s8 Local_SevSegOneEnd = end % 10;

	s32 Local_Counter1 = 0;
	s32 Local_Counter2 = 0;
	u8 num = 0;
	if(Local_SevSegTwoStart >= 0 && Local_SevSegTwoStart < 10 && Local_SevSegTwoEnd < 10 && Local_SevSegTwoEnd >= 0){

		if(start < end){
			for(Local_Counter1 = Local_SevSegTwoStart; Local_Counter1 <= Local_SevSegTwoEnd; Local_Counter1++){
				num &= 0x0F;
				num |= (Local_Counter1 << 4);
				for(Local_Counter2 =Local_SevSegOneStart;Local_Counter2 <10; Local_Counter2++){
					num &= 0xF0;
					num |= Local_Counter2;
					_delay_ms(Sev_DELAY);
					DIO_voidSetPortValue(Sev_PORT,num);
					if(Local_Counter2 == Local_SevSegOneEnd && Local_Counter1 == Local_SevSegTwoEnd){
						return;
					}
				}

				Local_SevSegOneStart = 0;
			}
		}
		else{
			for(Local_Counter1 = Local_SevSegTwoStart; Local_Counter1 >= Local_SevSegTwoEnd; Local_Counter1--){

				num &= 0x0F;
				num |= (Local_Counter1 << 4);

				for(Local_Counter2 =Local_SevSegOneStart;Local_Counter2 >= 0; Local_Counter2--){
					num &= 0xF0;
					num |= Local_Counter2;
					_delay_ms(Sev_DELAY);
					DIO_voidSetPortValue(Sev_PORT,num);

					if(Local_Counter2 == Local_SevSegOneEnd && Local_Counter1 == Local_SevSegTwoEnd){
						return;
					}
				}
				Local_SevSegOneStart = 9;
			}
		}
	}
}

void SevSeg_voidMulBCD(s8 start,s8 end){
	s8 Local_SevSegTwoStart = start / 10;
	s8 Local_SevSegOneStart = start % 10;

	s8 Local_SevSegTwoEnd = end / 10;
	s8 Local_SevSegOneEnd = end % 10;

	s32 Local_Counter1 = 0;
	s32 Local_Counter2 = 0;
	u8 num = 0;
	u32 count = 0;
	u32 delay = 1000 / (Sev_DELAY * 2);
	if(Local_SevSegTwoStart >= 0 && Local_SevSegTwoStart < 10 && Local_SevSegTwoEnd < 10 && Local_SevSegTwoEnd >= 0){

		if(start < end){
			for(Local_Counter1 = Local_SevSegTwoStart; Local_Counter1 <= Local_SevSegTwoEnd; Local_Counter1++){
				for(Local_Counter2 =Local_SevSegOneStart;Local_Counter2 <10; Local_Counter2++){
					count = 0;
					while(count< delay){
						DIO_voidSetPortValue(Sev_PORT,MulBCDArr[Local_Counter1]);
						DIO_voidSetPinValue(DIO_PortB, DIO_PIN6, Low);
						DIO_voidSetPinValue(DIO_PortB, DIO_PIN5, High);
						_delay_ms(Sev_DELAY);
						DIO_voidSetPortValue(Sev_PORT,MulBCDArr[Local_Counter2]);
						DIO_voidSetPinValue(DIO_PortB, DIO_PIN6, High);
						DIO_voidSetPinValue(DIO_PortB, DIO_PIN5, Low);
						_delay_ms(Sev_DELAY);
						count++;
					}
					//DIO_voidSetPortValue(Sev_PORT,num);
					if(Local_Counter2 == Local_SevSegOneEnd && Local_Counter1 == Local_SevSegTwoEnd){
						return;
					}
				}

				Local_SevSegOneStart = 0;
			}
		}
		else{
			for(Local_Counter1 = Local_SevSegTwoStart; Local_Counter1 >= Local_SevSegTwoEnd; Local_Counter1--){

				num &= 0x0F;
				num |= (Local_Counter1 << 4);

				for(Local_Counter2 =Local_SevSegOneStart;Local_Counter2 >= 0; Local_Counter2--){
					num &= 0xF0;
					num |= Local_Counter2;
					_delay_ms(Sev_DELAY);
					DIO_voidSetPortValue(Sev_PORT,num);

					if(Local_Counter2 == Local_SevSegOneEnd && Local_Counter1 == Local_SevSegTwoEnd){
						return;
					}
				}
				Local_SevSegOneStart = 9;
			}
		}
	}
}
