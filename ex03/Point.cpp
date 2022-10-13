#include <iostream>
#include "Point.hpp"
#include "utils.hpp"

# define COLOR GREEN

Point::Point(): x(0), y(0) {
}

Point::Point(float const x, float const y) : x(x), y(y) {
	// std::cout << COLOR << "`Point::Point(float const x, float const y)` called" << RESET << std::endl;
}

Point::Point(const Point &src) : x(src.x), y(src.y) {
	// std::cout << COLOR << "Point copy constructor called" << RESET << std::endl;
}

Point &Point::operator=(const Point &rhs) {
	if (this == &rhs)
		return *this;
	// (Fixed &)this->x = rhs.x;
	// (Fixed &)this->y = rhs.y;
	return *this;
}

Point::~Point() {}

Fixed const& Point::getX() const {
	return this->x;
}

Fixed const& Point::getY() const {
	return this->y;
}

# undef COLOR
