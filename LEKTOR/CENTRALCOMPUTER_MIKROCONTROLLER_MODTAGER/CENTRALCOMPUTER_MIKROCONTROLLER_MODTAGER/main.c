#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000
#include <util/delay.h>

//------------------------------------//
//		 CENTRAL MIKROKONTROLLER      //
//------------------------------------//

//Drivers
#include "SendOgModtag.h"
#include "uart.h"

#define PINNR 0
#define PINNR_2 0

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

	unsigned char streng[3] = "";
	
	//------------------------------------//
	//			 interrupt test			  //
	//------------------------------------//
	DDRD &= ~(1 << DDD0);
	// PD2 (PCINT0 pin) is now an input
	PORTD |= (1 << 0);
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
	DDRA &= ~(1 << PINNR_2);		//INPUT

	// Global interrupt enable
	sei();

	while(1)
	{
		//switch (index)
		//{
			//case 1:
			//streng[0] = karakter;
			//break;
			//case 2:
			//streng[1] = karakter;
			//break;
			//case 3:
			//streng[2] = karakter;
			//index = 0;
			//break;
		//}
		//if ((streng[0] == 'a') && (streng[1] == 'b') && (streng[2] == 'c'))
		//{
			//PORTC |= 1 << 5;
		//}
		//else
		//{
			//PORTC &= ~(1 << 5);
		//}

		if (karakter == 'a')
		{
			PORTC |= 1 << 5;
		}
		else
		{
			PORTC &= ~(1 << 5);
		}

		SendString(streng);

	}
}

// Interrupt service routine for INT0 (Er INT3 for Atmega 2560)
ISR (INT0_vect)
{
	// Test Write
	//sendCharSW('a');

	// Test Read
	karakter = readCharSW();
	//index++;
}