#pragma once
#define F_CPU 16000000
//Packages
#include "avr/interrupt.h"
#include "avr/io.h"
#include <util/delay.h>

//Local Constants

#define NO_us 80000/BAUD
#define DDR   DDRB
#define PORT  PORTB
#define PINNR 0
#define BAUD  9600


// 8 data bit, no parity, 1 stop bit
void sendCharSW(char Tegn);
void sendBurst();
void sendNothing();
void ventPaaZC();
void opdaterKommando();