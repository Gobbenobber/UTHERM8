/*

	____    ______           _   __            _
	\ \ \   | ___ \         | | / /           | |
	 \ \ \  | |_/ __ _  __ _| |/ /  ___  _ __ | |_ ___  _ __
	  \ \ \ |  __/ _` |/ _` |    \ / _ \| '_ \| __/ _ \| '__|
	   \ \ \| | | (_| | (_| | |\  | (_) | | | | || (_) | |
		\_\_\_|  \__,_|\__,_\_| \_/\___/|_| |_|\__\___/|_|
		---------------------------------------------------

- Indeholder information om lektors tilstedev�relse p� kontoret.
- Skrevet af Kasper, Susanne og Patrick.

 */ 


 skiftLEDTilstand_PaaKontor(char tilStede_)
 {

	if (tilStede_ == '1')
	{
	setToggleSwitchLED(char '0');
	tilstand_ = 0;
	}
	
 }

 void lektorStatus_PaaKontor(char*)
 {
	

 }