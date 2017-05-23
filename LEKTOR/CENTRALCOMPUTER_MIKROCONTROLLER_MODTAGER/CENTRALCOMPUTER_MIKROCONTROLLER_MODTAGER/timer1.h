/*
 * timer1.h
 *
 * Created: 13-12-2016 10:53:07
 *  Author: Batuik
 */ 

#pragma once

void T1Delay(int delay_ms); // MAX 262 MS DELAY!!! - Default 10 ms.











/***************************************
* MSYS, LAB 10                         *
* Using external and timer interrupts. *
*                                      *
* SWITCHES connected to PA pins.       *
* LEDs connected to PB pins.           *
*                                      *
* Henning Hargaard 17/5 2016           *
****************************************/
#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000
#include <util/delay.h>

// Prototyper
void initExtInts();
void initTimer0();
void initTimer1();

// Global variabel, der tæller antal Timer0 overflows (bemærk: SKAL erklæres volatile)
volatile unsigned int antal_overflows = 0;

//--------------------------------------

int main()
{

}

//--------------------------------------

// Interrupt service rutine for INT2
ISR (INT2_vect)
{
	toggleLED(2);
}

// Interrupt service rutine for INT3
ISR (INT3_vect)
{
	toggleLED(3);
}

// Interrupt service rutine for Timer0 overflow
ISR(TIMER0_OVF_vect)
{
	// LED6 toggles, når der har vaeret 62500 interrupts
	// = hvert sekund, da 16000000/1/256 = 1
	antal_overflows++;
	if (antal_overflows == 62500)
	{
		toggleLED(6);
		antal_overflows = 0;
	}
}

// Interrupt service rutine for Timer1 Compare Match (A-system)
ISR (TIMER1_COMPA_vect)
{
	toggleLED(5);
}

//--------------------------------------

void initExtInts()
{
	// INT2:Falling edge, INT3:Rising edge
	EICRA = 0b11100000;
	// Enable extern interrupts INT2 og INT3
	EIMSK |= 0b00001100;
}

void initTimer0()
{
	// Timer0: Normal mode, PS = 1 (= "No prescaling")
	TCCR0A = 0b00000000;
	TCCR0B = 0b00000001;
	// Enable Timer0 overflow interrupt
	TIMSK0 |= 0b00000001;
}