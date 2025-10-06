#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

class ScavTrap : public ClapTrap {
	public:
		// Constructors
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& other);

		// Destructor
		~ScavTrap();

		// Assignment operator
		ScavTrap& operator=(const ScavTrap& other);

		// Attack method
		void attack(const std::string& target);

		// Unique method for ScavTrap
		void guardGate();
};

#endif // SCAVTRAP_HPP
