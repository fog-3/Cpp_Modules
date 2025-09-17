#include "Zombie.hpp"

Zombie::Zombie(std::string zombieName){
    this->_name = zombieName;
    std::cout << "Zombie " << zombieName << " created" << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << "Zombie " << _name << " destroyed" << std::endl;
}

void Zombie::announce(void){
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
