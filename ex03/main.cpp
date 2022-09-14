#include <iostream>
#include "Point.hpp"
#include "utils.hpp"

# define COLOR BLUE

bool bsp(Point const a, Point const b, Point const c, Point const point);

void check_leaks() {
	std::cout << std::endl;
	system("leaks -q bsp");
}

int main(void) {
	atexit(&check_leaks);
	Point a(0, 0);
	Point b;
	b = a;
	std::cout << COLOR << "false: " << (bsp(Point(0, 0), Point(0, 0), Point(0, 0), Point(0, 0)) ? "true" : "false") << RESET << std::endl;
	std::cout << COLOR << "true: " << (bsp(Point(-3, 0), Point(3, 0), Point(0, 3), Point(0, 1)) ? "true" : "false") << RESET << std::endl;
	std::cout << COLOR << "false: " << (bsp(Point(-3, 0), Point(3, 0), Point(0, 3), Point(0, 0)) ? "true" : "false") << RESET << std::endl;
	std::cout << COLOR << "false: " << (bsp(Point(-3, 0), Point(3, 0), Point(0, 3), Point(0, 3)) ? "true" : "false") << RESET << std::endl;
	return 0;
}

# undef COLOR
