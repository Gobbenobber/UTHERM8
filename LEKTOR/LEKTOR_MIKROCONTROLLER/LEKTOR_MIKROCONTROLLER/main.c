//Globale variable
#define F_CPU 16000000
#define LEKTORID1 'A'
#define LEKTORID2 'A'
#define STARTCODE = 0b11101110

//AVR Header files
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

//Drivers
#include "Send.h"
#include "Manchester.h"
#include "RegistrerLektor_Optaget.h"
#include "RegistrerLektor_PaaKontor.h"
#include "Timer_1.h"
#include "Timer_2.h"
#include "Send.h"
#include "Sensor.h"
#include "ToggleSwitch.h"
#include "ToggleSwitchLED.h"
#include "zeroCrossDetector.h"

//------------------------------------//
//				 Variables			  //
//------------------------------------//
volatile unsigned char karakter = '\0';
volatile short int currentChar = 0;
volatile unsigned char COMMAND = '\0';
/*
//------------------------------------//
//				 Functions			  //
//------------------------------------//
*/
unsigned char* konverteretStreng;
int main(void)
{
	initSensor('B', 2);
	initToggleSwitch('B', 3);
	initToggleSwitchLED('B', 4);
	initZCDetector();
	
	unsigned char streng[3] = {LEKTORID1, LEKTORID2, COMMAND};
	sei();

	//TEST AF PIN
	//DDRC |= 1 << 0;

	//Test LED
	//DDRC |= 1 << 5;

	//Initializing



	// Global interrupt enable

	while(1)
	{

		if (lektorOptaget_ == '0' && lektortilStede_ == '0')
		{
			skiftLEDTilstand_PaaKontor(kontorStatus());
			COMMAND = 'V';					// V indikerer at lektor er væk!
		}
		else if (lektorOptaget_ == '0' && lektortilStede_ == '1')
		{
			skiftLEDTilstand_PaaKontor(kontorStatus());
			COMMAND = 'T';					// T Indikerer at lektor er tilstede
		}
		else if (lektorOptaget_ == '1' && lektortilStede_ == '0')
		{
			skiftLEDTilstand_Optaget(toggleSwitchStatus());
			COMMAND = 'O';					// O indikerer at lektor har benyttet ToggleSwitch (=Optaget)

		}
		else if (lektorOptaget_ == '1' && lektortilStede_ == '1')
		{
			if (returnerTimerStatus() == 0)
			{
			setTimer();
			}
			skiftLEDTilstand_Optaget(toggleSwitchStatus());
			COMMAND = 'O';					// O indikerer at lektor har benyttet ToggleSwitch (=Optaget)
		}

		streng[2] = COMMAND;

		konverteretStreng = stringToManchester(streng);
		karakter = konverteretStreng[currentChar];
		freePtr();
	}
}

// Interrupt service routine for INT0 (Er INT3 for Atmega 2560)
ISR (INT0_vect)
{
	//_delay_ms(2);
	T2Delay_us(8);
	sendCharSW(karakter);
	currentChar++;
}