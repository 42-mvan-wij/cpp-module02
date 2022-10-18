#include <iostream>
#include <cstdlib>
#include "Fixed.hpp"
#include "utils.hpp"

# define COLOR BLUE

void check_leaks() {
	std::cout << std::endl;
	system("leaks -q fixed-point-3");
}

int main( void ) {
	atexit(&check_leaks);
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << std::boolalpha;

	std::cout << COLOR << "a: " << a << RESET << std::endl;
	std::cout << COLOR << "++a: " << ++a << RESET << std::endl;
	std::cout << COLOR << "a: " << a << RESET << std::endl;
	std::cout << COLOR << "a++: " << a++ << RESET << std::endl;
	std::cout << COLOR << "a: " << a << RESET << std::endl;
	std::cout << COLOR << "b: " << b << RESET << std::endl;
	std::cout << COLOR << "max(a, b): " << Fixed::max( a, b ) << RESET << std::endl;

	std::cout << std::endl;

	std::cout << COLOR << "b < b: " << (b < b) << RESET << std::endl;
	std::cout << COLOR << "b <= b: " << (b <= b) << RESET << std::endl;
	std::cout << COLOR << "b > b: " << (b > b) << RESET << std::endl;
	std::cout << COLOR << "b >= b: " << (b >= b) << RESET << std::endl;
	std::cout << COLOR << "b == b: " << (b == b) << RESET << std::endl;

	std::cout << std::endl;

	std::cout << COLOR << "a < b: " << (a < b) << RESET << std::endl;
	std::cout << COLOR << "a <= b: " << (a <= b) << RESET << std::endl;
	std::cout << COLOR << "a > b: " << (a > b) << RESET << std::endl;
	std::cout << COLOR << "a >= b: " << (a >= b) << RESET << std::endl;
	std::cout << COLOR << "a == b: " << (a == b) << RESET << std::endl;

	std::cout << std::endl;

	std::cout << COLOR << "min(a, b): " << Fixed::min( a, b ) << RESET << std::endl;
	std::cout << COLOR << "a: " << a << RESET << std::endl;
	std::cout << COLOR << "a--: " << a-- << RESET << std::endl;
	std::cout << COLOR << "a: " << a << RESET << std::endl;
	std::cout << COLOR << "--a: " << --a << RESET << std::endl;
	std::cout << COLOR << "a: " << a << RESET << std::endl;
	return 0;
}

# undef COLOR
