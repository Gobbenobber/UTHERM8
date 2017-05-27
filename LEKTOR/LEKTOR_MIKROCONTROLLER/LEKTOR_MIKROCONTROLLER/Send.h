#pragma once
#define F_CPU 16000000
//Packages
#include "avr/interrupt.h"
#include "avr/io.h"
#include <util/delay.h>

//Local Constants

#define DDR   DDRB
#define PORT  PORTH
#define PINNR 6

// 8 data bit, no parity, 1 stop bit
void sendCharX10(char Tegn);
void sendBurst();
void sendNothing();
void ventPaaZC();
void opdaterKommando();
void initBurst();