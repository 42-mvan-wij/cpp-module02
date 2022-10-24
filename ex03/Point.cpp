#include <iostream>
#include "Point.hpp"

Point::Point(): x(0), y(0) {
}

Point::Point(float const x, float const y) : x(x), y(y) {
	// std::cout << "`Point::Point(float const x, float const y)` called" << std::endl;
}

Point::Point(const Point &src) : x(src.x), y(src.y) {
	// std::cout << "Point copy constructor called" << std::endl;
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


std::ostream &operator<<(std::ostream &s, Point const &point) {
	return (s << "(" << point.getX() << ", " << point.getY() << ")");
}
