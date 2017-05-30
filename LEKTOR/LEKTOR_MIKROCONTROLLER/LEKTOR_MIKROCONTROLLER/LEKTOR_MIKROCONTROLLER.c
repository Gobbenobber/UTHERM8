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
	
	// Global interrupt enable
	sei();

	//Streng med data som skal sendes.
	unsigned char streng[2] = {LEKTORID1, COMMAND};
	//Streng som er manchester-encoded (strengen som egentlig sendes).
	unsigned char* konverteretStreng;
	//Char (fra konverteretStreng) som aktuelt afsendes.
	volatile unsigned char karakter = '\0';
	int i = 0;
	while(1)
	{
		//konverteretStreng = stringToManchester((unsigned char*)"TROLDEFAR");
		//for (i = 0; i <= strlen((const char*)konverteretStreng); i++);
		//{
		//sendCharX10(konverteretStreng[i]);
		//}
		//freePtr();
		//sendCharX10(STARTCODE);
		const unsigned char* klunk = stringToManchester("ABCD");
		for (i = 0; i < strlen(klunk); i++)
		{
			sendCharX10(klunk[i]);
		}
		freePtr();
	
		//// Go through UC1 & UC2 -- also changes LED according to actual status.
		//lektorStatus_PaaKontor();
		//lektorStatus_Optaget();
		//// Check om der er sket en ændring, opdatér kommando baseret på dette.
		//opdaterKommando();
//
		//// Hvis der er sket en ændring, send STARTCODE efterfulgt af X10-kommando (bestående af LEKTORID1 og COMMAND).
		//if (aendring_ == 1)
		//{
		//streng[1] = COMMAND;
		//konverteretStreng = stringToManchester(streng);
		//sendCharX10(STARTCODE);
		//for (size_t i = 0; i > strlen((const char*)konverteretStreng); i++)
		//{
			//karakter = konverteretStreng[i];
			//sendCharX10(karakter);
		//}
		//// Send stopBit?!
		//ventPaaZC();
		//start1msDelay();
		//start1msDelay();
		//start400usDelay();
		//sendBurst();
		//freePtr();
		//}
	}
}