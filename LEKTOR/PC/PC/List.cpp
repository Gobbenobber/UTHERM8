#include "List.h"



List::List()
{
	size_ = 100; //100 lektorKontorer.
	storage_ = new std::string[size_];
	initializeSpaces(size_);
	printAll();
}


List::~List()
{

}

void List::setSize(int size)
{
	if (size < 1000 && size > 0)
	{
		size_ = size;
	}
	else
	{
		std::cout << "Error:1 - input a whole number between 0 and 1000" << std::endl;
	}
}

int List::getSize() const
{
	return size_;
}

void List::setLine(std::string line)
{
	line_ = line_;
}

std::string List::getLine() const
{
	return line_;
}

void List::initializeSpaces(int size)
{
	myFile_.open("Text.txt");
	//Prepare indicators
	std::cout << "Inputting indicators\n";
	if (myFile_.is_open())
	{
		for (int i = 0; i < size; i++)
		{
			if (i < 10)
			{
				myFile_ << "a0" << i << "-\n";
			}
			else
			{
				myFile_ << "a" << i << "-\n";
			}
		}
		std::cout << "Path has been prepared and path is open" << std::endl;
	}
	else
		std::cout << "path is closed" << std::endl;

	//Close the file
	myFile_.close();
}

void List::printAll() const
{
}

void List::validation() const
{
}

void List::inputText()
{
}

void List::textToInt()
{
}

void List::addLector(int id, std::string)
{
}

void List::removeLector(int id)
{
}

void List::changeState(int id, char state_1, char state_2)
{
}

std::string List::getLector() const
{
	return std::string();
}
