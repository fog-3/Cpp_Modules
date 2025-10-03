/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:13:33 by fosuna-g          #+#    #+#             */
/*   Updated: 2025/10/03 14:54:03 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed triangleArea(Point const a, Point const b, Point const c){
	Fixed term1(a.get_x() * (b.get_y() - c.get_y()));
	Fixed term2(b.get_x() * (c.get_y() - a.get_y()));
	Fixed term3(c.get_x() * (a.get_y() - b.get_y()));

	
	return (term1 + term2 + term3) / Fixed(2.0f);
}

bool    bsp(Point const a, Point const b, Point const c, Point const point){
	if (a == b || a == c || c == b){
		std::cerr << "\033[31mError:\033[0m if two point are the same you can't shape a triangle." << std::endl;
		return false;
	}
	Fixed totalArea(triangleArea(a, b, c));
	Fixed area1(triangleArea(point, b, c));
	Fixed area2(triangleArea(a, point, c));
	Fixed area3(triangleArea(a, b, point));

	bool sameSign1 = (totalArea * area1 >= 0);
    bool sameSign2 = (totalArea * area2 >= 0);
    bool sameSign3 = (totalArea * area3 >= 0);
	
	return sameSign1 && sameSign2 && sameSign3;
}
