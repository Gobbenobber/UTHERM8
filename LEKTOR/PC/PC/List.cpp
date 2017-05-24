#include "List.h"



List::List()
{
	size_ = 256; //256 lektorKontorer.
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
			else if(i >= 100)
			{
				myFile_ << "a" << i;
			}

			myFile_ << "\n";
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
			location++;
			std::cout << "Test: " << holder << "\n";
			storage_[location-1] = holder;
			
		}
	}
	myFile_.close();
}

void List::validation() const
{
	//Validation
	std::cout << "Printing all of the array\n";
	for (int i = 0; i < size_; i++)
	{
		std::cout << "Read: " << storage_[i] << std::endl;
	}

	for (int i = 0; i < size_; i++)
	{
		if (storage_[i].at(0) == 'a')
		{
			std::cout << "Validation successful for \"a\" \n";
		}
		else
		{
			std::cout << "Validation failed for \"a\" \n";
		}
	}
}

void List::inputText()
{

}

void List::textToInt()
{
	int * idArr;
	idArr = new int[size_];
	std::string tempStorage;
	std::string tempStr;

	for (int i = 0; i < size_; i++)
	{
		if (
			storage_[i].at(1) >= '0' || 
			storage_[i].at(2) >= '0' || 
			storage_[i].at(2) <= '9')
		{
			if (storage_[i].at(1) == '0' && storage_[i].at(2) == '0')
			{
				std::cout << storage_[i].at(3) << std::endl;
				tempStorage = storage_[i].at(3);
				idArr[i] = stoi(tempStorage);
			}
			else if(storage_[i].at(1) == '0')
			{
				std::cout << storage_[i].at(2) << storage_[i].at(3) << std::endl;
				tempStorage[0] = storage_[i][2];
				tempStorage[1] = storage_[i][3];
				idArr[i] = stoi(tempStorage);
			}
			else
			{
				std::cout << storage_[i].at(1) << storage_[i].at(2) << storage_[i].at(3) << std::endl;
				tempStorage[0] = storage_[i][1];
				tempStorage[1] = storage_[i][2];
				tempStr = storage_[i][3];
				idArr[i] = stoi(tempStorage)*10 + stoi(tempStr);
			}
		}
		else
		{
			std::cout << "Storage / indicatiors Failed \n";
		}
	}
	for (int i = 0; i < size_; i++)
	{
		std::cout << "Ints: " << idArr[i] << std::endl;
	}
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

void List::resetAll()
{
}

void List::terminateProgram()
{
}
