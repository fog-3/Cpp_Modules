/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 09:58:30 by fosuna-g          #+#    #+#             */
/*   Updated: 2025/10/02 09:58:31 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

class Harl{
	private:
		void debug(void);
		void info(void);
		void warning (void);
		void error(void);
	public:
		Harl(void);
		~Harl(void);
		void complain(std::string level);
};

#endif
