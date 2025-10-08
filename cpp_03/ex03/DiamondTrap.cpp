/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 09:14:29 by fosuna-g          #+#    #+#             */
/*   Updated: 2025/10/08 13:33:06 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& str) 
	: ClapTrap(str + "_clap_name"), FragTrap(str), ScavTrap(str)
{
	hit_points = FragTrap::getHitPoints();
	energy_points = ScavTrap::getEnergyPoints();
	attack_damage = FragTrap::getAttackDamage();
	name = str;
	
	std::cout << "DiamondTrap " << name << " constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) 
	: ClapTrap(other), FragTrap(other), ScavTrap(other) 
{
	name = other.name;
	std::cout << "DiamondTrap " << name << " copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other) {
        ClapTrap::operator=(other);
        name = other.name;
        std::cout << "DiamondTrap copy assignment operator called" << std::endl;
    }
    return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << name << " destructor called" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::name << std::endl;
}
