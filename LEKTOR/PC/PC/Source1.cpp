#include <stdio.h>
#include <tchar.h>
#include "Header.h"	// Library described above
#include <string>

// application reads from the specified serial port and reports the collected data
int main()
{
	printf("Test af seriel kommunikation!\n\n");

	Serial* arduinoPtr = new Serial("COM3");			// adjust as needed

	if (arduinoPtr->IsConnected())
		printf("UTHERM8 FORBUNDET!\n");

	unsigned char incomingData[9] = "";			// don't forget to pre-allocate memory
												// printf("%s\n",incomingData);
	int dataLength = 8;
	int readResult = 0;

	while (arduinoPtr->IsConnected())
	{
		readResult = arduinoPtr->ReadData(incomingData, dataLength);
												// printf("Bytes read: (0 means no data available) %i\n",readResult);
		incomingData[readResult] = 0;

		printf("%s\n", incomingData);

		Sleep(400);
	}
	return 0;
}