#include <iostream>
#include <cstdlib>
#include "Fixed.hpp"
#include "utils.hpp"

# define COLOR BLUE

void check_leaks() {
	std::cout << std::endl;
	system("leaks -q fixed-point");
}

int main() {
	atexit(&check_leaks);
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;
	int a_raw = a.getRawBits();
	std::cout << COLOR << a_raw << RESET << std::endl;
	int b_raw = b.getRawBits();
	std::cout << COLOR << b_raw << RESET << std::endl;
	int c_raw = c.getRawBits();
	std::cout << COLOR << c_raw << RESET << std::endl;
	return 0;
}

# undef COLOR
