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
//	- 31/05/2017:	[Check GitHub log for changes]
//					TODAY THIS PROGRAM HAS BEEN TESTED AND IT WORKS FOR SENDING ONE FULL X10 COMMAND AT A TIME. TIMER NOT IMPLEMENTED YET.			
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------

//AVR Header files
#include <avr/io.h>
#include <avr/interrupt.h>

//Drivers
#include "Manchester.h"
#include "RegistrerLektor_Optaget.h"
#include "RegistrerLektor_PaaKontor.h"
#include "Timer.h"
#include "Sensor.h"
#include "ToggleSwitch.h"
#include "ToggleSwitchLED.h"
#include "zeroCrossDetector.h"
#include "X10_Master.h"


int main(void)
{
	//Initializing
	initSensor('B', 2);
	initToggleSwitch('B', 3);
	initToggleSwitchLED('B', 4);
	initZCDetector();
	initBurst();
	
	unsigned char LEKTORID1 = 'A';
	unsigned char STARTCODE = 0b11101110;

	// Global interrupt enable
	sei();

	//Streng med data som skal sendes.
	unsigned char X10Message[3];
	int i = 0;
	int n;
	while(1)
	{	
		// Go through UC1 & UC2
		lektorStatus_PaaKontor();
		lektorStatus_Optaget();
		// Check om der er sket en ændring, opdatér kommando baseret på dette.
		opdaterKommando(); 

		// Hvis der er sket en ændring, send STARTCODE efterfulgt af X10-information (bestående af LEKTORID1 og COMMAND (konvereret til Manchester)).
		if (aendring_ == 1)
		{
			// COMMAND = 'c';
			X10Message[0] = LEKTORID1;
			X10Message[1] = COMMAND;
			X10Message[2] = '\0';
			unsigned char* konverteretStreng = stringToManchester(X10Message);
			for (n = 0; n < 2; n++)
			{
			
			sendCharX10(STARTCODE);
			for (i = 0; i < strlen((char*)konverteretStreng); i++)
			{
				sendCharX10(konverteretStreng[i]);
			}
			start1msDelay();
			freePtr();
			}
		}
	}
}