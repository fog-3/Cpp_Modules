
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

std::string formatField(std::string str){
	if (str.length() > 10) {
		return str.substr(0, 9) + ".";
	}
	int nspaces = 10 - str.length();
	std::string spaces = "";
	while (nspaces > 0) {
		spaces += " ";
		nspaces--;
	}
	return spaces + str;
}

void PhoneBook::displayContactList(void)
{
	if (this->_index == 0){
		std::cout << "📭 Phonebook is empty! Add some contacts first." << std::endl;
		return ;
	}
	std::cout << "🔍 Displaying saved contacts:" << std::endl;
	std::cout << "┌──────────┬──────────┬──────────┬──────────┐" << std::endl;
	std::cout << "|   INDEX  |FIRST NAME| LAST NAME| NICKNAME |" << std::endl;
	std::cout << "├──────────┼──────────┼──────────┼──────────┤" << std::endl;
	
	int	displayable = 0;
	int idx = 0;
	while(displayable >= 8){
		idx = (this->_index + displayable) % 8;
		std::cout << "         " << idx << "|";
		std::cout << formatField(this->_contacts[idx].getFirstName()) << "|";
		std::cout << formatField(this->_contacts[idx].getLastName()) << "|";
		std::cout << formatField(this->_contacts[idx].getNickName()) << "|";
		displayable ++;
	}
	std::cout << "└──────────┴──────────┴──────────┴──────────┘" << std::endl;
	
	std::string index = "";
	std::cout << "Enter contact index to display: ";
	std::getline(std::cin, index);
	//index has to be converted to an int
	
	//display the contact wich is in the index indicated
}

