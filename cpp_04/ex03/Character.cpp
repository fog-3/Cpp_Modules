
#include "Character.hpp"
#include <iostream>

Character::Character() : name ("defaultName")
{
	for (int i = 0; i < 4; i++){
		this->inventory[i] = NULL;
	}
}

Character::Character(std::string const & name) : name(name)
{
	for (int i = 0; i < 4; i++) {
		this->inventory[i] = NULL;
	}
}

Character::Character(const Character& other) : name(other.name)
{
	for (int i = 0; i < 4; i++) {
		if (other.inventory[i])
			this->inventory[i] = other.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
	}
}

Character::~Character()
{
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i] != NULL)
			delete this->inventory[i];
	}
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		this->name = other.name;
		for (int i = 0; i < 4; i++) {
			if (this->inventory[i] != NULL) {
				delete this->inventory[i];
				this->inventory[i] = NULL;
			}
		}
		
		for (int i = 0; i < 4; i++){
			if (other.inventory[i] != NULL){
				this->inventory[i] = other.inventory[i]->clone();
			}
		}
	}
	return *this;
}

std::string const & Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria* m)
{
	if (!m) return;
	int i = 0;
	while (i < 4 && this->inventory[i] != NULL)
		i++;
	
	if (i == 4)
		std::cout << "The inventory is full" << std::endl;
	else
	{
		this->inventory[i] = m;
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4) {
		this->inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && this->inventory[idx] != NULL)
	{
		this->inventory[idx]->use(target);
	}
	else
	{
		std::cout << "No Materia found on the inventory" << std::endl;
	}
}
