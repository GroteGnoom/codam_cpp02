#include <iostream>
#include "Point.hpp"

int main( void ) {
	Point a;
	Point b(0,1);
	Point c(1,0);
	
	Point t1(1,1);
	Point t2(.1,.1);
	Point t3(.49,.49);
	Point t4(.5,.5);
	Point t5(0,0);

	std::cout << a << std::endl;
	std::cout << b << std::endl;

	std::cout << bsp(a,b,c,t1) << std::endl;
	std::cout << bsp(a,b,c,t2) << std::endl;
	std::cout << bsp(a,b,c,t3) << std::endl;
	std::cout << bsp(a,b,c,t4) << std::endl;
	std::cout << bsp(a,b,c,t5) << std::endl;

	return 0;
}
