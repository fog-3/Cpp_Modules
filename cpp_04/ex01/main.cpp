/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 09:06:24 by fosuna-g          #+#    #+#             */
/*   Updated: 2025/12/17 11:20:54 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>

#define N_ANIMALS 4 // Small number for easier reading, subject asks for more usually (e.g. 10 or 100)

int main()
{
	// ------------------------------------------------------------------
	// TEST 1: The "Subject" Test (Array of Animals)
	// ------------------------------------------------------------------
	std::cout << "=== TEST 1: Array of Animals (Subject Requirement) ===" << std::endl;
	
	const Animal* animals[N_ANIMALS];

	for (int i = 0; i < N_ANIMALS; i++)
	{
		if (i < N_ANIMALS / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	// Correct order: ~Dog() -> ~Brain() -> ~Animal()
	std::cout << "\n--- Deleting Animals ---" << std::endl;
	for (int i = 0; i < N_ANIMALS; i++)
	{
		delete animals[i];
	}

	// ------------------------------------------------------------------
	// TEST 2: The "Deep Copy" Proof
	// ------------------------------------------------------------------
	std::cout << "\n=== TEST 2: Deep Copy Proof ===" << std::endl;
	
	std::cout << "1. Creating original Dog" << std::endl;
	Dog* dog1 = new Dog();

	std::cout << "2. Creating copy Dog (copy constructor)" << std::endl;
	Dog* dog2 = new Dog(*dog1); // Uses Copy Constructor

	std::cout << "3. Deleting original Dog" << std::endl;
	delete dog1; 
	
	std::cout << "4. Checking if copy is still alive" << std::endl;
	// IF COPY WAS SHALLOW: dog2's brain would have been deleted with dog1.
	// Accessing it now would crash (segfault) or show garbage.
	// IF COPY WAS DEEP: dog2 is totally fine.
	
	dog2->makeSound(); // Should still work
	
	std::cout << "5. Deleting copy Dog" << std::endl;
	delete dog2;

	// ------------------------------------------------------------------
	// TEST 3: The "Deep Copy" Proof on the assignement method
	// ------------------------------------------------------------------
	std::cout << "\n=== TEST 3: Deep Copy Proof on the assignement method ===" << std::endl;
	
	std::cout << "1. Creating original Dogs" << std::endl;
	Dog* dog3 = new Dog();
	Dog* dog4 = new Dog();

	std::cout << "2. Creating copy Dog" << std::endl;
	*dog4 = *dog3; // Assig nement method

	std::cout << "3. Deleting original Dog" << std::endl;
	delete dog3; 
	
	std::cout << "4. Checking if copy is still alive" << std::endl;
	// IF COPY WAS SHALLOW: dog2's brain would have been deleted with dog1.
	// Accessing it now would crash (segfault) or show garbage.
	// IF COPY WAS DEEP: dog2 is totally fine.
	
	dog4->makeSound(); // Should still work
	
	std::cout << "5. Deleting copy Dog" << std::endl;
	delete dog4;

	return 0;
}
