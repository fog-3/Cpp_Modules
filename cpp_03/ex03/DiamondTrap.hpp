/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 09:14:33 by fosuna-g          #+#    #+#             */
/*   Updated: 2025/10/09 13:11:37 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP

#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>
#include <iostream>

class DiamondTrap : public FragTrap, public ScavTrap {
	private:
		std::string name;
	public:
		DiamondTrap(const std::string& str);
		DiamondTrap(const DiamondTrap& other);
		DiamondTrap(void);
    	DiamondTrap& operator=(const DiamondTrap& other);
		~DiamondTrap(void);
		
		void whoAmI();
		
		// Override the attack method from ScavTrap
		using ScavTrap::attack;
};

#endif
