/*
 * smartSensor.c
 *
 *  Created on: Dec 11, 2019
 *      Author: Alatif
 */
#include "smartSensor.h"
#include "uart.h"

unsigned char address='B';
unsigned char kirim='0';
uint8_t slow[3]={0,0,0};
uint8_t shigh[3]={0,0,0};
uint16_t sensor[3]={0,0,0};
uint16_t smin[3]={1024,1024,1024};
uint16_t smax[3]={0,0,0};
uint16_t sthres[3];
uint8_t sfix=0x00;
uint8_t selow;
_Bool sdig[3];
char sdec;

void smartSensor_run(void){
	address=SPI_SlaveReceive(kirim);

	switch(address){
	case 0x00:{
		kirim=0xFF;
	}break;

	case 0x10:{				//sensor 0 ADCL
		ADC_Read(0, &selow, 0, 0);
		kirim=selow;
	}break;

	case 0x11:{				//sensor 0 ADCH
		ADC_Read(0, 0, &shigh[0], 0);
		kirim=shigh[0];
	}break;

	case 0x12:{				//sensor 1 ADCL
		ADC_Read(1, &slow[1], 0, 0);
		kirim=slow[1];
	}break;

	case 0x13:{				//sensor 1 ADCH
		ADC_Read(1, 0, &shigh[1], 0);
		kirim=shigh[1];
	}break;

	case 0x14:{				//sensor 2 ADCL
		ADC_Read(2, &slow[2], 0, 0);
		kirim=slow[2];
	}break;

	case 0x15:{				//sensor 2 ADCH
		ADC_Read(2, 0, &shigh[2], 0);
		kirim=shigh[2];
	}break;

	case 0x37:{				//kalibrasi
		smartSensor_kalibrasi();
		kirim=0xFF;
	}break;

//	case default:{
//		kirim=0xFF;
//	}


	}
}


void smartSensor_kalibrasi(void){
	smartSensor_read_analog();

	for(int i=0; i<3; i++){
		if(sensor[i]<smin[i])
			smin[i]=sensor[i];
		if (sensor[i]>smax[i])
			smax[i]=sensor[i];

		sthres[i]=(smax[i]+smin[i])/2;
	}
}

void smartSensor_read_analog(void){
	for(int i=0; i<3;i++){
	    ADC_Read(i, 0, 0, &sensor[i]);
	    }
}

void smartSensor_read_digital(void){
	smartSensor_read_analog();
	for(int i=0; i<3;i++){
		if(sensor[i]>sthres[i])
			sdig[i]=1;
		else
			sdig[i]=0;
	}
	sfix=(sdig[2]*4)+(sdig[1]*2)+sdig[0];
}

void smartSensor_decision(void){
    smartSensor_read_digital();

    switch (sfix)
    {
    case 0b000: sdec='-'; break;
    case 0b010: sdec='I'; break;
    case 0b011: sdec='R'; break;
    case 0b110: sdec='L'; break;
    case 0b111: sdec='+'; break;
    }
}
