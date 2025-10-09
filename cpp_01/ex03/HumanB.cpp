/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 09:46:55 by fosuna-g          #+#    #+#             */
/*   Updated: 2025/10/09 12:27:13 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string humanName) : _weapon(NULL)
{
    _name = humanName;
}

HumanB::~HumanB(void)
{    
}

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}

void HumanB::attack(void) {
    if (_weapon == NULL) {
        std::cout << _name << " has no weapon!" << std::endl;
    } else {
        std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
    }
}
