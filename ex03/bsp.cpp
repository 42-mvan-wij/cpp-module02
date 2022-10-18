#include "Point.hpp"

Fixed sign(Point const p1, Point const p2, Point const check) {
    return (check.getX() - p2.getX()) * (p1.getY() - p2.getY()) - (p1.getX() - p2.getX()) * (check.getY() - p2.getY());
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed d1, d2, d3, d4, d5, d6;

	// std::cout << static_cast<Point>(a).getX() << ", " << static_cast<Point>(a).getY() << std::endl;

	// test whether `point` and `c` are on the same side of line `a``b`
	d1 = sign(a, b, point);
	d4 = sign(a, b, c);
	// std::cout << d1 << " - " << d4 << std::endl;
	if (d1 == 0 || d4 == 0)
		return false;
	if ((d1 > 0) != (d4 > 0))
		return false;

	d2 = sign(b, c, point);
	d5 = sign(b, c, a);
	// std::cout << d2 << " - " << d5 << std::endl;
	if (d2 == 0 || d5 == 0)
		return false;
	if ((d2 > 0) != (d5 > 0))
		return false;

	d3 = sign(c, a, point);
	d6 = sign(c, a, b);
	// std::cout << d3 << " - " << d6 << std::endl;
	if (d3 == 0 || d6 == 0)
		return false;
	if ((d3 > 0) != (d6 > 0))
		return false;

	return true;
}

