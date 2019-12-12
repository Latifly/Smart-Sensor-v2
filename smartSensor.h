/*
 * smartSensor.h
 *
 *  Created on: Dec 11, 2019
 *      Author: Alatif
 */

#ifndef SMARTSENSOR_H_
#define SMARTSENSOR_H_

#include <stdint.h>
#include "adc.h"
#include "spi.h"

void smartSensor_run(void);
void smartSensor_kalibrasi(void);
void smartSensor_read_analog(void);
void smartSensor_read_digital(void);
void smartSensor_decision(void);


#endif /* SMARTSENSOR_H_ */
