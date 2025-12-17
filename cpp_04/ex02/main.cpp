/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 09:06:24 by fosuna-g          #+#    #+#             */
/*   Updated: 2025/12/17 11:57:56 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>

int main()
{
    // const Animal* meta = new Animal(); // <--- THIS NOW GIVE A COMPILER ERROR!
    // Error: "Cannot instantiate abstract class Animal"
	
    const Animal* j = new Dog(); // This still works perfectly
    const Animal* i = new Cat(); // This still works perfectly

    j->makeSound();
    i->makeSound();

    delete j;
    delete i;

	return 0;
}
