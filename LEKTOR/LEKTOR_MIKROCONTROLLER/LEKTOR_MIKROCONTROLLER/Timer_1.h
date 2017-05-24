///////////////////////////////////////////////////////////////
///						  - Timer1 -						///
///				 Af Susanne, Patrick og Kasper				///
///		Denne klasse har til opgave at lave en timer		///
///////////////////////////////////////////////////////////////

#pragma once
#include "avr/interrupt.h"
#include "avr/io.h"

//Variables
volatile static int ctr_ = 0;
volatile static int timerStatus_ = 0;

//Functions
int returnerTimerStatus();
void setTimer();
void resetTimer();
void timerStatus();
