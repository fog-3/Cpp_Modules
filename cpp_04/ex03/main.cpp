/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 11:09:32 by fosuna-g          #+#    #+#             */
/*   Updated: 2026/02/26 19:13:18 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

void printTitle(std::string title) {
	std::cout << "\n==============================================" << std::endl;
	std::cout << title << std::endl;
	std::cout << "==============================================" << std::endl;
}

int main()
{
	// ---------------------------------------------------------------------------------
	// TEST 1: SUBJECT MANDATORY TEST
	// ---------------------------------------------------------------------------------
	printTitle("TEST 1: Subject Mandatory Test");
	
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	// ---------------------------------------------------------------------------------
	// TEST 2: DEEP COPY & ASSIGNMENT OPERATOR
	// ---------------------------------------------------------------------------------
	printTitle("TEST 2: Deep Copy Character");

	// 1. Create a Master Character with full inventory
	Character* original = new Character("Original");
	IMateriaSource* factory = new MateriaSource();
	factory->learnMateria(new Ice());
	
	// (We have to save the pointer to delete it later, avoiding leaks for this specific test)
	AMateria* itemToDrop = factory->createMateria("ice");
	original->equip(itemToDrop);
	original->equip(factory->createMateria("ice"));

	// 2. Test Copy Constructor
	std::cout << "[INFO] Creating copy using Copy Constructor..." << std::endl;
	Character* copy = new Character(*original);

	// 3. Test Deep Copy Logic
	std::cout << "[INFO] Modifying Original (Unequip slot 0)..." << std::endl;
	original->unequip(0); // Original loses item
	delete itemToDrop; // We delete this item to avoid memory leaks

	std::cout << "[INFO] Testing Copy (Should still have item in slot 0)..." << std::endl;
	// If shallow copy: Copy would point to NULL or deleted memory -> CRASH
	// If deep copy: Copy has its own independent Ice -> PRINTS ICE MESSAGE
	copy->use(0, *original); 

	delete original;
	delete copy;
	delete factory;

	// ---------------------------------------------------------------------------------
	// TEST 3: INVENTORY LIMITS & UNEQUIP MEMORY MANAGEMENT
	// ---------------------------------------------------------------------------------
	printTitle("TEST 3: Inventory Limits & Unequip");

	ICharacter* cloud = new Character("Cloud");
	IMateriaSource* spellBook = new MateriaSource();
	std::cout << "[INFO] Learning all the MateriaSource (4 slots)..." << std::endl;
	spellBook->learnMateria(new Ice());
	spellBook->learnMateria(new Cure());
	spellBook->learnMateria(new Cure());
	spellBook->learnMateria(new Cure());
	std::cout << "[INFO] Trying to learn 5th materia (Should do nothing)..." << std::endl;
	spellBook->learnMateria(new Cure());


	std::cout << "[INFO] Filling inventory (4 slots)..." << std::endl;
	cloud->equip(spellBook->createMateria("ice")); // 0
	AMateria* itemToDrop2 = spellBook->createMateria("cure");
	cloud->equip(itemToDrop2); // 1
	cloud->equip(spellBook->createMateria("ice")); // 2
	cloud->equip(spellBook->createMateria("cure")); // 3

	std::cout << "[INFO] Trying to equip 5th item (Should do nothing)..." << std::endl;
	AMateria* extra = spellBook->createMateria("ice");
	cloud->equip(extra); // Inventory full, extra is NOT equipped

	std::cout << "[INFO] Using all items..." << std::endl;
	cloud->use(0, *cloud);
	cloud->use(3, *cloud);
	
	std::cout << "[INFO] Unequipping slot 1..." << std::endl;
	// SAVE POINTER FIRST to avoid leak (Subject says unequip must not delete)
	// Note: Since ICharacter doesn't have getters, we technically "lose" it here 
	// unless we kept a reference to 'extra' or modified the class. 
	// For strict subject compliance, we just accept the unequip logic.
	cloud->unequip(1); 
	
	cloud->use(1, *cloud); // Should do nothing (empty slot)

	// CLEANUP
	delete itemToDrop2;
	delete extra;
	delete cloud;
	delete spellBook;

	return 0;
}
