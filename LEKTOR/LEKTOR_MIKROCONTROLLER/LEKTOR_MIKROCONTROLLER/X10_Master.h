/*
 * IncFile1.h
 *
 * Created: 26-05-2017 01:04:17
 *  Author: Batuik
 */ 

#pragma once
#include "avr/interrupt.h"
#include "avr/io.h"
#define LEKTORID1 'A'
#define LEKTORID2 'A'
#define STARTCODE = 0b11101110
#define DDR   DDRB
#define PORT  PORTH
#define PINNR 6
volatile unsigned char COMMAND;
volatile char aendring_;

// 8 data bit, no parity, 1 stop bit
void sendCharX10(char Tegn);
void sendBurst();
void sendNothing();
void ventPaaZC();
void opdaterKommando();
void initBurst();
void opdaterKommando();