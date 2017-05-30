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
 //Variables
 volatile char LED_ON;
 static char register_;
 static short int pin_;

 void initToggleSwitchLED(char register__, short int pin)
 {
	if (register__ > 'L' || register__ < 'A' || register__ == 'I')
	{
		register_ = 'A';
	}
	else
	{
		register_ = register__;
	}
	if (pin > 7 || pin < 0)
	{
		pin_ = 3;
	}
	else
	{
		pin_ = pin;
	}

	//sæt given pin til output

	switch (register_)
	{
	case 'A':
	DDRA |= (1 << pin_);
	break;
	case 'B':
	DDRB |= (1 << pin_);
	break;
	case 'C':
	DDRC |= (1 << pin_);
	break;
	case 'D':
	DDRD |= (1 << pin_);
	break;
	case 'E':
	DDRE |= (1 << pin_);
	break;
	case 'F':
	DDRF |= (1 << pin_);
	break;
	case 'G':
	DDRG |= (1 << pin_);
	break;
	case 'H':
	DDRH |= (1 << pin_);
	break;
	case 'J':
	DDRJ |= (1 << pin_);
	break;
	case 'K':
	DDRK |= (1 << pin_);
	break;
	case 'L':
	DDRL |= (1 << pin_);
	break;
	}
 }


 void setToggleSwitchLED(char bool_)
 {
	switch (register_)
	{
		case 'A':
		if (bool_ == '0')
		{
			PORTA &= ~(1 << pin_);
		}
		else 
		{
			PORTA |= (1 << pin_);
		}
		break;

		case 'B':
		if (bool_ == '0')
		{
			PORTB &= ~(1 << pin_);
		}
		else
		{
			PORTB |= (1 << pin_);
		}
		break;
		case 'C':
		if (bool_ == '0')
		{
			PORTC &= ~(1 << pin_);
		}
		else
		{
			PORTC |= (1 << pin_);
		}
		break;
		case 'D':
		if (bool_ == '0')
		{
			PORTD &= ~(1 << pin_);
		}
		else
		{
			PORTD |= (1 << pin_);
		}
		break;
		case 'E':
		if (bool_ == '0')
		{
			PORTE &= ~(1 << pin_);
		}
		else
		{
			PORTE |= (1 << pin_);
		}
		break;
		case 'F':
		if (bool_ == '0')
		{
			PORTF &= ~(1 << pin_);
		}
		else
		{
			PORTF |= (1 << pin_);
		}
		break;
		case 'G':
		if (bool_ == '0')
		{
			PORTG &= ~(1 << pin_);
		}
		else
		{
			PORTG |= (1 << pin_);
		}
		break;
		case 'H':
		if (bool_ == '0')
		{
			PORTH &= ~(1 << pin_);
		}
		else
		{
			PORTH |= (1 << pin_);
		}
		break;
		case 'J':
		if (bool_ == '0')
		{
			PORTJ &= ~(1 << pin_);
		}
		else
		{
			PORTJ |= (1 << pin_);
		}
		break;
		case 'K':
		if (bool_ == '0')
		{
			PORTK &= ~(1 << pin_);
		}
		else
		{
			PORTK |= (1 << pin_);
		}
		break;
		case 'L':
		if (bool_ == '0')
		{
			PORTL &= ~(1 << pin_);
		}
		else
		{
			PORTL |= (1 << pin_);
		}
		break;
	}
 }
