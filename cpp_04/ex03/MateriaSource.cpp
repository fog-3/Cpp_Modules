/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 11:09:38 by fosuna-g          #+#    #+#             */
/*   Updated: 2025/12/18 11:24:05 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < 4; i++)
	{
		if (other.templates[i])
			this->templates[i] = other.templates[i]->clone();
		else
			this->templates[i] = NULL;
	}
}



MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->templates[i] != NULL)
		{
			delete this->templates[i];
			this->templates[i] = NULL;
		}
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->templates[i] != NULL)
			{
				delete this->templates[i];
				this->templates[i] = NULL;
			}
		}
		
		for (int i = 0; i < 4; i++)
		{
			if (other.templates[i])
				this->templates[i] = other.templates[i]->clone();
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (!m) return;

	int i = 0;
	while (i < 4 && this->templates[i] != NULL)
		i++;
	if (i == 4)
	{
		std::cout << "MateriaSource is full of templates!" << std::endl;
	}
	else
	{
		this->templates[i] = m;
	}
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
    {
        if (this->templates[i] != NULL && this->templates[i]->getType() == type)
            return this->templates[i]->clone();
    }
    return 0;
}
