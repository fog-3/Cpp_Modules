/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 09:44:45 by fosuna-g          #+#    #+#             */
/*   Updated: 2025/10/09 11:46:21 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string zombieName){
    this->_name = zombieName;
    std::cout << "Zombie " << zombieName << " created" << std::endl;
}

Zombie::Zombie(void)
{
}

Zombie::~Zombie(void)
{
    std::cout << "Zombie " << _name << " destroyed" << std::endl;
}

void Zombie::announce(void){
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string zombieName)
{
    _name = zombieName;
}
