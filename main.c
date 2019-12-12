/*
 * main.c
 *
 *  Created on: Dec 11, 2019
 *      Author: Alatif
 */
#include <avr/io.h>
#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <util/delay.h>
#include "uart.h"
#include "spi.h"
#include "smartSensor.h"

//uint8_t slow;
uint16_t full;

int main(){
	SPI_SlaveInit();
	ADC_Init();
//	USART_Init();

	while(1){
//		SPI_SlaveReceive(0x01);
		smartSensor_run();
//		ADC_Read(0,&slow,0,&full);
//		USART_PutNum(slow);
//		USART_PutStr("---\n");
	}
}
