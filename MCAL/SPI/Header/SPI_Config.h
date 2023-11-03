/*
 * SPI_Config.h
 *
 *  Created on: Oct 30, 2023
 *      Author: Hazim Emad
 */

#ifndef MCAL_SPI_HEADER_SPI_CONFIG_H_
#define MCAL_SPI_HEADER_SPI_CONFIG_H_

/*Enable SPI Interrupt Mode*/
/*
 * ENABLE_INTERRUPT
 * DISABLE_INTERRUPT
 *
 */

#define INTERRUPT_MODE ENABLE_INTERRUPT

/*SPI Data Order*/
/*
 * LSB_FIRST
 * MSB_FIRST
 *
 */

#define DATA_ORDER  LSB_FIRST

/*
 * Clock Polarity mode
 * IDLE_LOW >> leading edge is rising
 * IDLE_HIGH >> leading edge is falling
 *
 */
#define CLOCK_POLARITY  IDLE_LOW


/* Clock Phase Mode
 *
 * SPI_ZERO >> sample at leading and setup at trailing
 * SPI_ONE >> sample at trailing and setup at rising
 *
 */

#define CLOCK_PHASE SPI_ZERO


/* CLOCK
 *
 * QUARTER_FREQ
 * HALF_FREQ
 *
 */

#define SPI_FREQUENCY  QUARTER_FREQ




#endif /* MCAL_SPI_HEADER_SPI_CONFIG_H_ */
