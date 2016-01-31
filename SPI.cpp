#include "SPI.h"
#include <Arduino.h>
#include <usbasp/usbasp_spi.h>


void pinMode(int pin, int mode) { (void)pin; (void)mode; }
int digitalRead(int pin) { (void)pin; return HIGH; }
void digitalWrite(int pin, int state) { (void)pin; (void)state; }

spi::spi()
{
	usbasp_init();
	usbasp_spi_begin();
}

spi::~spi()
{
	usbasp_spi_end();
	usbasp_close();
}

void spi::begin()
{
	usbasp_spi_begin();
}

void spi::beginTransaction(int) { usbasp_spi_nss(LOW); }
byte spi::transfer(byte v) { return usbasp_spi_send(v); }
void spi::endTransaction() { usbasp_spi_nss(HIGH); }


spi SPI;
