/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 09:46:55 by fosuna-g          #+#    #+#             */
/*   Updated: 2025/09/18 10:58:09 by fosuna-g         ###   ########.fr       */
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
    std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}
