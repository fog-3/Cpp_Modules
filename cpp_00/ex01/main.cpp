
#include "PhoneBook.hpp"

int main(){
	PhoneBook   phonebook;
	std::string command = "";

	while (command != "EXIT") {
		std::cout << "📞 Command > ";
		std::getline(std::cin, command);

		if (command == "ADD")
			phonebook.addContact();
		else if (command == "SEARCH")
			phonebook.displayContactList();
		else
			std::cout << "Invalid command. Please enter ADD, SEARCH or EXIT." << std::endl;
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return (0);
		}
	}
	return (0);
}