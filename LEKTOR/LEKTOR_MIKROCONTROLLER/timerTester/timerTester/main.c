/*
 * timerTester.c
 *
 * Created: 23-05-2017 10:00:15
 * Author : Batuik
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
	while (1) 
    {

	setTimer();
	sei();

	returnerTimerStatus();

    }
}

