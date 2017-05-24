#include "List.h"



List::List()
{
	size_ = 255; //255 lektorKontorer.
	storage_ = new std::string[size_];
	initializeSpaces(size_);
	printAll();
}


List::~List()
{
	delete storage_;
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
				myFile_ << "a00" << i;
			}
			else if (i >= 10 && i < 100)
			{
				myFile_ << "a0" << i;
			}
			else
			{
				myFile_ << "a" << i;
			}

			myFile_ << "_\n";
		}
		std::cout << "Path has been prepared and path is open" << std::endl;
	}
	else
		std::cout << "path is closed" << std::endl;

	//Close the file
	myFile_.close();
}

void List::printAll()
{
	std::cout << "Printing the text from the file\n";
	std::ifstream myFile_("Text.txt");
	int location = 0;
	std::string holder;	//temp
	if (myFile_.is_open())
	{
		while (getline(myFile_, holder))
		{
			std::cout << "Test: " << holder << "\n";
			storage_[location] = holder;
			location++;
		}
	}
	myFile_.close();
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
