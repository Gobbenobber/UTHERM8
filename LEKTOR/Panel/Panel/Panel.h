#pragma once 
#define F_CPU 16000000
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

volatile static char condition = '1';

// Prototype for initialiseringen af porte 
void initPorts(); 

//Prototype for LED's modtager char {'A'-away, 'B'-busy & 'F'-free}
void setLED(char input);

//Prototype for interrupt 0, PD0
void initInterrupt();

// Prototype for initialer på display 
void setInitials(char* fN, char* lN, char portLetter);