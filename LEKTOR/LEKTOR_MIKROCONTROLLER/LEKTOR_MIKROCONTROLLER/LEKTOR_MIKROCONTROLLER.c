//  UUUUUUUU     UUUUUUUUTTTTTTTTTTTTTTTTTTTTTTTHHHHHHHHH     HHHHHHHHHEEEEEEEEEEEEEEEEEEEEEERRRRRRRRRRRRRRRRR   MMMMMMMM               MMMMMMMM     888888888
//  U::::::U     U::::::UT:::::::::::::::::::::TH:::::::H     H:::::::HE::::::::::::::::::::ER::::::::::::::::R  M:::::::M             M:::::::M   88:::::::::88
//  U::::::U     U::::::UT:::::::::::::::::::::TH:::::::H     H:::::::HE::::::::::::::::::::ER::::::RRRRRR:::::R M::::::::M           M::::::::M 88:::::::::::::88
//  UU:::::U     U:::::UUT:::::TT:::::::TT:::::THH::::::H     H::::::HHEE::::::EEEEEEEEE::::ERR:::::R     R:::::RM:::::::::M         M:::::::::M8::::::88888::::::8
//   U:::::U     U:::::U TTTTTT  T:::::T  TTTTTT  H:::::H     H:::::H    E:::::E       EEEEEE  R::::R     R:::::RM::::::::::M       M::::::::::M8:::::8     8:::::8
//   U:::::D     D:::::U         T:::::T          H:::::H     H:::::H    E:::::E               R::::R     R:::::RM:::::::::::M     M:::::::::::M8:::::8     8:::::8
//   U:::::D     D:::::U         T:::::T          H::::::HHHHH::::::H    E::::::EEEEEEEEEE     R::::RRRRRR:::::R M:::::::M::::M   M::::M:::::::M 8:::::88888:::::8
//   U:::::D     D:::::U         T:::::T          H:::::::::::::::::H    E:::::::::::::::E     R:::::::::::::RR  M::::::M M::::M M::::M M::::::M  8:::::::::::::8
//   U:::::D     D:::::U         T:::::T          H:::::::::::::::::H    E:::::::::::::::E     R::::RRRRRR:::::R M::::::M  M::::M::::M  M::::::M 8:::::88888:::::8
//   U:::::D     D:::::U         T:::::T          H::::::HHHHH::::::H    E::::::EEEEEEEEEE     R::::R     R:::::RM::::::M   M:::::::M   M::::::M8:::::8     8:::::8
//   U:::::D     D:::::U         T:::::T          H:::::H     H:::::H    E:::::E               R::::R     R:::::RM::::::M    M:::::M    M::::::M8:::::8     8:::::8
//   U::::::U   U::::::U         T:::::T          H:::::H     H:::::H    E:::::E       EEEEEE  R::::R     R:::::RM::::::M     MMMMM     M::::::M8:::::8     8:::::8
//   U:::::::UUU:::::::U       TT:::::::TT      HH::::::H     H::::::HHEE::::::EEEEEEEE:::::ERR:::::R     R:::::RM::::::M               M::::::M8::::::88888::::::8
//    UU:::::::::::::UU        T:::::::::T      H:::::::H     H:::::::HE::::::::::::::::::::ER::::::R     R:::::RM::::::M               M::::::M 88:::::::::::::88
//      UU:::::::::UU          T:::::::::T      H:::::::H     H:::::::HE::::::::::::::::::::ER::::::R     R:::::RM::::::M               M::::::M   88:::::::::88
//        UUUUUUUUU            TTTTTTTTTTT      HHHHHHHHH     HHHHHHHHHEEEEEEEEEEEEEEEEEEEEEERRRRRRRR     RRRRRRRMMMMMMMM               MMMMMMMM     888888888
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
//					MAIN PROGRAM
//	- 20/05/2017:	The program has been written anf compiles just fine
//					We still need to test it with toggleswitch and sensor.
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------

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
unsigned char* konverteretStreng;
/*
//------------------------------------//
//				 Functions			  //
//------------------------------------//
*/

int main(void)
{
	initSensor('B', 2);
	initToggleSwitch('B', 3);
	initToggleSwitchLED('B', 4);
	initZCDetector();
	
	//Streng med data som skal sendes.
	unsigned char streng[4] = {LEKTORID1, LEKTORID2, COMMAND, '\0'};
	
	// Global interrupt enable
	sei();

	//TEST AF PIN
	//DDRC |= 1 << 0;

	//Test LED
	//DDRC |= 1 << 5;

	//Initializing



	

	while(1)
	{

		kontorStatus();
		toggleSwitchStatus();

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
	return 0;
}

// Interrupt service routine for INT0 (Er INT3 for Atmega 2560)
ISR(INT0_vect)
{
	//_delay_ms(2);
	T2Delay_us(8);
	sendCharSW(karakter);
	currentChar++;
	if (currentChar > 5)
	{
		currentChar = 0;
	}
}