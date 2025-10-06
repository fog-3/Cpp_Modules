
#include "ClapTrap.hpp"

void testSection(const std::string& title) {
    std::cout << "\n\033[1;36m=== " << title << " ===\033[0m" << std::endl;
}

int main() {
    testSection("CONSTRUCCIÓN Y DESTRUCCIÓN");
    ClapTrap robot1("R2-D2");
    ClapTrap robot2("C-3PO");
    ClapTrap robot3(robot1); // Constructor de copia
    
    testSection("ATAQUES BÁSICOS");
    robot1.attack("C-3PO");
    robot2.attack("R2-D2");
    
    testSection("DAÑO Y REPARACIÓN");
    robot1.takeDamage(5);
    robot1.beRepaired(3);
    
    robot2.takeDamage(8);
    robot2.beRepaired(2);
    
    testSection("CONSUMO DE ENERGÍA");
    // Hacer múltiples ataques para consumir energía
    for (int i = 0; i < 10; i++) {
        std::cout << "Ataque #" << (i + 1) << ": ";
        robot1.attack("target");
    }
    
    testSection("SIN PUNTOS DE VIDA");
    ClapTrap robot4("Bender");
    robot4.takeDamage(15); // Más daño que puntos de vida
    robot4.attack("alguien"); // No debería funcionar
    robot4.beRepaired(5);    // No debería funcionar
    
    testSection("OPERADOR DE ASIGNACIÓN");
    ClapTrap robot5("Wall-E");
    robot5 = robot1; // Operador de asignación
    robot5.attack("EVA");
    
    testSection("LÍMITES DE REPARACIÓN");
    ClapTrap robot6("Johnny5");
    robot6.takeDamage(2);
    robot6.beRepaired(1);
    robot6.beRepaired(1);
    robot6.beRepaired(1); // Última reparación con energía
    
    testSection("DESTRUCTORES");
    
    return 0;
}