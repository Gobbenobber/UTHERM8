#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000
#include <util/delay.h>

//Drivers
#include "SendOgModtag.h"

#define PINNR 0
#define PINNR_2 1

//------------------------------------//
//				 Variables			  //
//------------------------------------//
volatile static int outputShizzle = 1;
volatile static char karakter = '0';

/*
//------------------------------------//
//				 Functions			  //
//------------------------------------//
*/

int main(void)
{
	//------------------------------------//
	//			Variables(in scope)		  //
	//------------------------------------//
	unsigned char streng[3] = "000";
	
	//------------------------------------//
	//			 interrupt test			  //
	//------------------------------------//
	DDRD &= ~(1 << DDD2);
	// PD2 (PCINT0 pin) is now an input
	PORTD |= (1 << PORTD2);
	// PD2 is now an input with pull-up enabled
	//EICRA |= (1 << ISC11) | (1 << ISC10);   // set INT0 to trigger on ANY logic change
	EICRA = 0b00000011;
	EIMSK |= (1 << INT0);
	//------------------------------------//

	//TEST AF PIN
	DDRC |= 1 << 0;

	//Test LED
	DDRC |= 1 << 5;

	//Initializing
	UCSR0B = 0;
	DDRB |= (1 << PINNR);			//OUTPUT 
	DDRB |= (1 << PINNR_2);		//INPUT

	// Global interrupt enable
	sei();

	while(1)
	{
		//ZEROCROSS TEST
		PORTC |= 1 << 0;
		_delay_ms(1);
		PORTC &= ~(1 << 0);
		_delay_ms(1);
		
		//test LED
		//PORTC |= 1 << 5; Redundant

		for (int i = 0; i < 3; i++)
		{
			//Receive
			streng[i] = karakter;
		}

		//testOutput
		if ((streng[0] == 'a') && (streng[1] == 'a') && (streng[2] == 'a'))
		{
			PORTB = 255;
		}

	}
}

// Interrupt service routine for INT0 (Er INT3 for Atmega 2560)
ISR (INT0_vect)
{
	// Test Write
	//sendCharSW('a');

	// Test Read
	karakter = readCharSW();
}