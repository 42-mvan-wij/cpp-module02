#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {
	public:
		Point();
		Point(float const x, float const y);
		Point(Point const &src);
		Point &operator=(const Point &rhs);
		~Point();

		Fixed const &getX() const;
		Fixed const &getY() const;

	private:
		Fixed const x;
		Fixed const y;

};

std::ostream &operator<<(std::ostream &s, Point const &point);

#endif
