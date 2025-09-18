/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 09:44:59 by fosuna-g          #+#    #+#             */
/*   Updated: 2025/09/18 09:45:00 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void){
    std::string message = "HI THIS IS BRAIN";
    std::string *stringPTR = &message;
    std::string &stringREF = message;

    std::cout << "Memory address of the string: " << &message << std::endl;
    std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;

    std::cout << std::endl;
    
    std::cout << "Value of the string: " << message << std::endl;
    std::cout << "Value pointed to stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value pointed to stringREF: " << stringREF << std::endl;
}