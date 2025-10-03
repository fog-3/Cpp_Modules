/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 09:59:40 by fosuna-g          #+#    #+#             */
/*   Updated: 2025/10/03 11:02:07 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed(void) : _value(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &otherFixed)
{
	//std::cout << "Copy constructor called" << std::endl;
	_value = otherFixed.getRawBits();
}

Fixed::Fixed(const int val)
{
	//std::cout << "Int constructor called" << std::endl;
	_value = val << _fractionalBits;
}


Fixed::Fixed(const float val)
{
	//std::cout << "Float constructor called" << std::endl;
	_value = roundf(val * (1 << this->_fractionalBits));
}

Fixed::~Fixed(void)
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) 
{
	//std::cout << "Copy assignment operator called" << std::endl;
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

bool  Fixed::operator>(const Fixed& other) const {
	return (this->_value > other.getRawBits());
}

bool Fixed::operator<(const Fixed& other) const {
	return (this->_value < other.getRawBits());
}

bool Fixed::operator>=(const Fixed& other) const {
	return (this->_value >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed& other) const {
	return (this->_value <= other.getRawBits());
}

bool Fixed::operator==(const Fixed& other) const {
	return (this->_value == other.getRawBits());
}

bool Fixed::operator!=(const Fixed& other) const {
	return (this->_value != other.getRawBits());
}

Fixed Fixed::operator+(const Fixed& other){
	Fixed res;
	res.setRawBits(this->_value + other.getRawBits());
	return res;
}

Fixed Fixed::operator-(const Fixed& other){
	Fixed res;
	res.setRawBits(this->_value - other.getRawBits());
	return res;
}

Fixed Fixed::operator*(const Fixed& other){
	Fixed res;
	long temp = (long)this->_value * (long)other.getRawBits();
	res.setRawBits(temp >> this->_fractionalBits);
	return res;
}

Fixed Fixed::operator/(const Fixed& other){
	Fixed res;
	if (other.getRawBits() == 0){
		std::cerr << "\033[31mError:\033[0m You're a bad boy, stop trying to divide by zero. >:c" << std::endl;
		res.setRawBits(0);
	} else {		
		long temp = ((long)this->_value << this->_fractionalBits);
		res.setRawBits(temp / other.getRawBits());
	}
	return res;
}

Fixed& Fixed::operator++(){
	_value += 1;
	return *this;
}

Fixed Fixed::operator++(int){
	Fixed temp(*this);
	_value += 1;
	return temp;
}

Fixed& Fixed::operator--(){
	_value -= 1;
	return *this;
}

Fixed Fixed::operator--(int){
	Fixed temp(*this);
    _value -= 1;
    return temp;
}

Fixed& Fixed::min(Fixed& fixed1, Fixed& fixed2){
	return (fixed1 < fixed2) ? fixed1 : fixed2;
}

const Fixed& Fixed::min(const Fixed& fixed1,const Fixed& fixed2){
	return (fixed1 < fixed2) ? fixed1 : fixed2;
}

Fixed& Fixed::max(Fixed& fixed1, Fixed& fixed2){
	return (fixed1 > fixed2) ? fixed1 : fixed2;
}

const Fixed& Fixed::max(const Fixed& fixed1,const Fixed& fixed2){
	return (fixed1 > fixed2) ? fixed1 : fixed2;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}
