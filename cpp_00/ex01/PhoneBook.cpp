
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
    this->_index = 0;
	std::cout << "╔══════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║           WELCOME TO CRAPPY PHONEBOOK 80s        ║" << std::endl;
    std::cout << "║                                                  ║" << std::endl;
    std::cout << "║  • Capacity: 8 contacts                          ║" << std::endl;
    std::cout << "║  • Commands: ADD, SEARCH, EXIT                   ║" << std::endl;
    std::cout << "║  • Technology: The future is NOW!                ║" << std::endl;
    std::cout << "╚══════════════════════════════════════════════════╝" << std::endl;
    std::cout << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << std::endl;
    std::cout << "╔══════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║         CRAPPY PHONEBOOK SHUTTING DOWN           ║" << std::endl;
    std::cout << "║                                                  ║" << std::endl;
    std::cout << "║  All contacts lost forever! (Like tears in rain) ║" << std::endl;
    std::cout << "╚══════════════════════════════════════════════════╝" << std::endl;
}

void PhoneBook::addContact(void)
{
	std::string str;

	str = "";
	if (this->_index > 7)
		std::cout << "Warning: overwriting info about " << this->_contacts[this->_index % 8].getFirstName() << std::endl;
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter a first name: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[this->_index % 8].setFirstName(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter " << this->_contacts[this->_index % 8].getFirstName() << "'s last name: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[this->_index % 8].setLastName(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter " << this->_contacts[this->_index % 8].getFirstName() << "'s nickname: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[this->_index % 8].setNickName(str);
	}
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter " << this->_contacts[this->_index % 8].getFirstName() << "'s phoneNumber: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[this->_index % 8].setPhoneNumber(str);
	}
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter " << this->_contacts[this->_index % 8].getFirstName() << "'s darkestSecret: ";
		if (std::getline(std::cin, str) && str != "")
		{
			this->_contacts[this->_index % 8].setDarkestSecret(str);
			std::cout << this->_contacts[this->_index % 8].getFirstName() << \
				" succesfully added to phonebook" << std::endl;
		}
	}
	this->_index++;
}

void PhoneBook::displayContactList(void)
{
	
}

