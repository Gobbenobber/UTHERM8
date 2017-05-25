#include "lectorMenu.h"



lectorMenu::lectorMenu() : lectorSys_()
{
	menuIndex_ = 0;
	edit_ = true;
}

lectorMenu::~lectorMenu()
{
}

void lectorMenu::setMenuIndex(int menuIndex)
{
	menuIndex_ = menuIndex;
}

int lectorMenu::getMenuIndex()
{
	return menuIndex_;
}

void lectorMenu::setEdit(bool edit)
{
	edit_ = edit;
}

bool lectorMenu::getEdit()
{
	return edit_;
}

void lectorMenu::initMenu()
{
	std::cout << "### - Admin menu, choose 1 to edit or 0 to continue - ###" << std::endl;
	std::cout << "= ";
	std::cin >> tempEdit_;
	if (tempEdit_ == 0)
		edit_ = false;
	else if (tempEdit_ == 1)
		edit_ = true;

	std::cout << "### ----WELCOME TO THE ADMIN MENU--- ###" << std::endl;
	std::cout << "### - Press '1' to create a Lector - ###" << std::endl;
	std::cout << "### - Press '2' to remove a Lector - ###" << std::endl;
	std::cout << "### - Press '3' find a lector      - ###" << std::endl;
	std::cout << "### - Press '4' change a state     - ###" << std::endl;
	std::cout << "### - Press '5' print all          - ###" << std::endl;
	std::cout << "### - Press '6' to resetall (!!!)  - ###" << std::endl;
	std::cout << "### - Press '7' to terminate       - ###" << std::endl;

	while (menuIndex_ < 1 || menuIndex_ > 7)
	{
		std::cout << "= ";
		std::cin >> menuIndex_;
	}
}

void lectorMenu::createLector()
{
	std::cout << "########################################" << std::endl;
	std::cout << "### --------- Create a Lector ------ ###" << std::endl;
	std::cout << "### ----- Enter a lector in the ---- ###" << std::endl;
	std::cout << "### ------- following syntax: ------ ###" << std::endl;

	//Initials
	std::cout << std::endl;
	std::cout << "### ---------- Initials {XX} ------- ###" << std::endl;
	do
	{
		std::cout << "= ";
		std::cin >> tempString_;
		tempString_.resize(2);
	} while (tempString_[0] < 'A' || tempString_[0] > 'Z' || tempString_[1] < 'A' || tempString_[1] > 'Z');
	std::cout << "& You've entered: " << tempString_ << std::endl;
	holderString_ = tempString_;	//Copy string
	tempString_ = "";

	//First Name
	std::cout << std::endl;
	std::cout << "### ----------- First Name --------- ###" << std::endl;
	std::cout << "### ----------- {Henning} ---------- ###" << std::endl;
	do
	{
		tempString_ = "";
		std::cout << "= ";
		std::cin >> tempString_;

	} while (tempString_.size() <= 1);
	std::cout << "& You've entered: " << tempString_ << std::endl;

	holderString_ += '-' + tempString_;

	//Last Name
	std::cout << std::endl;
	std::cout << "### ----------- Last Name --------- ###" << std::endl;
	std::cout << "### ---------- {Hermansen} -------- ###" << std::endl;
	do
	{
		tempString_ = "";
		std::cout << "= ";
		std::cin >> tempString_;

	} while (tempString_.size() <= 1);
	std::cout << "& You've entered: " << tempString_ << std::endl;

	//ID
	std::cout << std::endl;
	std::cout << "### --- Now enter the correct ID --- ###" << std::endl;
	std::cout << "### --------- Between 0-255 -------- ###" << std::endl;
	std::cout << "### --- Only enter whole numbers --- ###" << std::endl;
	do
	{
		std::cout << "= ";
		std::cin >> tempInt_;

	} while (tempInt_ < 0 || tempInt_ > 255);
	std::cout << "& You've entered: " << tempInt_ << std::endl;

	std::cout << "### ------ You've successfully  ---- ###" << std::endl;
	std::cout << "### -------- entered a lector ------ ###" << std::endl;

	tempString_ = holderString_ + '-' + tempString_;

	std::size_t found = tempString_.find_first_of(" ");
	while (found != std::string::npos)
	{
		tempString_[found] = '-';
		found = tempString_.find_first_of(" ", found + 1);
	}
	std::cout << "& You've entered: " << tempString_ << std::endl;
	std::cout << "& at number: " << tempInt_ << std::endl;
	std::cout << "########################################" << std::endl;
	std::cout << std::endl << std::endl;

	lectorSys_.addLector(tempInt_, tempString_);
}

void lectorMenu::removeLector()
{
	std::cout << "########################################" << std::endl;
	std::cout << "### --------- Remove a Lector ------ ###" << std::endl;
	std::cout << "### --- Enter the ID of a lector --- ###" << std::endl;
	std::cout << "### --------- Between 0-255 -------- ###" << std::endl;
	std::cout << "### --- Only enter whole numbers --- ###" << std::endl;
	do
	{
		tempInt_ = -1;
		std::cout << "= ";
		std::cin >> tempInt_;

	} while (tempInt_ < 0 || tempInt_ > 255);
	std::cout << "& You've entered: " << tempInt_ << std::endl;
	lectorSys_.removeLector(tempInt_);
	std::cout << "### -- You've succesfully removed -- ###" << std::endl;

}

void lectorMenu::findLector()
{
}

void lectorMenu::changeStateOfLector()
{
}

void lectorMenu::printAllOfLectorSystem()
{
}

void lectorMenu::resetAllOfLectorSystem()
{
}

void lectorMenu::terminateTheMenu()
{
}

int lectorMenu::startOfMenu()
{
	return 0;
}

int lectorMenu::endOfMenu()
{
	return 0;
}
