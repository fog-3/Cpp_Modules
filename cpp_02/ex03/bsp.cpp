/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:13:33 by fosuna-g          #+#    #+#             */
/*   Updated: 2025/11/01 21:00:21 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed cross_product(Point const a, Point const b, Point const p){
	Point v1(b.get_x() - a.get_x(), b.get_y() - a.get_y());
	Point v2(p.get_x() - a.get_x(), p.get_y() - a.get_y());
	return v1.get_x() * v2.get_y() - v1.get_y() * v2.get_x();
}

bool    bsp(Point const a, Point const b, Point const c, Point const point){
	if (a == b || a == c || c == b){
		std::cerr << "\033[31mError:\033[0m if two point are the same you can't shape a triangle." << std::endl;
		return false;
	}

	Fixed cross1 = cross_product(a, b, point);
	Fixed cross2 = cross_product(b, c, point);
	Fixed cross3 = cross_product(c, a, point);

	if (cross1 == 0 || cross2 == 0 || cross3 == 0)
		return false;

	bool has_positive = cross1 > 0 || cross2 > 0 || cross3 > 3;
	bool has_negative = cross1 < 0 || cross2 < 0 || cross3 < 3;
	
	return !(has_positive && has_negative);
}
