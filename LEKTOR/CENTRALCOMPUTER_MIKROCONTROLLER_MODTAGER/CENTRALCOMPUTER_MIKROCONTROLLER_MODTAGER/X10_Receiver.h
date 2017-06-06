/*
 * IncFile1.h
 *
 * Created: 26-05-2017 01:04:17
 *  Author: Batuik
 */ 

#pragma once
#include "avr/interrupt.h"
#include "avr/io.h"

// 8 data bit, no parity, 1 stop bit
void start1msDelay();
void start100usDelay();
unsigned char* receiveX10Message();
void ventPaaZC();