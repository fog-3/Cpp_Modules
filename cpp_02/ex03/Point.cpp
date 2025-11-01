/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:13:39 by fosuna-g          #+#    #+#             */
/*   Updated: 2025/11/01 21:01:33 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void): _x(0), _y(0)
{
	
}

Point::Point(const float valx, const float valy): _x(valx), _y(valy)
{
}

Point::Point(const Fixed valx, const Fixed valy): _x(valx), _y(valy)
{	
}

Point::Point(const Point& otherPoint): _x(otherPoint.get_x()), _y(otherPoint.get_y())
{
}

Point::~Point(void)
{	
}

Point&  Point::operator=(const Point& other)
{
	if (this != &other) {
		this->~Point();
		new (this) Point(other);		
	}
	return *this;
}

bool  Point::operator==(const Point& other) const
{
	return (this->get_x() == other.get_x() && this->get_y() == other.get_y());
}

Fixed Point::get_x() const {
	return _x;
}

Fixed Point::get_y() const {
	return _y;
}
