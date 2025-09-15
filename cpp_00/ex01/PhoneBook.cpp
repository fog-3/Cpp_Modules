
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
		std::cout << "\033[31mWarning:\033[0m overwriting info about " << this->_contacts[this->_index % 8].getFirstName() << std::endl;
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
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter " << this->_contacts[this->_index % 8].getFirstName() << "'s phoneNumber: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[this->_index % 8].setPhoneNumber(str);
	}
	str = "";
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

std::string PhoneBook::formatField(const std::string &str) const {
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

void	PhoneBook::printContact(Contact contact){
	std::cout << std::endl << "📋 Contact details:" << std::endl;
	std::cout << "First name: " << contact.getFirstName() << std::endl;
	std::cout << "Last name: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickName() << std::endl;
	std::cout << "Phone number: " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest secret:: " << contact.getDarkestSecret() << std::endl << std::endl;
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
	
	int	index
	 = 0;
	while(index < 8 && index < this->_index){
		std::cout << "|         " << index << "|";
		std::cout << formatField(this->_contacts[index].getFirstName()) << "|";
		std::cout << formatField(this->_contacts[index].getLastName()) << "|";
		std::cout << formatField(this->_contacts[index].getNickName()) << "|" << std::endl;
		index ++;
	}
	std::cout << "└──────────┴──────────┴──────────┴──────────┘" << std::endl;
	
	index = 0;
	std::cout << "Enter contact index to display: ";
	if (!(std::cin >> index)) {
		std::cout << "Invalid index (it has to be an integer)" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} else if (index >= 0 && (index <= this->_index && index < 8)) {
		printContact(this->_contacts[index]);
		std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} else {
		std::cout << "Invalid index (index out of bounds)" << std::endl;
		std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

