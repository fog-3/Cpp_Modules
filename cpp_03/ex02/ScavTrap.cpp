/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 09:10:42 by fosuna-g          #+#    #+#             */
/*   Updated: 2025/10/09 13:04:01 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
	std::cout << "ScavTrap " << getName() << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other.getName())
{
	hit_points = other.getHitPoints();
	energy_points = other.getEnergyPoints();
	attack_damage = other.getAttackDamage();
	std::cout << "ScavTrap " << getName() << " copy constructor called" << std::endl;
}

ScavTrap::ScavTrap(void)
{
	std::cout << "Default ScavTrap constructor called" << std::endl;
}

ScavTrap::~ScavTrap() 
{
    std::cout << "ScavTrap " << getName() << " destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        std::cout << "ScavTrap copy assignment operator called" << std::endl;
    }
    return *this;
}

void	ScavTrap::attack(const std::string& target)
{
	if (getHitPoints() == 0) {
        std::cout << "ScavTrap " << getName() << " has no hit points left and can't attack!" << std::endl;
        return;
    }
    if (getEnergyPoints() == 0) {
        std::cout << "ScavTrap " << getName() << " has no energy points left!" << std::endl;
        return;
    }

	energy_points--;
	std::cout << "ScavTrap " << getName() << " attacks " << target 
              << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate() {
    std::cout << "ScavTrap " << getName() << " is now in Gate keeper mode!" << std::endl;
}
