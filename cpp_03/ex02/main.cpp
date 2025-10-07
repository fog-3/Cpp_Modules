/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 09:10:38 by fosuna-g          #+#    #+#             */
/*   Updated: 2025/10/07 12:02:15 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "FragTrap.hpp"
#include <iostream>

void testSection(const std::string& title) {
    std::cout << "\n\033[1;35m=== " << title << " ===\033[0m" << std::endl;
}

int main() {
    testSection("CONSTRUCCIÓN BÁSICA");
    FragTrap frag1("Boomer");
    FragTrap frag2("Exploder");
    
    testSection("HIGH FIVES - MÉTODO EXCLUSIVO");
    frag1.HighFivesGuys();
    frag2.HighFivesGuys();
    
    testSection("ATAQUES CON DAÑO MEJORADO (30)");
    frag1.attack("target A");
    frag2.attack("target B");
    
    testSection("DAÑO Y REPARACIÓN");
    frag1.takeDamage(50);
    frag1.beRepaired(25);
    frag1.attack("after repair");
    
    testSection("ENERGÍA MÁXIMA (100 puntos)");
    FragTrap energyFrag("EnergyMaster");
    for (int i = 0; i < 105; i++) {
        std::cout << "Ataque #" << (i + 1) << ": ";
        energyFrag.attack("energy test");
    }
    
    testSection("HIGH FIVE SIN ENERGÍA");
    energyFrag.HighFivesGuys(); // ¡High five siempre funciona!
    
    testSection("CONSTRUCTOR DE COPIA");
    FragTrap frag3(frag1);
    frag3.HighFivesGuys();
    frag3.attack("copied attack");
    
    testSection("OPERADOR DE ASIGNACIÓN");
    FragTrap frag4("TempFrag");
    frag4 = frag2;
    frag4.HighFivesGuys();
    frag4.attack("assigned attack");
    
    testSection("SIN PUNTOS DE VIDA");
    FragTrap toughFrag("ToughOne");
    toughFrag.takeDamage(150); // Más daño que HP máximo
    toughFrag.attack("should fail");
    toughFrag.beRepaired(10);  // Debería fallar
    toughFrag.HighFivesGuys(); // ¡Pero high five SIEMPRE funciona!
    
    testSection("MÚLTIPLES HIGH FIVES");
    FragTrap happyFrag("HappyBot");
    happyFrag.HighFivesGuys();
    happyFrag.HighFivesGuys();
    happyFrag.HighFivesGuys();
    happyFrag.attack("between high fives");
    happyFrag.HighFivesGuys();
    
    testSection("VALORES INICIALES VERIFICACIÓN");
    std::cout << "Frag1 - HP: " << frag1.getHitPoints() 
              << ", Energy: " << frag1.getEnergyPoints()
              << ", Damage: " << frag1.getAttackDamage() << std::endl;
    
    testSection("DESTRUCCIÓN CON CADENA");
    
    std::cout << "\n\033[1;32m✅ Todas las pruebas de FragTrap completadas!\033[0m" << std::endl;
    std::cout << "\033[1;33m(Los destructores se mostrarán a continuación)\033[0m" << std::endl;
    
    return 0;
}