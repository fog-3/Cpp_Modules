#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed(void) : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &otherFixed)
{
    std::cout << "Copy constructor called" << std::endl;
    _value = otherFixed.getRawBits();
}

Fixed::Fixed(const int val)
{
    std::cout << "Int constructor called" << std::endl;
    _value = val << _fractionalBits;
}


Fixed::Fixed(const float val)
{
    std::cout << "Float constructor called" << std::endl;
    _value = roundf(val * (1 << this->_fractionalBits));
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) 
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        _value = other.getRawBits();
    }
    return *this;
}

int Fixed::getRawBits(void) const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return _value;
}

void Fixed::setRawBits(int const raw)
{
    _value = raw;
}

float   Fixed::toFloat(void) const
{
    return (float)_value / (1 << this->_fractionalBits);
}

int     Fixed::toInt(void) const
{
    return (int)(_value >> _fractionalBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}
