/*
 * uart.h
 *
 *  Created on: Dec 12, 2019
 *      Author: Alatif
 */

#ifndef UART_H_
#define UART_H_

#include <avr/io.h>

#define UART_BAUD_RATE 9600
#define VBAUDRATE (((F_CPU / (UART_BAUD_RATE * 16UL))) - 1)
#define BAUDH VBAUDRATE / 256
#define BAUDL VBAUDRATE % 256

void USART_Init(void);
unsigned char USART_GetChar(void);
void USART_PutChar(unsigned char data);
void USART_PutStr(char *text);
void USART_PutNum(int16_t number);


#endif /* UART_H_ */
