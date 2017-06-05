#pragma once

//Packages
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

class List
{
public:
	List(int size = 256);		//Default constructor
	~List();	//Destructor

	//Mutators
	void setSize(int size);
	int getSize() const;
	void setLine(std::string line);
	std::string getLine() const;

	//Methods
	void initializeSpaces(int size);
	void printAll();
	void validation() const;
	void textToInt();
	
	//Add lector from name
	void addLector(int id, std::string name);
	void removeLector(int id);
	void changeState(int id, char state);
	std::string getLector(int id) const;
	void resetAll();
	int returnID(std::string initialer);
	std::string returnLector(int id);
	void fillStorage();
private:
	int size_; //Changeable
	std::string* storage_; //Dynamic
	std::string line_;
	std::fstream myFile_;
	int * idArr;

};

