#include <iostream>
#include "Fixed.hpp"
#include "utils.hpp"

# define COLOR YELLOW

Fixed::Fixed(): fixedPointValue(0) {
	std::cout << COLOR << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(Fixed const &src): fixedPointValue(src.fixedPointValue) {
	std::cout << COLOR << "Copy constructor called" << RESET << std::endl;
}

Fixed &Fixed::operator=(Fixed const &rhs) {
	std::cout << COLOR << "Copy assignment operator called" << RESET << std::endl;
	if (this == &rhs)
		return *this;
	this->fixedPointValue = rhs.fixedPointValue;
	return *this;
}

Fixed::~Fixed() {
	std::cout << COLOR << "Destructor called" << RESET << std::endl;
}

int Fixed::getRawBits() const {
	std::cout << COLOR << "getRawBits member function called" << RESET << std::endl;
	return this->fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
	std::cout << COLOR << "setRawBits member function called" << RESET << std::endl;
	this->fixedPointValue = raw;
}

# undef COLOR
