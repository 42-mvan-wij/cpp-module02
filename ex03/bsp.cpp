#include "Point.hpp"

Fixed sign(Point const p1, Point const p2, Point const check) {
    return (check.getX() - p2.getX()) * (p1.getY() - p2.getY()) - (p1.getX() - p2.getX()) * (check.getY() - p2.getY());
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed d1, d2, d3;

	d1 = sign(a, b, point);
	d2 = sign(b, c, point);
	d3 = sign(c, a, point);

	bool has_on_line = (d1 == 0) || (d2 == 0) || (d3 == 0);
	bool has_left = (d1 < 0) || (d2 < 0) || (d3 < 0);
	bool has_right = (d1 > 0) || (d2 > 0) || (d3 > 0);

	return !has_on_line && !(has_left && has_right);
}

