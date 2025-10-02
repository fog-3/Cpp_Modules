/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 09:59:44 by fosuna-g          #+#    #+#             */
/*   Updated: 2025/10/02 13:08:53 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP

# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
	private:
		int _value;
		static const int _fractionalBits;
	public:
		Fixed(void);
		Fixed(const int val);
		Fixed(const float val);
		Fixed(const Fixed &oherFixed);
		~Fixed(void);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		
		/* Comparison Operators */
		Fixed&	operator>(const Fixed& other);
		Fixed&	operator<(const Fixed& other);
		Fixed&	operator>=(const Fixed& other);
		Fixed&	operator<=(const Fixed& other);
		Fixed&	operator==(const Fixed& other);
		Fixed&	operator!=(const Fixed& other);
		
		/* Arithmetic operators */
		Fixed&	operator=(const Fixed& other);
		Fixed&	operator+(const Fixed& other);
		Fixed&	operator-(const Fixed& other);
		Fixed&	operator*(const Fixed& other);
		Fixed&	operator/(const Fixed& other);

		/* Special Arithmetic operators */
		Fixed&	operator++();
		Fixed	operator++(int);
		Fixed&	operator--();
		Fixed	operator--(int);
		
		float	toFloat( void ) const;
		int		toInt( void ) const;

		static Fixed& min(Fixed& fixed1, Fixed& fixed2);
		static Fixed& min(const Fixed& fixed1,const Fixed& fixed2);
		static Fixed& max(Fixed& fixed1, Fixed& fixed2);
		static Fixed& max(const Fixed& fixed1,const Fixed& fixed2);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif