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
//					MAIN PROGRAM - RECEIVER																						                                  |
//	- 31/05/2017:	PROGRAM WORKS!!																																  |
//																																								  |
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------

//AVR Header files
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>
//Drivers
#include "Manchester.h"
#include "zeroCrossDetector.h"
#include "X10_Receiver.h"
#include "uart.h"

int main(void)
{
	//Initiér UART og ZCDetector.
	InitUART(9600,8,'N');
	initZCDetector();
	//PINF7 = INPUT!
	DDRF &= ~(1 << 7);
	//Global interrupt enable
	sei();

	while(1)
	{	
		while (!(PINF & (1 << 7)))
		{}
		SendString((char*)manchesterToString(receiveX10Message()));
	}
}