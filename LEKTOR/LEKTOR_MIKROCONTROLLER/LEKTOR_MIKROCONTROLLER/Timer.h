///////////////////////////////////////////////////////////////
///							- Timer -						///
///				 Af Susanne, Patrick og Kasper				///
///		Denne klasse har til opgave at lave en timer		///
///////////////////////////////////////////////////////////////

#include "avr/interrupt.h"
#include "avr/io.h"

#ifndef TIMER_H_
#define TIMER_H_

//Variables
volatile int ctr_ = 0;
volatile int timerStatus_ = 0;

//Functions
int returnerTimerStatus();
void setTimer();
void resetTimer();
void timerStatus();

#endif /* TIMER_H_ */