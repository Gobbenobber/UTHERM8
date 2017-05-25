#pragma once
#include <stdio.h>
#include <tchar.h>
#include <string>
#include "List.h"
#include <iostream>
#include <stdlib.h>
#include <conio.h>



class lectorMenu
{
public:
	lectorMenu();
	~lectorMenu();
	//Mutators
	void setMenuIndex(int menuIndex);
	int getMenuIndex();
	void setEdit(bool edit);
	bool getEdit();

	//Methods
	void initMenu();
	void createLector();
	void removeLector();
	void findLector();
	void changeStateOfLector();
	void printAllOfLectorSystem();
	void resetAllOfLectorSystem();
	void terminateTheMenu();
	int startOfMenu();
	int endOfMenu();
private:
	bool edit_;
	int menuIndex_;
	int tempEdit_;
	std::string tempString_;
	std::string holderString_;
	int tempInt_;
	List lectorSys_;
	bool handle_;
};

