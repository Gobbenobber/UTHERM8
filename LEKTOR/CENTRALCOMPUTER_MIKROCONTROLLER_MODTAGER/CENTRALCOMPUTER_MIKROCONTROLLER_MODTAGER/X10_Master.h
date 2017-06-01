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
#define DDR   DDRH
#define PORT  PORTH
#define PINNR 6
volatile unsigned char COMMAND;
volatile char aendring_;
unsigned char receive[6];

// 8 data bit, no parity, 1 stop bit
char validateStartByte(char val);
void start500usDelay();
void start1msDelay();
void start400usDelay();
unsigned char* receiveBurst();
void ventPaaZC();
void initBurst();