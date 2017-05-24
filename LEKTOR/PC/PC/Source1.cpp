#include <stdio.h>
#include <tchar.h>
#include "Header.h"	// Library described above
#include <string>
#include "List.h"

// application reads from the specified serial port and reports the collected data
int main()
{
	//Receiver
	const std::string COMPort_1 = "COM3";

	std::cout << "Seriel kommunikation ### - 1 - ###\n\n" << std::endl;
	Serial* arduinoPtr_1 = new Serial("COM3");			// adjust as needed

	std::cout << "Arduino_1 Receiver on the " << COMPort_1 << " port"<< std::endl;

	if (arduinoPtr_1->IsConnected())
		printf("Arduino_1 fundet!\n");

	//Transmitter
	const std::string COMPort_2 = "COM4";

	std::cout << "Seriel kommunikation ### - 2 - ###\n\n" << std::endl;
	Serial* arduinoPtr_2 = new Serial("COM4");			// adjust as needed

	std::cout << "Arduino_2 Receiver on the " << COMPort_2 << " port" << std::endl;

	if (arduinoPtr_2->IsConnected())
		printf("Arduino_2 fundet!\n");

	// Variables and Buffers
	unsigned char incomingData[9] = "";			// don't forget to pre-allocate memory
	unsigned char tempData[9] = "";
	unsigned char outgoingData[9] = "";
												// printf("%s\n",incomingData);
	// Definer data length
	int dataLength = 8;
	int readResult = 0;

	List adminSys;	//Using the default 256 spaces. Outputting to "Text.txt"

	//Admin controlmenu
	int tempEdit;
	bool edit = false;

	std::cout << "### - Admin menu, choose 1 to edit or 0 to continue - ###" << std::endl;
	std::cout << "= ";
	std::cin >> tempEdit;
	if (tempEdit == 0)
		edit = false;
	else if (tempEdit == 1)
		edit = true;

	while (edit == true)
	{
		std::cout << "### -	 WELCOME TO THE ADMIN MENU	 - ###" << std::endl;
		std::cout << "### - Press '1' to create a Lector - ###" << std::endl;
		std::cout << "### - Press '2' to remove a Lector - ###" << std::endl;
		std::cout << "### - Press '3' find a lector		 - ###" << std::endl;
		std::cout << "### - Press '4' change a state	 - ###" << std::endl;
		std::cout << "### - Press '5' print all			 - ###" << std::endl;
		std::cout << "### - Press '6' to resetall (!!!)	 - ###" << std::endl;
		std::cout << "### - Press '7' to terminate		 - ###" << std::endl;
		std::cin >> edit;






	}
		


	while (1)
	{
		//Receiver
		//Move data from serial to incomingData
		if (arduinoPtr_1->IsConnected())
		{
			//Serial Read
			readResult = arduinoPtr_1->ReadData(incomingData, dataLength);
			// printf("Bytes read: (0 means no data available) %i\n",readResult);
			incomingData[readResult] = 0;

			std::cout << incomingData << std::endl;

			//Storing Data
			for (int i = 0; i < dataLength; i++)
			{
				tempData[i] = incomingData[i];
			}
		}
		if (outgoingData != tempData)
		{
			for (size_t i = 0; i < dataLength; i++)
			{
				outgoingData[i] = tempData[i];
			}

			//Implement in List
			









		}
	}
	return 0;
}