
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

/* Setters */

void	ClapTrap::setHitPoints(unsigned int points)
{
	this->hit_points = points;
}

void	ClapTrap::setEnergyPoints(unsigned int points)
{
	this->energy_points = points;
}

void	ClapTrap::setAttackDamage(unsigned int damage)
{
	this->attack_damage = damage;
}
