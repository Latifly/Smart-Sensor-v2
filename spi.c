#include <avr/io.h>
#include "spi.h"


void SPI_SlaveInit(void)
{
	/* Set MISO output, all others input */
	DDR_SPI = (1<<DD_MISO);
	//PORTB |= (1<<PB2);
	/* Enable SPI */
	SPCR = (1<<SPE);
}
char SPI_SlaveReceive(char cData)
{
	/* Wait for reception complete */
	//
	SPDR= cData; // confirm to master already received
	while(!(SPSR & (1<<SPIF)));
	/* Return data register */
	return SPDR;
}
