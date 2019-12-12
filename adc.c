/*
 * adc.c
 *
 *  Created on: Dec 11, 2019
 *      Author: Alatif
 */

#include  <avr/io.h>
#include  "adc.h"
#include  "spi.h"

void ADC_Init(){
	ADCSRA |= (1<<ADATE); //ADC trigger enable
	ADCSRA |= (1<<ADPS2) | (1<<ADPS1); //prescaller 64
	ADCSRB &=~(_BV(ADTS2)|_BV(ADTS1)|_BV(ADTS0)); //free running
	ADMUX  |= (1<<REFS0); //referensi vcc
//	ADMUX  |= (1<<ADLAR);
	ADCSRA |= (1<<ADEN); //ADC enable
	ADCSRA |= (1<<ADSC); //ADC start konversi
	ADMUX &=~ (0x1F);
}

void ADC_Read(uint8_t mux, uint8_t *hasil_low, uint8_t *hasil_high, uint16_t *hasil ){
	ADMUX &=~ (0x1F);
	ADMUX |= (mux);
	//data=((ADCH<<2)|(ADCL>>6));
	//return data;
	data1 = ADCL;
	data2 = ADCH;
	*hasil_low=data1;
	*hasil_high=data2;
	*hasil = data2*256 + data1;


}

