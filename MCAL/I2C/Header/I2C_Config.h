/*
 * I2C_Config.h
 *
 *  Created on: Oct 31, 2023
 *      Author: Hazim Emad
 */

#ifndef MCAL_I2C_HEADER_I2C_CONFIG_H_
#define MCAL_I2C_HEADER_I2C_CONFIG_H_

/*
The I2C_TWBR_VALUE should be > 10 if in master mode
I2C Freq=(F_CPU)/(16+2T)
*/
#define     I2C_TWBR_VALUE        72 //72 for 100kHz, 12 for 400kHz

/*
I2C_ACK_MODE can be: (Master/Slave)
              ACK_ENABLE
              ACK_DISABLE
*/
#define     I2C_ACK_MODE          ACK_ENABLE

/*
I2C_PRESCALER can be: (Master/Slave)
              I2C_PRESCALER_1
              I2C_PRESCALER_4
              I2C_PRESCALER_16
              I2C_PRESCALER_64
*/
#define    I2C_PRESCALER          I2C_PRESCALER_1


#endif /* MCAL_I2C_HEADER_I2C_CONFIG_H_ */
