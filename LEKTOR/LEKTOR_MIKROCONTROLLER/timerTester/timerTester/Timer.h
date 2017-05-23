

///////////////////////////////////////////////////////////////
///							- Timer -						///
///				 Af Susanne, Patrick og Kasper				///
///		Denne klasse har til opgave at lave en timer		///
///////////////////////////////////////////////////////////////

#pragma once
#include "avr/interrupt.h"
#include "avr/io.h"

//Variables
volatile int ctr_ = 0;
volatile int timerStatus_ = 0;

//Functions
int returnerTimerStatus();
void setTimer();
void resetTimer();
void timerStatus();
