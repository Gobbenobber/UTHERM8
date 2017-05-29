/*
 * zeroCrossDetector.c
 *
 * Created: 24-05-2017 15:45:02
 *  Author: Batuik
 */ 
#include "zeroCrossDetector.h"
#include "avr/io.h"
#include "avr/interrupt.h"

 void initZCDetector()
 {
	 //------------------------------------//
	 //			 interrupt test			  //
	 //------------------------------------//
	 DDRD &= ~(1 << 0);
	 // PD2 (PCINT0 pin) is now an input
	 PORTD |= (1 << 0);
	 // PD2 is now an input with pull-up enabled
	 //EICRA |= (1 << ISC11) | (1 << ISC10);   // set INT0 to trigger on ANY logic change
	 EICRA = 0b00000011;
	 EIMSK |= (1 << 0);
	 //------------------------------------//

 }

 // Interrupt service routine for INT0 (Er INT3 for Atmega 2560)
 ISR(INT0_vect)
 {
	 ZCDetected_ = 1;
 }