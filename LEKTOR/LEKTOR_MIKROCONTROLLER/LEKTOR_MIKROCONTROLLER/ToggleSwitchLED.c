/*

$$\$$\   $$$$$$$$\                        $$\          $$$$$$\              $$\  $$\             $$\      $$\      $$$$$$$$\$$$$$$$\
\$$\$$\  \__$$  __|                       $$ |        $$  __$$\             \__| $$ |            $$ |     $$ |     $$  _____$$  __$$\
 \$$\$$\    $$ |$$$$$$\  $$$$$$\  $$$$$$\ $$ |$$$$$$\ $$ /  \__$$\  $$\  $$\$$\$$$$$$\   $$$$$$$\$$$$$$$\ $$ |     $$ |     $$ |  $$ |
  \$$\$$\   $$ $$  __$$\$$  __$$\$$  __$$\$$ $$  __$$\\$$$$$$\ $$ | $$ | $$ $$ \_$$  _| $$  _____$$  __$$\$$ |     $$$$$\   $$ |  $$ |
   \$$\$$\  $$ $$ /  $$ $$ /  $$ $$ /  $$ $$ $$$$$$$$ |\____$$\$$ | $$ | $$ $$ | $$ |   $$ /     $$ |  $$ $$ |     $$  __|  $$ |  $$ |
    \$$\$$\ $$ $$ |  $$ $$ |  $$ $$ |  $$ $$ $$   ____$$\   $$ $$ | $$ | $$ $$ | $$ |$$\$$ |     $$ |  $$ $$ |     $$ |     $$ |  $$ |
     \$$\$$\$$ \$$$$$$  \$$$$$$$ \$$$$$$$ $$ \$$$$$$$\\$$$$$$  \$$$$$\$$$$  $$ | \$$$$  \$$$$$$$\$$ |  $$ $$$$$$$$\$$$$$$$$\$$$$$$$  |
	  \__\__\__|\______/ \____$$ |\____$$ \__|\_______|\______/ \_____\____/\__|  \____/ \_______\__|  \__\________\________\_______/
					    $$\   $$ $$\   $$ |
						\$$$$$$$ \$$$$$$$ |
						 \______/ \______/



 */ 

 #include "ToggleSwitchLED.h"

 void initToggleSwitchLED(char register_, short int port)
 {
	if (register_ > 'L' || register_ < 'A' || register_ == 'I')
	{
		register____ = 'A';
	}
	if (port > 7 || port < 0)
	{
		port____ = 1;
	}

	//sæt given pin til output

	switch (register____)
	{
	case 'A':
	DDRA |= (1 << port____);
	break;
	case 'B':
	DDRB |= (1 << port____);
	break;
	case 'C':
	DDRC |= (1 << port____);
	break;
	case 'D':
	DDRD |= (1 << port____);
	break;
	case 'E':
	DDRE |= (1 << port____);
	break;
	case 'F':
	DDRF |= (1 << port____);
	break;
	case 'G':
	DDRG |= (1 << port____);
	break;
	case 'H':
	DDRH |= (1 << port____);
	break;
	case 'J':
	DDRJ |= (1 << port____);
	break;
	case 'K':
	DDRK |= (1 << port____);
	break;
	case 'L':
	DDRL |= (1 << port____);
	break;
	}
 }


 void setToggleSwitchLED(char bool_)
 {
	switch (register____)
	{
		case 'A':
		if (bool_ == '0')
		{
			PORTA &= ~(1 << port____);
		}
		else 
		{
			PORTA |= (1 << port____);
		}
		break;

		case 'B':
		if (bool_ == '0')
		{
			PORTB &= ~(1 << port____);
		}
		else
		{
			PORTB |= (1 << port____);
		}
		break;
		case 'C':
		if (bool_ == '0')
		{
			PORTC &= ~(1 << port____);
		}
		else
		{
			PORTC |= (1 << port____);
		}
		break;
		case 'D':
		if (bool_ == '0')
		{
			PORTD &= ~(1 << port____);
		}
		else
		{
			PORTD |= (1 << port____);
		}
		break;
		case 'E':
		if (bool_ == '0')
		{
			PORTE &= ~(1 << port____);
		}
		else
		{
			PORTE |= (1 << port____);
		}
		break;
		case 'F':
		if (bool_ == '0')
		{
			PORTF &= ~(1 << port____);
		}
		else
		{
			PORTF |= (1 << port____);
		}
		break;
		case 'G':
		if (bool_ == '0')
		{
			PORTG &= ~(1 << port____);
		}
		else
		{
			PORTG |= (1 << port____);
		}
		break;
		case 'H':
		if (bool_ == '0')
		{
			PORTH &= ~(1 << port____);
		}
		else
		{
			PORTH |= (1 << port____);
		}
		break;
		case 'J':
		if (bool_ == '0')
		{
			PORTJ &= ~(1 << port____);
		}
		else
		{
			PORTJ |= (1 << port____);
		}
		break;
		case 'K':
		if (bool_ == '0')
		{
			PORTK &= ~(1 << port____);
		}
		else
		{
			PORTK |= (1 << port____);
		}
		break;
		case 'L':
		if (bool_ == '0')
		{
			PORTL &= ~(1 << port____);
		}
		else
		{
			PORTL |= (1 << port____);
		}
		break;
	}
 }
