/*
 * adc.h
 *
 *  Created on: Dec 11, 2019
 *      Author: Alatif
 */

#ifndef ADC_H_
#define ADC_H_

void ADC_Init();

void ADC_Read(uint8_t mux, uint8_t *hasil_low, uint8_t *hasil_high, uint16_t *hasil);
uint16_t data1, data2;

#endif /* ADC_H_ */
