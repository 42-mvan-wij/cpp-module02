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
	std::cout << COLOR << a << RESET << std::endl;
	std::cout << COLOR << ++a << RESET << std::endl;
	std::cout << COLOR << a << RESET << std::endl;
	std::cout << COLOR << a++ << RESET << std::endl;
	std::cout << COLOR << a << RESET << std::endl;
	std::cout << COLOR << b << RESET << std::endl;
	std::cout << COLOR << Fixed::max( a, b ) << RESET << std::endl;

	std::cout << std::endl;
	std::cout << COLOR << Fixed::min( a, b ) << RESET << std::endl;
	std::cout << COLOR << a << RESET << std::endl;
	std::cout << COLOR << a-- << RESET << std::endl;
	std::cout << COLOR << a << RESET << std::endl;
	std::cout << COLOR << --a << RESET << std::endl;
	std::cout << COLOR << a << RESET << std::endl;
	return 0;
}

# undef COLOR
