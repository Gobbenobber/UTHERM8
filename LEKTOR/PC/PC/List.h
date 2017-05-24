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
	List();		//Default constructor
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
	void inputText();
	void textToInt();
	
	//Add lector from name
	void addLector(int id, std::string);
	void removeLector(int id);
	void changeState(int id, char state_1, char state_2);
	std::string getLector() const;
private:
	int size_; //Changeable
	std::string* storage_; //Dynamic
	std::string line_;
	std::fstream myFile_;

};

