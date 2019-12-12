/*
 * spi.h
 *
 *  Created on: Dec 11, 2019
 *      Author: Alatif
 */

#ifndef SPI_H_
#define SPI_H_

#include <avr/io.h>
#include <stdio.h>

#define DDR_SPI DDRB
#define DD_SS DDB0
#define DD_SCK DDB1
#define DD_MOSI DDB2
#define DD_MISO DDB3

void SPI_SlaveInit(void);
char SPI_SlaveReceive(char cData);

#endif /* SPI_H_ */
