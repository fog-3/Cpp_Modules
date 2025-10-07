/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 09:12:21 by fosuna-g          #+#    #+#             */
/*   Updated: 2025/10/07 11:58:37 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
	std::cout << "FragTrap " << getName() << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other.getName())
{
	hit_points = other.getHitPoints();
	energy_points = other.getEnergyPoints();
	attack_damage = other.getAttackDamage();
	std::cout << "FragTrap " << getName() << " copy constructor called" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << getName() << " destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other) {
		ClapTrap::operator=(other);
		std::cout << "FragTrap copy assignment operator called" << std::endl;
	}
	return *this;
}

void	FragTrap::HighFivesGuys()
{
	std::cout << "FragTrap " << name << " requests a positive high five! ✋" << std::endl;
	std::cout << "   Let's celebrate! 🎉" << std::endl;
}
