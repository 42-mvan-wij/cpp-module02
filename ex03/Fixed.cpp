#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() {
	// std::cout << "Default constructor called" << std::endl;
	this->fixedPointValue = 0;
}

Fixed::Fixed(int const val) {
	// std::cout << "Int constructor called" << std::endl;
	this->fixedPointValue = val << this->fractionalBits;
}

Fixed::Fixed(float const val) {
	// std::cout << "Float constructor called" << std::endl;
	this->fixedPointValue = roundf(val * (1 << this->fractionalBits));
}

Fixed::Fixed(const Fixed &src) {
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed &Fixed::operator=(const Fixed &rhs) {
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this == &rhs)
		return *this;
	this->fixedPointValue = rhs.fixedPointValue;
	return *this;
}

Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
	return this->fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
	// std::cout << "setRawBits member function called" << std::endl;
	this->fixedPointValue = raw;
}

float Fixed::toFloat() const {
	return this->fixedPointValue / static_cast<float>(1 << this->fractionalBits);
}

int Fixed::toInt() const {
	return this->getRawBits() >> this->fractionalBits;
}

bool Fixed::operator>(Fixed const &rhs) const {
	return this->getRawBits() > rhs.getRawBits();
}

bool Fixed::operator<(Fixed const &rhs) const {
	return this->getRawBits() < rhs.getRawBits();
}

bool Fixed::operator>=(Fixed const &rhs) const {
	return this->getRawBits() >= rhs.getRawBits();
}

bool Fixed::operator<=(Fixed const &rhs) const {
	return this->getRawBits() <= rhs.getRawBits();
}

bool Fixed::operator==(Fixed const &rhs) const {
	return this->getRawBits() == rhs.getRawBits();
}

bool Fixed::operator!=(Fixed const &rhs) const {
	return this->getRawBits() != rhs.getRawBits();
}

Fixed Fixed::operator+(Fixed const &rhs) {
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(Fixed const &rhs) const {
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(Fixed const &rhs) {
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(Fixed const &rhs) {
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed& Fixed::operator++() {
	this->fixedPointValue++;
	return *this;
}

Fixed& Fixed::operator--() {
	this->fixedPointValue--;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	this->fixedPointValue++;
	return tmp;
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	this->fixedPointValue--;
	return tmp;
}

Fixed& Fixed::min(Fixed &lhs, Fixed &rhs) {
	if (lhs < rhs)
		return lhs;
	return rhs;
}

Fixed const& Fixed::min(Fixed const &lhs, Fixed const &rhs) {
	if (lhs < rhs)
		return lhs;
	return rhs;
}

Fixed& Fixed::max(Fixed &lhs, Fixed &rhs) {
	if (lhs > rhs)
		return lhs;
	return rhs;
}

Fixed const& Fixed::max(Fixed const &lhs, Fixed const &rhs) {
	if (lhs > rhs)
		return lhs;
	return rhs;
}

std::ostream &operator<<(std::ostream &o, Fixed const &fixed) {
	o << fixed.toFloat();
	return o;
}
