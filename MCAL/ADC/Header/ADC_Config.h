/*
 * ADC_Config.h
 *
 *  Created on: Oct 23, 2023
 *      Author: Hazim Emad
 */

#ifndef MCAL_ADC_HEADER_ADC_CONFIG_H_
#define MCAL_ADC_HEADER_ADC_CONFIG_H_


/****************************************************************/
/** !comment : Please Enter the Voltage Reference				*/
/** 		   VOLTAGE_REFERENCE can be : 						*/
/*					    					AREF 				*/
/*						    				AVCC 				*/
/*							    			INTERNAL			*/
/****************************************************************/

#define VOLTAGE_REFERENCE			ADC_AVCC



/****************************************************************/
/** !comment : Please Enter the ADJUSTMENT						*/
/** 		   ADJUSTMENT can be : 								*/
/*					    					RIGHT_ADJUSTMENT	*/
/*							    			LEFT_ADJUSTMENT		*/
/****************************************************************/
/****************************************************************/
/** NOTE	 : The preferred adjustment for a 8 bits Resolution	*/
/*				is LEFT_ADJUSTMENT and for a 10 bits Resolution	*/
/*				is RIGHT_ADJUSTMENT								*/
/****************************************************************/

#define ADJUSTMENT				RIGHT_ADJUSTMENT

#define ADC_AUTO_TRIGGER_SOURCE		NORMAL_MODE

#define ADC_PRESCALLER				DIVISION_BY_128

#define ADC_AREF_VALUE					2.56f

#endif /* MCAL_ADC_HEADER_ADC_CONFIG_H_ */
