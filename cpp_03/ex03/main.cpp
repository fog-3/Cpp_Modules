/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 09:10:38 by fosuna-g          #+#    #+#             */
/*   Updated: 2025/10/08 13:20:30 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "DiamondTrap.hpp"

void testSection(const std::string& title) {
	std::cout << "\n\033[1;34m=== " << title << " ===\033[0m" << std::endl;
}

int main() {
	testSection("CONSTRUCCIÓN DIAMONDTRAP");
	DiamondTrap diamond("Sparkle");
	
	testSection("MÉTODO WHOAMI");
	diamond.whoAmI();
	
	testSection("ATAQUE (de ScavTrap)");
	diamond.attack("target");
	
	testSection("HIGH FIVE (de FragTrap)");
	diamond.highFivesGuys();
	
	testSection("GUARD GATE (de ScavTrap)");
	diamond.guardGate();
	
	testSection("DAÑO Y REPARACIÓN");
	diamond.takeDamage(50);
	diamond.beRepaired(25);
	
	testSection("CONSTRUCTOR DE COPIA");
	DiamondTrap diamond2(diamond);
	diamond2.whoAmI();
	
	testSection("DESTRUCCIÓN");
	
	return 0;
}
