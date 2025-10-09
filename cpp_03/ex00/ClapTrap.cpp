/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 09:10:10 by fosuna-g          #+#    #+#             */
/*   Updated: 2025/10/09 12:48:04 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name) : hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "ClapTrap " << name << " constructor called" << std::endl;
	this->name = name;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "ClapTrap " << other.getName() << " copy constructor called" << std::endl;
	this->name = other.getName();
	this->hit_points = other.getHitPoints();
	this->energy_points = other.getHitPoints();
	this->attack_damage = other.getAttackDamage();
}

ClapTrap::ClapTrap(void)
{
	std::cout << "Default ClapTrap constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << name << " destructed." << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this != &other){
		this->name = other.getName();
		this->hit_points = other.getHitPoints();
		this->energy_points = other.getHitPoints();
		this->attack_damage = other.getAttackDamage();
	}
	return *this;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->energy_points > 0 && this->hit_points > 0){
		this->energy_points--;
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing "
			<< this->attack_damage << " point of damage!" << std::endl;
	} else if (this->energy_points == 0) {
		std::cout << "ClapTrap " << this->name << " has no energy points left!" << std::endl;
	} else if (this->hit_points == 0) {
		std::cout << "ClapTrap " << this->name << " has no hit points left and can't attack!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount >= (unsigned int) this->hit_points)
		hit_points = 0;
	else
		hit_points -= amount;
	std::cout << "ClapTrap " << this->name << " takes " << amount << " damage, now has "
		<< this->hit_points << " hit points!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	//ClapTrap R2-D2 repairs itself for 3 hit points, now has 8 hit points!
	if (this->energy_points > 0 && this->hit_points > 0){
		this->energy_points--;
		if ((amount + this->hit_points) > 10)
			hit_points = 10;
		else
			hit_points += amount;
		std::cout << "ClapTrap " << this->name << " repairs itself for " << amount << " hit points, now has "
			<< this->hit_points << " hit points!" << std::endl;
	} else if (this->energy_points == 0) {
		std::cout << "ClapTrap " << this->name << " has no energy points left!" << std::endl;
	} else if (this->hit_points == 0) {
		std::cout << "ClapTrap " << this->name << " has no hit points left and can't repair!" << std::endl;
	}
}

std::string	ClapTrap::getName() const
{
	return name;
}

int	ClapTrap::getHitPoints() const
{
	return hit_points;
}

int	ClapTrap::getEnergyPoints() const
{
	return energy_points;
}

int	ClapTrap::getAttackDamage() const
{
	return attack_damage;
}
