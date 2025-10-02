/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 09:59:30 by fosuna-g          #+#    #+#             */
/*   Updated: 2025/10/02 09:59:31 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP

# define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
    private:
        int _value;
        static const int _bit;
    public:
        Fixed(void);
        Fixed(const Fixed &oherFixed);
        ~Fixed(void);

        int getRawBits( void ) const;
        void setRawBits( int const raw );
        Fixed& operator=(const Fixed& other);
};

#endif