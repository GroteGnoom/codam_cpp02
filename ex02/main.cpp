#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;

	std::cout << "max:" << std::endl;
	std::cout << Fixed::max( a, a ) << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << "min:" << std::endl;
	std::cout << Fixed::min( a, a ) << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;

	std::cout << "going three down, two up:" << std::endl;
	std::cout << --a << std::endl;
	std::cout << --a << std::endl;
	std::cout << --a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << ++a << std::endl;

	std::cout << "comparisons:" << std::endl;
	std::cout << (a < a) << std::endl;
	std::cout << (a == a) << std::endl;
	std::cout << (a != a) << std::endl;
	std::cout << (a > a) << std::endl;
	std::cout << (a >= a) << std::endl;
	std::cout << (a <= a) << std::endl;

	a = Fixed(3);
	std::cout << "arithmetic:" << std::endl;
	std::cout << (a * a) << std::endl;
	std::cout << (a / a) << std::endl;
	std::cout << (a + a) << std::endl;
	std::cout << (a - a) << std::endl;
	return 0;
}
