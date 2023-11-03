/*
 * I2C_Imp.c
 *
 *  Created on: Oct 31, 2023
 *      Author: Hazim Emad
 */

#include "../../../Library/STD_types.h"
#include "../../../Library/Bit_Math.h"
#include "../Header/I2C_Interface.h"

void I2C_Master_voidInit(void){
#if I2C_PRESCALER == I2C_PRESCALER_1
	/*Set Prescaler Values*/
	CLR_BIT(TWSR, TWSR_TWPS0);
	CLR_BIT(TWSR, TWSR_TWPS1);
#elif I2C_PRESCALER == I2C_PRESCALER_4
	/*Set Prescaler Values*/
	SET_BIT(TWSR, TWSR_TWPS0);
	CLR_BIT(TWSR, TWSR_TWPS1);
#elif I2C_PRESCALER == I2C_PRESCALER_16
	/*Set Prescaler Values*/
	CLR_BIT(TWSR, TWSR_TWPS0);
	SET_BIT(TWSR, TWSR_TWPS1);
#elif I2C_PRESCALER == I2C_PRESCALER_64
	/*Set Prescaler Values*/
	SET_BIT(TWSR, TWSR_TWPS0);
	SET_BIT(TWSR, TWSR_TWPS1);
#endif

	/*Set TWBR with the Value =>100KHZ*/
	TWBR = I2C_TWBR_VALUE;

	/*Enable  I2C*/
	SET_BIT(TWCR,TWCR_TWEN);
}

void I2C_Slave_voidInit(u8 I2C_Address){
	/*Set Slave Address iN TWAR*/
	TWAR = I2C_Address;

#if I2C_ACK_MODE == ACK_ENABLE
	/*Enable  ACK*/
	Set_Bit(TWCR,TWCR_TWEA);
#elif I2C_ACK_MODE == ACK_DISABLE
	/*Disable  ACK*/
	Clear_Bit(TWCR,TWCR_TWEA);
#endif
	/*Enable I2C*/
	SET_BIT(TWCR, TWCR_TWEN);
}

I2C_Error_State I2C_Master_enuSendStartCond(void){
	I2C_Error_State state = NoError;

#if I2C_ACK_MODE == ACK_ENABLE
	/*Enable  ACK*/
	TWCR=(1<<TWCR_TWSTA)|(1<<TWCR_TWEA)|(1<<TWCR_TWEN)|(1<<TWCR_TWINT);
#elif I2C_ACK_MODE == ACK_DISABLE
	/*Disable  ACK*/
	TWCR=(1<<TWCR_TWSTA)|(1<<TWCR_TWEN)|(1<<TWCR_TWINT);
#endif

	/*Wait for the flag*/
	while(Get_Bit(TWCR,TWCR_TWINT) == 0);

	/*Check Status*/
	if((TWSR & 0xF8) != I2C_MTXCheckStart){
		state = ErrorStartCondition;
	}
	return state;
}

I2C_Error_State I2C_Master_enuSendRepeatedStartCond(void){
	I2C_Error_State state = NoError;

#if I2C_ACK_MODE == ACK_ENABLE
	/*Enable  ACK*/
	TWCR=(1<<TWCR_TWSTA)|(1<<TWCR_TWEA)|(1<<TWCR_TWEN)|(1<<TWCR_TWINT);
#elif I2C_ACK_MODE == ACK_DISABLE
	/*Disable  ACK*/
	TWCR=(1<<TWCR_TWSTA)|(1<<TWCR_TWEN)|(1<<TWCR_TWINT);
#endif
	/*Wait for the flag*/
	while(Get_Bit(TWCR,TWCR_TWINT) == 0);

	/*Check Status*/
	if((TWSR & 0xF8) != I2C_MTXCheckReStart){
		state = ErrorRestartCondition;
	}
	return state;
}


I2C_Error_State I2C_Master_enuSendSlaveAddressWithRead(u8 I2C_Address){
	I2C_Error_State state = NoError;

	/*Load the slave address*/
	TWDR = I2C_Address;
	/*Select the read mode*/
	SET_BIT(TWDR, 0);

#if I2C_ACK_MODE == ACK_ENABLE
	/*Enable  ACK*/
	TWCR=(1<<TWCR_TWEA)|(1<<TWCR_TWEN)|(1<<TWCR_TWINT);
#elif I2C_ACK_MODE == ACK_DISABLE
	/*Disable  ACK*/
	TWCR=(1<<TWCR_TWEN)|(1<<TWCR_TWINT);
#endif

	/*Wait for the flag*/
	while(Get_Bit(TWCR,TWCR_TWINT) == 0);

	/*Check Status*/
#if I2C_ACK_MODE == ACK_ENABLE
	if((TWSR & 0xF8) != I2C_MRXCheckSLA_R_WithAck){
		state = ErrorSlaveAddressReadWithAck;
	}
#elif  I2C_ACK_MODE == ACK_DISABLE
	if((TWSR & 0xF8) != I2C_MRXCheckSLA_R_WithOutAck){
		state = ErrorSlaveAddressReadWithoutAck;
	}
#endif
	return state;
}

I2C_Error_State I2C_Master_enuSendSlaveAddressWithWrite(u8 I2C_Address){
	I2C_Error_State state = NoError;
	/*Load the slave address*/
	TWDR = I2C_Address;

	/*Select the write mode*/
	CLR_BIT(TWDR, 0);

#if I2C_ACK_MODE == ACK_ENABLE
	/*Enable  ACK*/
	TWCR=(1<<TWCR_TWEA)|(1<<TWCR_TWEN)|(1<<TWCR_TWINT);
#elif I2C_ACK_MODE == ACK_DISABLE
	/*Disable  ACK*/
	TWCR=(1<<TWCR_TWEN)|(1<<TWCR_TWINT);
#endif

	/*Wait for the flag*/
	while(Get_Bit(TWCR,TWCR_TWINT) == 0);

	/*Check Status*/
#if I2C_ACK_MODE == ACK_ENABLE
	if((TWSR & 0xF8) != I2C_MTXCheckSLA_W_WithAck){
		state = ErrorSlaveAddressWriteWithAck;
	}
#elif  I2C_ACK_MODE == ACK_DISABLE
	if((TWSR & 0xF8) != I2C_MTXCheckSLA_W_WithOutAck){
		state = ErrorSlaveAddressWriteWithoutAck;
	}
#endif
	return state;
}


I2C_Error_State I2C_Master_enuSendu8Data(u8 I2C_Data){
	I2C_Error_State state = NoError;

	/*Load the data*/
	TWDR = I2C_Data;

#if I2C_ACK_MODE == ACK_ENABLE
	/*Enable  ACK*/
	TWCR=(1<<TWCR_TWEA)|(1<<TWCR_TWEN)|(1<<TWCR_TWINT);
#elif I2C_ACK_MODE == ACK_DISABLE
	/*Disable  ACK*/
	TWCR=(1<<TWCR_TWEN)|(1<<TWCR_TWINT);
#endif

	/*Wait for the flag*/
	while(Get_Bit(TWCR,TWCR_TWINT) == 0);

	/*Check Status*/
#if I2C_ACK_MODE == ACK_ENABLE
	if((TWSR & 0xF8) != I2C_MTXCheckData_WithAck){
		state = ErrorWriteDataWithAck;
	}
#elif  I2C_ACK_MODE == ACK_DISABLE
	if((TWSR & 0xF8) != I2C_MTXCheckData_WithOutAck){
		state = ErrorWriteDataWithoutAck;
	}
#endif
	return state;
}

I2C_Error_State I2C_Master_enuReadu8Data(u8* I2C_Data){
	if(I2C_Data != NULL){
		I2C_Error_State state = NoError;

#if I2C_ACK_MODE == ACK_ENABLE
		/*Enable  ACK*/
		TWCR=(1<<TWCR_TWEA)|(1<<TWCR_TWEN)|(1<<TWCR_TWINT);
#elif I2C_ACK_MODE == ACK_DISABLE
		/*Disable  ACK*/
		TWCR=(1<<TWCR_TWEN)|(1<<TWCR_TWINT);
#endif

		/*Wait for the flag*/
		while(Get_Bit(TWCR,TWCR_TWINT) == 0);

		/*Check Status*/
#if I2C_ACK_MODE == ACK_ENABLE
		if((TWSR & 0xF8) != I2C_MRXCheckData_WithAck){
			state = ErrorReadDataWithAck;
		}
#elif  I2C_ACK_MODE == ACK_DISABLE
		if((TWSR & 0xF8) != I2C_MRXCheckData_WithOutAck){
			state = ErrorReadDataWithoutAck;
		}
#endif
		*I2C_Data = TWDR;
		return state;
	}

	return -1;
}
I2C_Error_State I2C_Master_voidFlush(){
	I2C_Error_State state = NoError;

	/*Disable  ACK*/
	TWCR=(1<<TWCR_TWEN)|(1<<TWCR_TWINT);

	/*Wait for the flag*/
	while(Get_Bit(TWCR,TWCR_TWINT) == 0);

	/*Check Status*/
	if((TWSR & 0xF8) != I2C_MRXCheckData_WithOutAck){
		state = ErrorReadDataWithoutAck;
	}

	return state;
}

void I2C_Master_enuSendStopCond(void){
	TWCR=(1<<TWCR_TWSTO)|(1<<TWCR_TWEN)|(1<<TWCR_TWINT);

	/*Wait for the flag*/
	while(Get_Bit(TWCR,TWCR_TWSTO) == 1);

}

I2C_Error_State I2C_Slave_enuReadu8Data(u8* I2C_Data){

	return 0;
}
