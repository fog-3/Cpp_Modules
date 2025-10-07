/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 09:12:24 by fosuna-g          #+#    #+#             */
/*   Updated: 2025/10/07 10:08:51 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

class FragTrap : public ClapTrap{
	public:
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& other);
		~FragTrap();
		
		FragTrap& operator=(const FragTrap& other);

		void HighFivesGuys();
};

#endif