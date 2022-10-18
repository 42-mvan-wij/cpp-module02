#include <iostream>
#include <cstdlib>
#include "Fixed.hpp"

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

	std::cout << "a_raw: " << a.getRawBits() << std::endl;
	std::cout << "b_raw: " << b.getRawBits() << std::endl;
	std::cout << "c_raw: " << c.getRawBits() << std::endl;

	std::cout << std::endl;

	a.setRawBits( 42 );
	std::cout << "a_raw: " << a.getRawBits() << std::endl;
	std::cout << "b_raw: " << b.getRawBits() << std::endl;
	std::cout << "c_raw: " << c.getRawBits() << std::endl;
	return 0;
}
