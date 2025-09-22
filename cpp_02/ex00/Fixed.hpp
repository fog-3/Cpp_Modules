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