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

        int getRawBits( void ) const;
        void setRawBits( int const raw );
        Fixed& operator=(const Fixed& other);
        
        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif