#include <iostream>
#include <cstdlib>
#include "Fixed.hpp"

void check_leaks() {
	std::cout << std::endl;
	system("leaks -q fixed-point-3");
}

int main( void ) {
	atexit(&check_leaks);
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << std::boolalpha;

	std::cout << "a: " << a << std::endl;
	std::cout << "++a: " << ++a << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a++: " << a++ << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "max(a, b): " << Fixed::max( a, b ) << std::endl;

	std::cout << std::endl;

	std::cout << "min(a, b): " << Fixed::min( a, b ) << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a--: " << a-- << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "--a: " << --a << std::endl;
	std::cout << "a: " << a << std::endl;

	std::cout << std::endl;

	std::cout << "b < b: " << (b < b) << std::endl;
	std::cout << "b <= b: " << (b <= b) << std::endl;
	std::cout << "b > b: " << (b > b) << std::endl;
	std::cout << "b >= b: " << (b >= b) << std::endl;
	std::cout << "b == b: " << (b == b) << std::endl;
	std::cout << "b != b: " << (b != b) << std::endl;

	std::cout << std::endl;

	std::cout << "a < b: " << (a < b) << std::endl;
	std::cout << "a <= b: " << (a <= b) << std::endl;
	std::cout << "a > b: " << (a > b) << std::endl;
	std::cout << "a >= b: " << (a >= b) << std::endl;
	std::cout << "a == b: " << (a == b) << std::endl;
	std::cout << "a != b: " << (a != b) << std::endl;

	std::cout << std::endl;

	a = Fixed(3);
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;

	std::cout << std::endl;

	std::cout << "a + b: " << (a + b) << std::endl;
	std::cout << "a - b: " << (a - b) << std::endl;
	std::cout << "b - a: " << (b - a) << std::endl;
	std::cout << "a * b: " << (a * b) << std::endl;
	std::cout << "a / b: " << (a / b) << std::endl;
	std::cout << "b / a: " << (b / a) << std::endl;

	return 0;
}
