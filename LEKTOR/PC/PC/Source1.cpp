#include <stdio.h>
#include <tchar.h>
#include "Header.h"	// Library described above
#include <string>

#include "List.h";

// application reads from the specified serial port and reports the collected data
int main()
{
	/*
	printf("Welcome to the serial test app!\n\n");

	Serial* SP = new Serial("COM3");			// adjust as needed

	if (SP->IsConnected())
		printf("UTHERM8 FORBUNDET!");

	unsigned char incomingData[5] = "";			// don't forget to pre-allocate memory
												//printf("%s\n",incomingData);
	int dataLength = 4;
	int readResult = 0;

	while (SP->IsConnected())
	{
		readResult = SP->ReadData(incomingData, dataLength);
												//printf("Bytes read: (0 means no data available) %i\n",readResult);
		incomingData[readResult] = 0;

		printf("%s\n", incomingData);

		Sleep(500);
	}
	*/
	List l_1;
	l_1.printAll();
	l_1.validation();
	l_1.textToInt();

	while (true)
	{

	}
	return 0;
}