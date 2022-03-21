#include "Fixed.hpp"
#include <iostream>
#include <cmath>

#defi
/*
void print_bits(Fixed a) {
	int bits = a.getRawBits();
	for (int i = 31; i >= 0; i--) {
		std::cout << ((bits & 1 << i) >> i);
	}
	std::cout << std::endl;
}
*/

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	setRawBits(0);
}

Fixed::Fixed(const float f) {
	int ipart = (int)f;
	float fpart = f - ipart;
	std::cout << "Float constructor called" << std::endl;
	_fp = (ipart << 16) + (fpart * 65536);
}

Fixed::Fixed(const int i) {
	std::cout << "Int constructor called" << std::endl;
	_fp = i << 16;
}

float Fixed::toFloat( void ) const {
	float ipart = _fp >> 16;
	int shifted;
	shifted = ((int)ipart << 16);
	float fpart = (float)(_fp - shifted) / 65536.;
	return ipart + fpart;
}

int	Fixed::toInt( void ) const {
	return _fp >> 16;
}	

Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy constructor called" << std::endl;
	setRawBits(fixed.getRawBits());
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	setRawBits(other.getRawBits());
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
	return _fp;
}

void Fixed::setRawBits( int const raw) {
	_fp = raw;
}

std::ostream &operator<<(std::ostream &out, const Fixed &f) {
	out << f.toFloat();
	return out;
}

