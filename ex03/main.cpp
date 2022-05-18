#include <iostream>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

__attribute__((destructor))
void check_leaks() {
	std::cout << std::endl;
	system("leaks -q bsp");
}

int main(void) {
	std::cout << "false: " << (bsp(Point(0, 0), Point(0, 0), Point(0, 0), Point(0, 0)) ? "true" : "false") << std::endl;
	std::cout << "true: " << (bsp(Point(-3, 0), Point(3, 0), Point(0, 3), Point(0, 1)) ? "true" : "false") << std::endl;
	std::cout << "false: " << (bsp(Point(-3, 0), Point(3, 0), Point(0, 3), Point(0, 0)) ? "true" : "false") << std::endl;
	std::cout << "false: " << (bsp(Point(-3, 0), Point(3, 0), Point(0, 3), Point(0, 3)) ? "true" : "false") << std::endl;
	return 0;
}
