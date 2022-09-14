#include <iostream>
#include "Fixed.hpp"
#include "utils.hpp"

# define COLOR YELLOW

Fixed::Fixed() {
	std::cout << COLOR << "Default constructor called" << RESET << std::endl;
	this->fixedPointValue = 0;
}

Fixed::Fixed(Fixed const &src) {
	std::cout << COLOR << "Copy constructor called" << RESET << std::endl;
	this->fixedPointValue = src.fixedPointValue;
}

Fixed &Fixed::operator=(Fixed const &rhs) {
	std::cout << COLOR << "Copy assignment operator called" << RESET << std::endl;
	if (this != &rhs) {
		this->fixedPointValue = rhs.fixedPointValue;
	}
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
