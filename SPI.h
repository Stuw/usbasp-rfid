#pragma once
#include <Arduino.h>

#define SPISettings(a, b, c) 0
#define SPI_CLOCK_DIV4 0
#define MSFIRS 0
#define SPI_MODE0 0
#define LOW 0
#define HIGH 1
#define OUTPUT 0
#define INPUT 1

void pinMode(int pin, int mode);
int digitalRead(int pin);
void digitalWrite(int pin, int state);

class spi
{
	public:
		spi();
		virtual ~spi();

		void begin();
		void beginTransaction(int);
		byte transfer(byte v);
		void endTransaction();
};

extern spi SPI;
