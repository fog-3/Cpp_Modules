/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 09:44:31 by fosuna-g          #+#    #+#             */
/*   Updated: 2025/09/18 09:44:32 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP

# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie {
	private:
		std::string _name;
	public:
		Zombie(std::string zombieName);
		~Zombie(void);
		void announce(void);
};

void 	randomChump(std::string name);
Zombie 	*newZombie(std::string name);

#endif
