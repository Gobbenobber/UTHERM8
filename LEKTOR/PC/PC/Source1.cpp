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

	std::cout << "Seriel kommunikation ### - 1 - ###\n" << std::endl;
	Serial* arduinoPtr_1 = new Serial("COM3");			// adjust as needed

	std::cout << "Arduino_1 Receiver on the " << COMPort_1 << " port"<< std::endl;

	if (arduinoPtr_1->IsConnected())
		printf("Arduino_1 fundet!\n");

	//Transmitter
	const std::string COMPort_2 = "COM4";

	std::cout << "Seriel kommunikation ### - 2 - ###\n" << std::endl;
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
	int menuIndex = 0;
	bool edit = false;
	std::string tempString = "  ";	//insert two spaces
	std::string holderString;
	int tempInt;

	std::cout << "### - Admin menu, choose 1 to edit or 0 to continue - ###" << std::endl;
	std::cout << "= ";
	std::cin >> tempEdit;
	if (tempEdit == 0)
		edit = false;
	else if (tempEdit == 1)
		edit = true;

	while (edit == true)
	{
		std::cout << "### ----WELCOME TO THE ADMIN MENU--- ###" << std::endl;
		std::cout << "### - Press '1' to create a Lector - ###" << std::endl;
		std::cout << "### - Press '2' to remove a Lector - ###" << std::endl;
		std::cout << "### - Press '3' find a lector      - ###" << std::endl;
		std::cout << "### - Press '4' change a state     - ###" << std::endl;
		std::cout << "### - Press '5' print all          - ###" << std::endl;
		std::cout << "### - Press '6' to resetall (!!!)  - ###" << std::endl;
		std::cout << "### - Press '7' to terminate       - ###" << std::endl;
		while (menuIndex < 1 || menuIndex > 7)
		{
			std::cout << "= ";
			std::cin >> menuIndex;
		}
		if (menuIndex >= 1 && menuIndex <= 7)
		{
			switch (menuIndex)
			{
			case 1:
				std::cout << "### --------- Create a Lector ------ ###" << std::endl;
				std::cout << "### ----- Enter a lector in the ---- ###" << std::endl;
				std::cout << "### ------- following syntax: ------ ###" << std::endl;

				//Initials
				std::cout << std::endl;
				std::cout << "### ---------- Initials {XX} ------- ###" << std::endl;
				do
				{
					std::cout << "= ";
					std::cin >> tempString;
					tempString.resize(2);
				} while (tempString[0] < 'A' || tempString[0] > 'Z' || tempString[1] < 'A' || tempString[1] > 'Z' );
				std::cout << "& You've entered: " << tempString << std::endl;
				holderString = tempString;	//Copy string
				tempString = "";

				//Name
				std::cout << std::endl;
				std::cout << "### ----------- First Name --------- ###" << std::endl;
				std::cout << "### ----------- {Henning} ---------- ###" << std::endl;
				do
				{
					std::cout << "= ";
					std::cin >> tempString;
					for (int i = 0; i < tempString.size(); i++)
					{
						if (tempString[i] == ' ')
						{
							tempString = "";
						}
						if ((tempString[i] < 'A' || tempString[i] > 'Z') && (tempString[i] < 'a' || tempString[i] > 'Z'))
						{
							tempString = "";
						}
					}

				} while (tempString.size() <= 1);
				std::cout << "& You've entered: " << tempString << std::endl;

				std::cout << "### ------ You've successfully  ---- ###" << std::endl;
				std::cout << "### -------- entered a lector ------ ###" << std::endl;
				std::cout << "### --- Now enter the correct ID --- ###" << std::endl;
				std::cout << "### --------- Between 0-255 -------- ###" << std::endl;
				std::cout << "### --- Only enter whole numbers --- ###" << std::endl;

				do
				{
					std::cout << "= ";
					std::cin >> tempInt;
				} while (tempInt < 0 || tempInt > 255);

				//adminSys.addLector();
			break;
			}
		}





		menuIndex = 0;
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