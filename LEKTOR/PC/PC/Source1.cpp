#include <stdio.h>
#include <tchar.h>
#include "Serial.h"	// Library described above
#include <string>
#include "List.h"
#include "lectorMenu.h"


// application reads from the specified serial port and reports the collected data
int main()
{
	//Receiver
	const std::string COMPort_1 = "COM5";
	std::cout << "Seriel kommunikation ### - 1 - ###" << std::endl;
	Serial* arduinoPtr_1 = new Serial("COM5");			// adjust as needed
	std::cout << "Arduino_1 Receiver on the " << COMPort_1 << " port"<< std::endl << std::endl;

	if (arduinoPtr_1->IsConnected())
		printf("Arduino_1 fundet!\n");

	//Transmitter
	const std::string COMPort_2 = "COM4";

	std::cout << "Seriel kommunikation ### - 2 - ###" << std::endl;
	Serial* arduinoPtr_2 = new Serial("COM4");			// adjust as needed

	std::cout << "Arduino_2 Panel on the " << COMPort_2 << " port" << std::endl << std::endl;

	if (arduinoPtr_2->IsConnected())
		printf("Arduino_2 fundet!\n");

	// Variables and Buffers
	unsigned char incomingData[10] = "";			// don't forget to pre-allocate memory
	char tempData[10] = "";
	char tempArr[10] = "";
	char outgoingData[10] = "";
	
	std::string tempString;
	// Definer data length
	int dataLength = 2;
	int readResult = 0;

	List lectorSys;	//Using the default 256 spaces. Outputting to "Text.txt"
	lectorMenu adminSys;

	//Admin controlmenu
	bool edit;
	int tempEdit = 0;
	int menuIndex;
	edit = adminSys.getEdit();

	do	//Running the LectorMenu on startup, will proceed until all changes has been made.
	{
		adminSys.initMenu();
		edit = adminSys.getEdit();
	} while (edit == true);

	{
		//Receiver
		//Move data from serial to incomingData

		if (arduinoPtr_1->IsConnected())
		{
			//Serial Read
			readResult = arduinoPtr_1->ReadData(incomingData, dataLength);
			incomingData[readResult] = 0;
		}

		if (incomingData[0] >= 'A')
		{
			std::cout << incomingData << std::endl;
		}

		//Storing Data
		for (int i = 0; i < dataLength; i++)
		{
			tempData[i] = incomingData[i];
		}
		
		if (outgoingData != tempData)
		{
			tempString = "";
			for (size_t i = 0; i < dataLength; i++)
			{
				outgoingData[i] = tempData[i];
			}
			for (size_t i = 0; i < 3; i++)
			{
				tempString += outgoingData[i];
			}
			int id = tempString[0];
			if (tempString[1] == '\0')
			{
				tempString[1] = 'F';

			}
			id = 10;	//Temporary ID, chosen for clarity in the text file.
			lectorSys.changeState(id, tempString[1]);
		}
		
		//Output to panel
		if (outgoingData != "00000000")
		{
			if (arduinoPtr_2->IsConnected())
			{
				bool tempBool = false;
				outgoingData[0] = outgoingData[1];

				//Writing 1 char for prototype.
				tempBool = arduinoPtr_2->WriteData(outgoingData, 1);
			}
		}
		
	}
	return 0;
}