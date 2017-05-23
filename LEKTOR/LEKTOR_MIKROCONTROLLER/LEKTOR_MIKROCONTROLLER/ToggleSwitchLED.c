/*
	Implementeringsfil for ToggleSwitchLED.h
 */ 

 #include "ToggleSwitchLED.h"

 void initToggleSwitchLED(char register_, short int port)
 {
	if (register_ >= 'E' || register_ <= 'A' || register_ == 'I')
	{
		register__ = 'B';
	}
	if (port > 7 || port < 0)
	{
		port__ = 1;
	}

	//sæt given pin til output

	switch (register__)
	{
	//case 'A':
	//DDRA |= (1 << port__);
	//break;
	case 'B':
	DDRB |= (1 << port__);
	break;
	case 'C':
	DDRC |= (1 << port__);
	break;
	case 'D':
	DDRD |= (1 << port__);
	break;
	//case 'E':
	//DDRE |= (1 << port__);
	//break;
	//case 'F':
	//DDRF |= (1 << port__);
	//break;
	//case 'G':
	//DDRG |= (1 << port__);
	//break;
	//case 'H':
	//DDRH |= (1 << port__);
	//break;
	//case 'J':
	//DDRJ |= (1 << port__);
	//break;
	//case 'K':
	//DDRK |= (1 << port__);
	//break;
	//case 'L':
	//DDRL |= (1 << port__);
	//break;
	}
 }


 void setToggleSwitchLED(char bool_)
 {
	switch (register__)
	{
		//case 'A':
		//if (bool_ == '0')
		//{
			//PORTA &= ~(1 << port__);
		//}
		//else 
		//{
			//PORTA |= (1 << port__);
		//}
		//break;

		case 'B':
		if (bool_ == '0')
		{
			PORTB &= ~(1 << port__);
		}
		else
		{
			PORTB |= (1 << port__);
		}
		break;
		case 'C':
		if (bool_ == '0')
		{
			PORTC &= ~(1 << port__);
		}
		else
		{
			PORTC |= (1 << port__);
		}
		break;
		case 'D':
		if (bool_ == '0')
		{
			PORTD &= ~(1 << port__);
		}
		else
		{
			PORTD |= (1 << port__);
		}
		break;
		//case 'E':
		//if (bool_ == '0')
		//{
			//PORTE &= ~(1 << port__);
		//}
		//else
		//{
			//PORTE |= (1 << port__);
		//}
		//break;
		//case 'F':
		//if (bool_ == '0')
		//{
			//PORTF &= ~(1 << port__);
		//}
		//else
		//{
			//PORTF |= (1 << port__);
		//}
		//break;
		//case 'G':
		//if (bool_ == '0')
		//{
			//PORTG &= ~(1 << port__);
		//}
		//else
		//{
			//PORTG |= (1 << port__);
		//}
		//break;
		//case 'H':
		//if (bool_ == '0')
		//{
			//PORTH &= ~(1 << port__);
		//}
		//else
		//{
			//PORTH |= (1 << port__);
		//}
		//break;
		//case 'J':
		//if (bool_ == '0')
		//{
			//PORTJ &= ~(1 << port__);
		//}
		//else
		//{
			//PORTJ |= (1 << port__);
		//}
		//break;
		//case 'K':
		//if (bool_ == '0')
		//{
			//PORTK &= ~(1 << port__);
		//}
		//else
		//{
			//PORTK |= (1 << port__);
		//}
		//break;
		//case 'L':
		//if (bool_ == '0')
		//{
			//PORTL &= ~(1 << port__);
		//}
		//else
		//{
			//PORTL |= (1 << port__);
		//}
		//break;
	}
 }
