/*
 * I2C_Private.h
 *
 *  Created on: Oct 31, 2023
 *      Author: Hazim Emad
 */

#ifndef MCAL_I2C_HEADER_I2C_PRIVATE_H_
#define MCAL_I2C_HEADER_I2C_PRIVATE_H_

#define     ACK_ENABLE            0
#define     ACK_DISABLE           1

#define     I2C_PRESCALER_1   1
#define     I2C_PRESCALER_4   4
#define     I2C_PRESCALER_16  16
#define     I2C_PRESCALER_64  64

/*TWI_Master Transmit Check */
#define I2C_MTXCheckStart         				0x08
#define I2C_MTXCheckReStart       				0x10
#define I2C_MTXCheckSLA_W_WithAck       		0x18
#define I2C_MTXCheckSLA_W_WithOutAck    	   	0x20
#define I2C_MTXCheckData_WithAck       			0x28
#define I2C_MTXCheckData_WithOutAck       		0x30
#define I2C_MTXCheckLostArbitration   			0x38

#define I2C_MRXCheckSLA_R_WithAck           	0x40
#define I2C_MRXCheckSLA_R_WithOutAck           	0x48

#define I2C_MRXCheckData_WithAck             	0x50
#define I2C_MRXCheckData_WithOutAck           	0x58

#endif /* MCAL_I2C_HEADER_I2C_PRIVATE_H_ */
