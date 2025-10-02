/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 09:58:45 by fosuna-g          #+#    #+#             */
/*   Updated: 2025/10/02 09:58:56 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char *argv[])
{
    Harl harl;

    if (argc != 2){
        std::cout << "\033[31mERROR\033[0m: incorrect number of arguments" << std::endl;
        std::cout << "Expected 1 argument" << std::endl;
        return 1;
    }
    harl.complain(argv[1]);
    return 0;
}
