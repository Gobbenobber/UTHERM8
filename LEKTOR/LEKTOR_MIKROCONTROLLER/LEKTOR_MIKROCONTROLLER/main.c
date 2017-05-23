#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000
#include <util/delay.h>

//Drivers
#include "SendOgModtag.h"

#define PINNR 0

//------------------------------------//
//				 Variables			  //
//------------------------------------//
volatile static int index = 0;
volatile unsigned char karakter = '\0';

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

	
	//------------------------------------//
	//			 interrupt test			  //
	//------------------------------------//
	DDRD &= ~(1 << DDD0);
	// PD2 (PCINT0 pin) is now an input
	PORTD |= (1 << PORTD0);
	// PD2 is now an input with pull-up enabled
	//EICRA |= (1 << ISC11) | (1 << ISC10);   // set INT0 to trigger on ANY logic change
	EICRA = 0b00000011;
	EIMSK |= (1 << INT0);
	//------------------------------------//

	DDRC |= (1 << 0);

	//Initializing
	UCSR0B = 0;
	DDRB |= (1 << PINNR);			//OUTPUT 

	// Global interrupt enable
	sei();

	while(1)
	{
		//ZEROCROSS TEST
		PORTC |= 1 << 0;
		_delay_ms(1);
		PORTC &= ~(1 << 0);
		_delay_ms(1);
		

	}
}

// Interrupt service routine for INT0 (Er INT3 for Atmega 2560)
ISR (INT0_vect)
{
	// Test Write
	//if (index == 0)
	//{
		//sendCharSW('a');
		//index++;
	//}
	//if (index == 1)
	//{
		//sendCharSW('b');
		//index++;
	//}
	//if (index == 2)
	//{
		//sendCharSW('c');
		//index = 0;
	//}
	sendCharSW('a');
	
}