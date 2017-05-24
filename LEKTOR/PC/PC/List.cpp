#include "List.h"



List::List()
{
	size_ = 100; //100 lektorKontorer.
	storage_ = new std::string[size_];
	initializeSpaces(size_);

}


List::~List()
{

}

void List::setSize(int size)
{
}

int List::getSize() const
{
	return size_;
}

void List::setLine(std::string line)
{
}

std::string List::getLine() const
{
	return line_;
}

void List::initializeSpaces(int size)
{
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
