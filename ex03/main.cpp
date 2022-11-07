#include <iostream>
#include <cstdlib>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

void check_leaks() {
	std::cout << std::endl;
	std::system("leaks -q bsp");
}

int main(void) {
	std::atexit(&check_leaks);

	Point a;
	Point b(5, 1);
	Point c(b);

	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;

	std::cout << std::boolalpha;

	std::cout << "expect: false, got: " << bsp(Point(0, 0), Point(0, 0), Point(0, 0), Point(0, 0)) << std::endl;
	std::cout << "expect: false, got: " << bsp(Point(-3, 0), Point(3, 0), Point(3, 0), Point(0, 1)) << std::endl;
	std::cout << "expect: true, got: " << bsp(Point(-3, 0), Point(3, 0), Point(0, 3), Point(0, 1)) << std::endl;
	std::cout << "expect: true, got: " << bsp(Point(-7, 5), Point(-9, 5), Point(12, 0), Point(8, 1)) << std::endl;
	std::cout << "expect: false, got: " << bsp(Point(-3, 0), Point(3, 0), Point(0, 3), Point(0, 5)) << std::endl;
	std::cout << "expect: false, got: " << bsp(Point(-3, 0), Point(3, 0), Point(0, 3), Point(0, 0)) << std::endl;
	std::cout << "expect: false, got: " << bsp(Point(-3, 0), Point(3, 0), Point(0, 3), Point(0, 3)) << std::endl;

	return 0;
}

/*

3|      C
2|
1|      P
0|A           B
----------------
 |0 1 2 3 4 5 6


3|      C
2|
1|
0|A     P     B
----------------
 |0 1 2 3 4 5 6

*/
