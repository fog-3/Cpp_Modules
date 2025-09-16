/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:05:08 by fosuna-g          #+#    #+#             */
/*   Updated: 2025/09/16 11:05:09 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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