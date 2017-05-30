/*
	Implementeringsfil for ToggleSwitch.h
 */ 

#include "ToggleSwitch.h"
//Variables
volatile char tilstand_;
static char register_;
static short int pin_;

void initToggleSwitch(char register__, short int pin)
{
 	if (register__ > 'L' || register__ < 'A' || register__ == 'I')
 	{
	 	register_ = 'A';
 	}
	else
	{
		register_ = register__;
	}
 	if (pin > 7)
 	{
	 	pin_ = 1;
 	}
	else
	{
		pin_ = pin;
	}
 	
 	switch (register_)
 	{
	 	case 'A':
	 	DDRA &= ~(1 << pin_);
	 	break;
	 	case 'B':
	 	DDRB &= ~(1 << pin_);
	 	break;
	 	case 'C':
	 	DDRC &= ~(1 << pin_);
	 	break;
	 	case 'D':
	 	DDRD &= ~(1 << pin_);
	 	break;
	 	case 'E':
	 	DDRE &= ~(1 << pin_);
	 	break;
	 	case 'F':
	 	DDRF &= ~(1 << pin_);
	 	break;
	 	case 'G':
	 	DDRG &= ~(1 << pin_);
	 	break;
	 	case 'H':
	 	DDRH &= ~(1 << pin_);
	 	break;
	 	case 'J':
	 	DDRJ &= ~(1 << pin_);
	 	break;
	 	case 'K':
	 	DDRK &= ~(1 << pin_);
	 	break;
	 	case 'L':
	 	DDRL &= ~(1 << pin_);
	 	break;
 	}

}

char toggleSwitchStatus()
{
	switch (register_)
	{
		case 'A':
		
		if (PINA & (1 << pin_))
		{
			tilstand_ = '1';
			return tilstand_;
		}
		else 		
		{
			tilstand_ = '0';
			return tilstand_;
		}
		break;

		case 'B':
		if (PINB & (1 << pin_))
		{
			tilstand_ = '1';
			return tilstand_;
		}
		else 		
		{
			tilstand_ = '0';
			return tilstand_;
		}
		break;

		case 'C':
		if (PINC & (1 << pin_))
		{
			tilstand_ = '1';
			return tilstand_;
		}
		else 		
		{
			tilstand_ = '0';
			return tilstand_;
		}
		break;

		case 'D':
		if (PIND & (1 << pin_))
		{
			tilstand_ = '1';
			return tilstand_;
		}
		else 		
		{
			tilstand_ = '0';
			return tilstand_;
		}
		break;

		case 'E':
		if (PINE & (1 << pin_))
		{
			tilstand_ = '1';
			return tilstand_;
		}
		else 		
		{
			tilstand_ = '0';
			return tilstand_;
		}
		break;

		case 'F':
		if (PINF & (1 << pin_))
		{
			tilstand_ = '1';
			return tilstand_;
		}
		else 		
		{
			tilstand_ = '0';
			return tilstand_;
		}
		break;

		case 'G':
		if (PING & (1 << pin_))
		{
			tilstand_ = '1';
			return tilstand_;
		}
		else 		
		{
			tilstand_ = '0';
			return tilstand_;
		}
		break;

		case 'H':
		if (PINH & (1 << pin_))
		{
			tilstand_ = '1';
			return tilstand_;
		}
		else 		
		{
			tilstand_ = '0';
			return tilstand_;
		}
		break;

		case 'J':
		if (PINJ & (1 << pin_))
		{
			tilstand_ = '1';
			return tilstand_;
		}
		else 		
		{
			tilstand_ = '0';
			return tilstand_;
		}
		break;

		case 'K':
		if (PINK & (1 << pin_))
		{
			tilstand_ = '1';
			return tilstand_;
		}
		else 		
		{
			tilstand_ = '0';
			return tilstand_;
		}
		break;

		case 'L':
		if (PINL & (1 << pin_))
		{
			tilstand_ = '1';
			return tilstand_;
		}
		else 		
		{
			tilstand_ = '0';
			return tilstand_;
		}
		break;
		default: return '0';
	}
}