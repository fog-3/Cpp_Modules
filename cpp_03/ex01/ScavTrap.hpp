/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 09:10:53 by fosuna-g          #+#    #+#             */
/*   Updated: 2025/10/07 09:10:54 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
