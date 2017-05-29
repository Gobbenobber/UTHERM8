/*
//   $$$$$$\
//  $$  __$$\
//  $$ /  \__| $$$$$$\  $$$$$$$\   $$$$$$$\  $$$$$$\   $$$$$$\
//  \$$$$$$\  $$  __$$\ $$  __$$\ $$  _____|$$  __$$\ $$  __$$\
//   \____$$\ $$$$$$$$ |$$ |  $$ |\$$$$$$\  $$ /  $$ |$$ |  \__|
//  $$\   $$ |$$   ____|$$ |  $$ | \____$$\ $$ |  $$ |$$ |
//  \$$$$$$  |\$$$$$$$\ $$ |  $$ |$$$$$$$  |\$$$$$$  |$$ |
//   \______/  \_______|\__|  \__|\_______/  \______/ \__|.c
 */ 


#include "Sensor.h"
//Variables
volatile char lektorDetected_;
static char register_;
static short int port_;


void initSensor(char register__, short int port)
{
	if (register__ > 'L' || register__ < 'A' || register__ == 'I')
	{
		register_ = 'A';
	}
	if (port > 7)
	{
		port_ = 2;
	}

	switch (register_)
	{
		case 'A':
		DDRA &= ~(1 << port);
		break;
		case 'B':
		DDRB &= ~(1 << port);
		break;
		case 'C':
		DDRC &= ~(1 << port);
		break;
		case 'D':
		DDRD &= ~(1 << port);
		break;
		case 'E':
		DDRE &= ~(1 << port);
		break;
		case 'F':
		DDRF &= ~(1 << port);
		break;
		case 'G':
		DDRG &= ~(1 << port);
		break;
		case 'H':
		DDRH &= ~(1 << port);
		break;
		case 'J':
		DDRJ &= ~(1 << port);
		break;
		case 'K':
		DDRK &= ~(1 << port);
		break;
		case 'L':
		DDRL &= ~(1 << port);
		break;
	}
}

char kontorStatus()
{
	switch (register_)
	{
		case 'A':
	
		if (PINA & (1 << port_))
		{
			lektorDetected_ = '1';
			return lektorDetected_;
		}
		else
		{
			lektorDetected_ = '0';
			return lektorDetected_;
		}
		break;

		case 'B':
		if (PINB & (1 << port_))
		{
			lektorDetected_ = '1';
			return lektorDetected_;
		}
		else
		{
			lektorDetected_ = '0';
			return lektorDetected_;
		}
		break;

		case 'C':
		if (PINC & (1 << port_))
		{
			lektorDetected_ = '1';
			return lektorDetected_;
		}
		else
		{
			lektorDetected_ = '0';
			return lektorDetected_;
		}
		break;

		case 'D':
		if (PIND & (1 << port_))
		{
			lektorDetected_ = '1';
			return lektorDetected_;
		}
		else
		{
			lektorDetected_ = '0';
			return lektorDetected_;
		}
		break;

		case 'E':
		if (PINE & (1 << port_))
		{
			lektorDetected_ = '1';
			return lektorDetected_;
		}
		else
		{
			lektorDetected_ = '0';
			return lektorDetected_;
		}
		break;

		case 'F':
		if (PINF & (1 << port_))
		{
			lektorDetected_ = '1';
			return lektorDetected_;
		}
		else
		{
			lektorDetected_ = '0';
			return lektorDetected_;
		}
		break;

		case 'G':
		if (PING & (1 << port_))
		{
			lektorDetected_ = '1';
			return lektorDetected_;
		}
		else
		{
			lektorDetected_ = '0';
			return lektorDetected_;
		}
		break;

		case 'H':
		if (PINH & (1 << port_))
		{
			lektorDetected_ = '1';
			return lektorDetected_;
		}
		else
		{
			lektorDetected_ = '0';
			return lektorDetected_;
		}
		break;

		case 'J':
		if (PINJ & (1 << port_))
		{
			lektorDetected_ = '1';
			return lektorDetected_;
		}
		else
		{
			lektorDetected_ = '0';
			return lektorDetected_;
		}
		break;

		case 'K':
		if (PINK & (1 << port_))
		{
			lektorDetected_ = '1';
			return lektorDetected_;
		}
		else
		{
			lektorDetected_ = '0';
			return lektorDetected_;
		}
		break;

		case 'L':
		if (PINL & (1 << port_))
		{
			lektorDetected_ = '1';
			return lektorDetected_;
		}
		else
		{
			lektorDetected_ = '0';
			return lektorDetected_;
		}
		break;
		default: return '0';
	}
}