#include <iostream>
#include <cstdlib>
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

	std::cout << std::boolalpha;

	std::cout << COLOR << "expect `false`, got: `" << bsp(Point(0, 0), Point(0, 0), Point(0, 0), Point(0, 0)) << "`" << RESET << std::endl;
	std::cout << COLOR << "expect `true`, got: `" << bsp(Point(-3, 0), Point(3, 0), Point(0, 3), Point(0, 1)) << "`" << RESET << std::endl;
	std::cout << COLOR << "expect `false`, got: `" << bsp(Point(-3, 0), Point(3, 0), Point(0, 3), Point(0, 0)) << "`" << RESET << std::endl;
	std::cout << COLOR << "expect `false`, got: `" << bsp(Point(-3, 0), Point(3, 0), Point(0, 3), Point(0, 3)) << "`" << RESET << std::endl;
	return 0;
}

# undef COLOR

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
