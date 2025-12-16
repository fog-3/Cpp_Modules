
#include "Animal.hpp"

#include <iostream>

Animal::Animal() : type("Animal") {
	std::cout << "Animal constructed" << std::endl;
}

Animal::Animal(const Animal& other) {
	std::cout << "Animal copy constructed" << std::endl;
	*this = other;
}

Animal& Animal::operator=(const Animal& other) {
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal destroyed" << std::endl;
}

void Animal::makeSound() const {
	std::cout << "* Generic animal noises *" << std::endl;
}

std::string Animal::getType() const {
	return this->type;
}
