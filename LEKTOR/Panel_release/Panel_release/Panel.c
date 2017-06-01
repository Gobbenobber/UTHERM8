#include "Panel.h"

void initPorts()
{
	DDRB |= (1 << PINB0) | (1 << PINB1) | (1 << PINB2) | (1 << PINB3);	//Using portB {0,1}
	DDRA = 0xFF;
	DDRC = 0xFF;
	//DDRH |= (1 << PINH0);	//Using portD {0,1}
	//DDRH |= (1 << PINH1);

}

void setLED(char input)
{
	switch (input)
	{
		case 'A':
		PORTB &= ~(1 << 2);
		PORTB &= ~(1 << 3);
		break;
		case 'B':
		PORTB |= (1 << 2);
		PORTB |= (1 << 3);
		break;
		case 'F':
		PORTB &= ~(1 << 2);
		PORTB |= (1 << 3);
		break;
		default:
		break;
	}
}

void initInterrupt()
{
	DDRD &= ~(1 << 0);
	// PD2 (PCINT0 pin) is now an input
	PORTD |= (1 << 0);
	// PD2 is now an input with pull-up enabled
	//EICRA |= (1 << ISC11) | (1 << ISC10);   // set INT0 to trigger on ANY logic change
	EICRA = 0b00000011;
	EIMSK |= (1 << INT0);
	//------------------------------------//

	////Making the zero-cross
	//DDRC |= (1 << 0);

	//Initializing
	UCSR0B = 0;
	
	// Global interrupt enable
	sei();
}

void setInitials(char* fN, char* lN, char portLetter)
{
	condition = '1';
	do{
		if (portLetter == 'A') //Hvis man ønsker at ændre navnet på første initial på en lektor connected til portA
		{
			PORTB |= 0b11111101;
			switch(fN[0]) //Hvis det første bogstav i fornavnet er:
			{
				case 'A':		//A
				PORTA |= 0b11111010;
				break;
				case 'B':		//b
				PORTA |= 0b00111110;
				break;
				case 'C':		//C
				PORTA |= 0b01100110;
				break;
				case 'D':
				PORTA |= 0b11101110;
				break;
				case 'E':
				PORTA |= 0b11101110;
				break;
				case 'F':
				PORTA |= 0b01110010;
				break;
				case 'G':
				PORTA |= 0b11111100;
				break;
				case 'H':
				PORTA |= 0b10111010;
				break;
			}
			
			_delay_us(10);		// Delay på 10us
			PORTA = 0b00000000; // Reset PORTA
			PORTB &= 0b0000100; // Reset PORTB
			PORTB |= 0b1111110; // Sætter pin 3 til udgang
			
			switch(lN[0])
			{
				case 'A':
				PORTA |= 0b11111010;
				break;
				case 'B':
				PORTA |= 0b00111110;
				break;
				case 'C':
				PORTA |= 0b01100110;
				break;
				case 'D':
				PORTA |= 0b11101110;
				break;
				case 'E':
				PORTA |= 0b01110110;
				break;
				case 'F':
				PORTA |= 0b01110010;
				break;
				case 'G':
				PORTA |= 0b11111100;
				break;
				case 'H':
				PORTA |= 0b10111010;
				break;
			}
			
			_delay_us(10);
			PORTA = 0b00000000; // Reset PORTA
			PORTB &= 0b0001000; // Reset PORTB
		}
		else if (portLetter == 'C')
		{
			PORTB |= 0b11110111;
			switch(fN[0])
			{
				case 'A':
				PORTC |= 0b11111010;
				break;
				case 'B':
				PORTC |= 0b00111110;
				break;
				case 'C':
				PORTC |= 0b01100110;
				break;
				case 'D':
				PORTC |= 0b11101110;
				break;
				case 'E':
				PORTC |= 0b11101110;
				break;
				case 'F':
				PORTC |= 0b01110010;
				break;
				case 'G':
				PORTC |= 0b11111100;
				break;
				case 'H':
				PORTC |= 0b10111010;
				break;
			}
			_delay_us(10);
			PORTC = 0b00000000; // Reset PORTA
			PORTB &= 0b0001000; // Reset PORTB
			PORTB |= 0b1111011; // Sætter PORTB som udgang
			
			switch(lN[0])
			{
				case 'A':
				PORTC |= 0b11111010;
				break;
				case 'B':
				PORTC |= 0b00111110;
				break;
				case 'C':
				PORTC |= 0b01100110;
				break;
				case 'D':
				PORTC |= 0b11101110;
				break;
				case 'E':
				PORTC |= 0b01110110;
				break;
				case 'F':
				PORTC |= 0b01110010;
				break;
				case 'G':
				PORTC |= 0b11111100;
				break;
				case 'H':
				PORTC |= 0b10111010;
				break;
			}

			_delay_us(10);
			PORTC = 0b00000000; // Reset PORTC
			PORTB &= 0b0000100; // Reset PORTB
		}
	} while(condition == '1');
}

ISR (INT0_vect)
{
	if (condition == '1')
	{
		condition = '0';
	}
	else
	{
		condition = '1';
	}
}