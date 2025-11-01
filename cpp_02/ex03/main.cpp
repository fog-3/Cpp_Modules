/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 09:59:48 by fosuna-g          #+#    #+#             */
/*   Updated: 2025/11/01 21:05:39 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

void    print_boolean(bool is_in)
{
    if (is_in)
        std::cout << "the point is in.";
    else
        std::cout << "the point is out.";
}

int main() {
    Point a(0, 0);
    Point b(10, 0);
    Point c(5, 10);
    
    // Prove points
    Point inside(5, 3);          // It should be in
    Point outside(1, 8);         // It should be out
    Point vertex(0, 0);          // On the vertex (considered out)
    Point edge(5, 0);            // On the edge (cosidered out)
    Point outside2(3.5f, 8);     // It should be out
    Point inside2(6.5f, 5);       // It should be in

    std::cout << "Triangle A(0,0), B(10,0), C(5,10):" << std::endl;
    std::cout << "Point (5,3): " << bsp(a, b, c, inside) << std::endl;
    std::cout << "Point (1,8): " << bsp(a, b, c, outside) << std::endl;
    std::cout << "Point (0,0): " << bsp(a, b, c, vertex) << std::endl;
    std::cout << "Point (5,0): " << bsp(a, b, c, edge) << std::endl;
    std::cout << "Point (3.5,8): " << bsp(a, b, c, outside2) << std::endl;
    std::cout << "Point (6.5,5): " << bsp(a, b, c, inside2) << std::endl;

    return 0;
}
