/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 09:06:24 by fosuna-g          #+#    #+#             */
/*   Updated: 2025/12/18 11:05:15 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	// -------------------------------------------------------------------------
	// 1. SUBJECT TEST (The Correct Way)
	// -------------------------------------------------------------------------
	std::cout << "\n-------- CORRECT ANIMAL TEST --------" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	
	i->makeSound(); // Will output the cat sound! (Correct)
	j->makeSound(); // Will output the dog sound! (Correct)
	meta->makeSound();

	// -------------------------------------------------------------------------
	// 2. WRONG ANIMAL TEST (The "What if" Scenario)
	// -------------------------------------------------------------------------
	std::cout << "\n-------- WRONG ANIMAL TEST --------" << std::endl;
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << wrongCat->getType() << " " << std::endl;

	wrongCat->makeSound(); 
	
	wrongMeta->makeSound();

	// -------------------------------------------------------------------------
	// 3. CLEANUP
	// -------------------------------------------------------------------------
	std::cout << "\n-------- ANIMAL DESTRUCTORS --------" << std::endl;
	delete meta;
	delete j;
	delete i;
	delete wrongMeta;
	delete wrongCat;

	return 0;
}
