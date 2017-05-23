#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000
#include <util/delay.h>

//Drivers
#include "SendOgModtag.h"


// Prototyper
void initExtInts(int interruptnr);

#define DDR   DDRB
#define PORT PORTB
#define PINNR 0
#define PINNR_2 8
#define BAUD  9600

#define NO_us 80000/BAUD

//------------------------------------//
//				 Variables			  //
//------------------------------------//
volatile static int outputShizzle = 1;
volatile static unsigned char karakter = '0';


//------------------------------------//
//				 Functions			  //
//------------------------------------//
//Enable interrupt (disabled)

int main(void)
{
	//------------------------------------//
	//			 interrupt test			  //
	//------------------------------------//
	DDRD &= ~(1 << DDD2);     // Clear the PD2 pin (Nr. 2)
	// PD2 (PCINT0 pin) is now an input

	PORTD |= (1 << PORTD2);    // turn On the Pull-up
	// PD2 is now an input with pull-up enabled

	//EICRA |= (1 << ISC11) | (1 << ISC10);   // set INT0 to trigger on ANY logic change
	EICRA = 0b00000011;
	EIMSK |= (1 << INT0);     // Turns on INT0
	//------------------------------------//

	//TEST AF PIN
	DDRC |= 1 << 0;

	//Initializing
	//unsigned char* streng = "000";
	UCSR0B = 0;
	DDR |= (1<<PINNR);
	DDR |= (1 << PINNR_2);

	// Global interrupt enable
	sei();

	while(1)
	{
		//ZEROCROSS TEST
		PORTC |= 1 << 0;
		_delay_ms(1);
		PORTC &= ~(1 << 0);
		_delay_ms(1);

		for (int i = 0; i < 3; i++)
		{
			//streng[i] = karakter;
		}

		//testOutput
		//if (streng == "aaa")
		//{
			//PORTB = 255;
		//}



	}
}

// Interrupt service routine for INT0 (Er INT3 for Atmega 2560)
ISR (INT0_vect)
{
	// Test Write
	SendCharSW('a');

	// Test Read
	//karakter = ReadCharSW();
}