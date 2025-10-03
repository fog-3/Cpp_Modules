/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 09:59:48 by fosuna-g          #+#    #+#             */
/*   Updated: 2025/10/03 15:01:57 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int main() {
    // Triángulo con vértices (0,0), (10,0), (5,10)
    Point a(0, 0);
    Point b(10, 0);
    Point c(5, 10);
    
    // Puntos de prueba
    Point inside(5, 3);     // Debería estar dentro
    Point outside(1, 8);    // Debería estar fuera
    Point vertex(0, 0);     //  En el vértice (considerado dentro)
    Point edge(5, 0);       // En la arista (considerado dentro)
    Point outside2(3.5f, 8);     // Debería estar fuera

    
    std::cout << "Punto (5,3) dentro: " << bsp(a, b, c, inside) << std::endl;
    std::cout << "Punto (1,8) dentro: " << bsp(a, b, c, outside) << std::endl;
    std::cout << "Punto (0,0) dentro: " << bsp(a, b, c, vertex) << std::endl;
    std::cout << "Punto (5,0) dentro: " << bsp(a, b, c, edge) << std::endl;
    std::cout << "Punto (3.5, 8) dentro: " << bsp(a, b, c, outside2) << std::endl;

    return 0;
}
