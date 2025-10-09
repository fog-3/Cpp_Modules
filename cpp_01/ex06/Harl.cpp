/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 09:58:39 by fosuna-g          #+#    #+#             */
/*   Updated: 2025/10/09 12:31:01 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}

void Harl::debug(void)
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup" << std::endl << "burger. I really do!" << std::endl << std::endl;
}

void Harl::info(void)
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put" << std::endl << \
                "bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}

void Harl::warning (void)
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout <<  "I think I deserve to have some extra bacon for free. I’ve been coming for" << std::endl << \
                    "years, whereas you started working here just last month." << std::endl << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}

void    Harl::complain(std::string level)
{
    int logLevel = 0;
    
    if (level == "DEBUG") logLevel = 1;
    else if (level == "INFO") logLevel = 2;
    else if (level == "WARNING") logLevel = 3;
    else if (level == "ERROR") logLevel = 4;

    switch (logLevel) {
        case 1:
            debug();
            // fallthrough
        case 2:
            info();
            // fallthrough
        case 3:
            warning();
            // fallthrough
        case 4:
            error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}
