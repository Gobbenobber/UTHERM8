/*
	Implementeringsfil for ToggleSwitch.H
 */ 

 #include "ToggleSwitch.h"

void initToggleSwitch(char register_, short int port)

{
 	if (register_ >= 'E' || register_ <= 'A' || register_ == 'I')
 	{
	 	register__ = 'B';
 	}
 	if (port > 7)
 	{
	 	port__ = 1;
 	}
 	
 	switch (register__)
 	{
	 	//case 'A':
	 	//DDRA &= ~(1 << port);
	 	//break;
	 	case 'B':
	 	DDRB &= ~(1 << port);
	 	break;
	 	case 'C':
	 	DDRC &= ~(1 << port);
	 	break;
	 	case 'D':
	 	DDRD &= ~(1 << port);
	 	break;
	 	//case 'E':
	 	//DDRE &= ~(1 << port);
	 	//break;
	 	//case 'F':
	 	//DDRF &= ~(1 << port);
	 	//break;
	 	//case 'G':
	 	//DDRG &= ~(1 << port);
	 	//break;
	 	//case 'H':
	 	//DDRH &= ~(1 << port);
	 	//break;
	 	//case 'J':
	 	//DDRJ &= ~(1 << port);
	 	//break;
	 	//case 'K':
	 	//DDRK &= ~(1 << port);
	 	//break;
	 	//case 'L':
	 	//DDRL &= ~(1 << port);
	 	//break;
 	}

}

char toggleSwitchStatus()
{
	switch (register__)
	{
		//case 'A':
		//
		//if (PINA & (1 << port__))
		//{
			//tilstand_ = '1';
			//return tilstand_;
		//}
		//else 		
		//{
			//tilstand_ = '0';
			//return tilstand_;
		//}
		//break;

		case 'B':
		if (PINB & (1 << port__))
		{
			tilstand_ = '1';
			return tilstand_;
		}
		else 		
		{
			tilstand_ = '0';
			return tilstand_;
		}
		break;

		case 'C':
		if (PINC & (1 << port__))
		{
			tilstand_ = '1';
			return tilstand_;
		}
		else 		
		{
			tilstand_ = '0';
			return tilstand_;
		}
		break;

		case 'D':
		if (PIND & (1 << port__))
		{
			tilstand_ = '1';
			return tilstand_;
		}
		else 		
		{
			tilstand_ = '0';
			return tilstand_;
		}
		break;

		//case 'E':
		//if (PINE & (1 << port__))
		//{
			//tilstand_ = '1';
			//return tilstand_;
		//}
		//else 		
		//{
			//tilstand_ = '0';
			//return tilstand_;
		//}
		//break;
//
		//case 'F':
		//if (PINF & (1 << port__))
		//{
			//tilstand_ = '1';
			//return tilstand_;
		//}
		//else 		
		//{
			//tilstand_ = '0';
			//return tilstand_;
		//}
		//break;
//
		//case 'G':
		//if (PING & (1 << port__))
		//{
			//tilstand_ = '1';
			//return tilstand_;
		//}
		//else 		
		//{
			//tilstand_ = '0';
			//return tilstand_;
		//}
		//break;
//
		//case 'H':
		//if (PINH & (1 << port__))
		//{
			//tilstand_ = '1';
			//return tilstand_;
		//}
		//else 		
		//{
			//tilstand_ = '0';
			//return tilstand_;
		//}
		//break;
//
		//case 'J':
		//if (PINJ & (1 << port__))
		//{
			//tilstand_ = '1';
			//return tilstand_;
		//}
		//else 		
		//{
			//tilstand_ = '0';
			//return tilstand_;
		//}
		//break;
//
		//case 'K':
		//if (PINK & (1 << port__))
		//{
			//tilstand_ = '1';
			//return tilstand_;
		//}
		//else 		
		//{
			//tilstand_ = '0';
			//return tilstand_;
		//}
		//break;
//
		//case 'L':
		//if (PINL & (1 << port__))
		//{
			//tilstand_ = '1';
			//return tilstand_;
		//}
		//else 		
		//{
			//tilstand_ = '0';
			//return tilstand_;
		//}
		//break;
	}
}