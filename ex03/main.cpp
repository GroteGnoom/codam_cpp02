#include <iostream>
#include "Point.hpp"

int main( void ) {
	Point a;
	Point b(0, 1);
	Point c(1, 0);
	
	Point a2(10, 10);
	Point b2(10, 11);
	Point c2(11, 10);
	
	Point a3(1, 2);
	Point b3(3, 4);
	Point c3(5, 3);
	
	Point t1(1,1);
	Point t2(.1,.1);
	Point t3(.49,.49);
	Point t4(.5,.5);
	Point t5(0,0);

	Point t21(11,11);
	Point t22(10.1,10.1);
	Point t23(10.49,10.49);
	Point t24(10.5,10.5);
	Point t25(10,10);

	Point t31(1,1);
	Point t32(3,3.99);
	Point t33(3,4);

	Point a4;
	Point c4(0, 1);
	Point b4(1, 0);
	
	std::cout << a << std::endl;
	std::cout << b << std::endl;

	std::cout << "Triangle between origin, (0,1) and (1,0):" << std::endl;
	std::cout << bsp(a,b,c,t1) << std::endl;
	std::cout << bsp(a,b,c,t2) << std::endl;
	std::cout << bsp(a,b,c,t3) << std::endl;
	std::cout << bsp(a,b,c,t4) << std::endl;
	std::cout << bsp(a,b,c,t5) << std::endl;

	std::cout << "Same triangle, shifted by 10:" << std::endl;
	std::cout << bsp(a2,b2,c2,t21) << std::endl;
	std::cout << bsp(a2,b2,c2,t22) << std::endl;
	std::cout << bsp(a2,b2,c2,t23) << std::endl;
	std::cout << bsp(a2,b2,c2,t24) << std::endl;
	std::cout << bsp(a2,b2,c2,t25) << std::endl;

	std::cout << "Triangle between (1,2), (3,4) and (5,3):" << std::endl;
	std::cout << bsp(a3,b3,c3,t31) << std::endl;
	std::cout << bsp(a3,b3,c3,t32) << std::endl;
	std::cout << bsp(a3,b3,c3,t33) << std::endl;

	std::cout << "First triangle in reverse:" << std::endl;
	std::cout << bsp(a4,b4,c4,t1) << std::endl;
	std::cout << bsp(a4,b4,c4,t2) << std::endl;
	std::cout << bsp(a4,b4,c4,t3) << std::endl;
	std::cout << bsp(a4,b4,c4,t4) << std::endl;
	std::cout << bsp(a4,b4,c4,t5) << std::endl;

	return 0;
}
