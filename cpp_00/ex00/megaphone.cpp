/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:04:50 by fosuna-g          #+#    #+#             */
/*   Updated: 2025/09/16 11:04:51 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>

bool ft_is_minus(char c)
{
	return (c >= 'a' && c <= 'z');
}

int	ft_strlen(char *str)
{
	int	i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

int main(int argc, char *argv[]) {
	if (argc > 1)
	{	
		for (int i = 1; i < argc; ++i) {
			for (int j = 0; j < ft_strlen(argv[i]); j++){
				if (ft_is_minus(argv[i][j]))
					std::cout << (char)(argv[i][j] - 32);
				else
					std::cout << argv[i][j];
			}
		}
		std::cout << std::endl;
	} 
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;

	return 0;
}