#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	setRawBits(0);
}

Fixed::Fixed(const float f) {
	int ipart = (int)f;
	float fpart = f - ipart;
	std::cout << "Float constructor called" << std::endl;
	_fp = (ipart << _fract) + roundf((fpart * (1 << _fract)));
}

Fixed::Fixed(const int i) {
	std::cout << "Int constructor called" << std::endl;
	_fp = i << _fract;
}

float Fixed::toFloat( void ) const {
	float ipart = _fp >> _fract;
	int shifted;
	shifted = ((int)ipart << _fract);
	float fpart = (float)(_fp - shifted) / (float)(1 << _fract);
	return ipart + fpart;
}

int	Fixed::toInt( void ) const {
	return _fp >> _fract;
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

Fixed Fixed::operator/(const Fixed &other) {
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) {
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator+(const Fixed &other) {
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) {
	return Fixed(this->toFloat() - other.toFloat());
}

bool Fixed::operator<=(const Fixed &other) {
	return this->toFloat() <= other.toFloat();
}

bool Fixed::operator>=(const Fixed &other) {
	return this->toFloat() >= other.toFloat();
}

bool Fixed::operator<(const Fixed &other) {
	return this->toFloat() < other.toFloat();
}

bool Fixed::operator>(const Fixed &other) {
	return this->toFloat() > other.toFloat();
}

bool Fixed::operator!=(const Fixed &other) {
	return this->toFloat() != other.toFloat();
}
bool Fixed::operator==(const Fixed &other) {
	return this->toFloat() == other.toFloat();
}
Fixed &Fixed::operator--() {
	_fp--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed tmp = *this;
	_fp--;
	return tmp;
}

Fixed &Fixed::operator++() {
	_fp++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp = *this;
	_fp++;
	return tmp;
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

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2) {
	if (f1.toFloat() < f2.toFloat()) {
		return f2;
	}
	return f1;
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2) {
	if (f1.toFloat() < f2.toFloat()) {
		return f2;
	}
	return f1;
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2) {
	if (f1.toFloat() > f2.toFloat()) {
		return f2;
	}
	return f1;
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2) {
	if (f1.toFloat() > f2.toFloat()) {
		return f2;
	}
	return f1;
}

