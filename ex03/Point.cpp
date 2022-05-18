#include <iostream>
#include "Point.hpp"

Point::Point(): x(0), y(0) {
}

Point::Point(float const x, float const y) : x(x), y(y) {
	// std::cout << "hello" << std::endl;
}

Point::Point(const Point &src) {
	// std::cout << "nouh" << std::endl;
	*this = src;
}

Point &Point::operator=(const Point &rhs) {
	if (this == &rhs)
		return *this;
	(Fixed &)this->x = rhs.x;
	(Fixed &)this->y = rhs.y;
	return *this;
}

Point::~Point() {

}

Fixed const& Point::getX() const {
	return this->x;
}

Fixed const& Point::getY() const {
	return this->y;
}
