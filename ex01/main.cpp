#include <iostream>
#include <cstdlib>
#include "Fixed.hpp"
#include "utils.hpp"

# define COLOR BLUE

void check_leaks() {
	std::cout << std::endl;
	system("leaks -q fixed-point-2");
}

int main( void ) {
	atexit(&check_leaks);

	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );

	std::cout << std::endl;

	std::cout << COLOR << "a is " << a << RESET << std::endl;
	std::cout << COLOR << "b is " << b << RESET << std::endl;
	std::cout << COLOR << "c is " << c << RESET << std::endl;
	std::cout << COLOR << "d is " << d << RESET << std::endl;

	std::cout << std::endl;

	std::cout << COLOR << "a is " << a.toInt() << " as integer" << RESET << std::endl;
	std::cout << COLOR << "b is " << b.toInt() << " as integer" << RESET << std::endl;
	std::cout << COLOR << "c is " << c.toInt() << " as integer" << RESET << std::endl;
	std::cout << COLOR << "d is " << d.toInt() << " as integer" << RESET << std::endl;

	std::cout << std::endl;

	std::cout << COLOR << "a is " << a.toFloat() << " as float" << RESET << std::endl;
	std::cout << COLOR << "b is " << b.toFloat() << " as float" << RESET << std::endl;
	std::cout << COLOR << "c is " << c.toFloat() << " as float" << RESET << std::endl;
	std::cout << COLOR << "d is " << d.toFloat() << " as float" << RESET << std::endl;

	std::cout << std::endl;

	return 0;
}

# undef COLOR
