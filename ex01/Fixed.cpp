#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed(): fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const val): fixedPointValue(val << fractionalBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const val): fixedPointValue(roundf(val * (1 << fractionalBits))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src): fixedPointValue(src.fixedPointValue) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &rhs)
		return *this;
	this->fixedPointValue = rhs.fixedPointValue;
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
	return this->fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
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
