#include <iostream>
#include <cmath>
#include "Fixed.hpp"
#include "utils.hpp"

# define COLOR YELLOW

Fixed::Fixed() {
	std::cout << COLOR << "Default constructor called" << RESET << std::endl;
	this->fixedPointValue = 0;
}

Fixed::Fixed(int const val) {
	std::cout << COLOR << "Int constructor called" << RESET << std::endl;
	this->fixedPointValue = val << this->fractionalBits;
}

Fixed::Fixed(float const val) {
	std::cout << COLOR << "Float constructor called" << RESET << std::endl;
	this->fixedPointValue = roundf(val * (1 << this->fractionalBits));
}

Fixed::Fixed(Fixed const &src) {
	std::cout << COLOR << "Copy constructor called" << RESET << std::endl;
	this->fixedPointValue = src.fixedPointValue;
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
	return this->fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
	std::cout << COLOR << "setRawBits member function called" << RESET << std::endl;
	this->fixedPointValue = raw;
}

float Fixed::toFloat() const {
	return this->fixedPointValue / static_cast<float>(1 << this->fractionalBits);
}

int Fixed::toInt() const {
	return this->getRawBits() >> this->fractionalBits;
}

std::ostream &operator<<(std::ostream &o, Fixed const &fixed) {
	o << fixed.toFloat();
	return o;
}

# undef COLOR
