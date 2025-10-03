/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:13:41 by fosuna-g          #+#    #+#             */
/*   Updated: 2025/10/03 14:22:26 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"
#include <iostream>
#include <string>

class Point
{
  private:
    const Fixed _x;
    const Fixed _y;
  public:
    Point(void);
    Point(const float valx, const float valy);
    Point(const Point& otherPoint);
    ~Point(void);

    Point&  operator=(const Point& other);
    bool    operator==(const Point& other) const;

    Fixed get_x(void) const;
    Fixed get_y(void) const;
};

Fixed   triangleArea(Point const a, Point const b, Point const c);
bool    bsp(Point const a, Point const b, Point const c, Point const point);

#endif
