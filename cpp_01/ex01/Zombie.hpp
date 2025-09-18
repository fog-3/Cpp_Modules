/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 09:44:48 by fosuna-g          #+#    #+#             */
/*   Updated: 2025/09/18 09:44:49 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP

# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <ctype.h>

class Zombie {
	private:
		std::string _name;
	public:
		Zombie(std::string zombieName);
		Zombie(void);
		~Zombie(void);
		void announce(void);
};

Zombie* zombieHorde( int N, std::string name );

#endif
