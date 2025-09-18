/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 09:50:24 by fosuna-g          #+#    #+#             */
/*   Updated: 2025/09/18 10:18:48 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string weaponType){
	this->_type = weaponType;
}

Weapon::Weapon(void)
{   
}

Weapon::~Weapon(void)
{
}

const	std::string &Weapon::getType(void) const{
	const std::string &res = this->_type;
	return (res);
}


void	Weapon::setType(std::string weaponType){
	this->_type = weaponType;
}
