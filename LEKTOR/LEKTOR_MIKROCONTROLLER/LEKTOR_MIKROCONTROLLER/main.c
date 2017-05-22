#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000
#include <util/delay.h>

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

/*
void initExtInt(int interruptnr)
{
	// INT2:Rising edge
	if (interruptnr==0)
	{
		EICRA=0b00000011;
		EIMSK |= 0b00000001;
	}
	
	else if(interruptnr==1)
	{
		EICRA=0b00001100;
		EIMSK |= 0b00000010;
	}
	
	else if (interruptnr==2)
	{
		EICRA=0b00110000;
		EIMSK |= 0b00000100;
	}
	
	else if(interruptnr==3)
	{
		EICRA=0b11000000;
		EIMSK |= 0b00001000;
	}
	
}
*/
// 8 data bit, no parity, 1 stop bit
void SendCharSW(char Tegn)
{
	// Main-loop: Toggle LED7 hvert sekund
	unsigned char i;
	unsigned char x = Tegn;
	// Start bit
	PORT &= ~(1<<PINNR);
	_delay_us(NO_us);
	// 8 data bits (LSB first)
	for (i = 0; i<8; i++)
	{
		if(x & 0b00000001)
		PORT |= (1<<PINNR);
		else
		PORT &= ~(1<<PINNR);
		_delay_us(NO_us);
		x = x>>1;
	}
	PORT |= (1<<PINNR);
	_delay_us(NO_us);
	//Test ###DUNNO what the stopbit is###
	PORT &= ~(1<<PINNR);
}
// 8 data bit, no parity, 1 stop bit
char ReadCharSW()
{
	unsigned char i;
	unsigned char x = PINNR_2;
	unsigned char out = '0';
	_delay_us(NO_us);
	
	//STARTBIT
	if (PINNR_2 != 0);
	{
		//Data
		for (i = 8; i > 0; --i)
		{
			x = PINNR_2;
			if (PINNR_2 != 0)
			{
				out |= 1 << i;
			}
			else
			{
				out &= ~(1 << i);
			}
			_delay_us(NO_us);
		}
	}
	if (PINNR_2 == 0)
	{
		_delay_us(NO_us);
		printf("ERROR! STOPBIT IS FUKT");
	}
	_delay_us(NO_us);
}

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
	unsigned char* streng = "000";
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
			streng[i] = karakter;
		}

		//testOutput
		printf("%s\n", streng);
		if (streng == "aaa")
		{
			PORTB = 255;
		}
	}
}

// Interrupt service routine for INT0 (Er INT3 for Atmega 2560)
ISR (INT0_vect)
{
	// Test Write
	SendCharSW('a');

	// Test Read
	karakter = ReadCharSW();
}