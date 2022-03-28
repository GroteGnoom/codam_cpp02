#include "Point.hpp"

Point::Point() : _x(Fixed(0)), _y(Fixed(0)) {}

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y)) {}

std::ostream &operator<<(std::ostream &out, const Point &p) {
	out << "(" << p.get_x().toFloat() << ", " << p.get_y().toFloat() << ")";
	return out;
}

Point::~Point() {}

Point::Point(const Point &point) {
	_x.setRawBits(point.get_x().getRawBits());
	_y.setRawBits(point.get_y().getRawBits());
}

Point &Point::operator=(const Point &other) {
	_x.setRawBits(other.get_x().getRawBits());
	_y.setRawBits(other.get_y().getRawBits());
	return *this;
}

Point Point::operator-(const Point &other) const {
	Fixed x = _x - other._x;
	Fixed y = _y - other._y;
	return Point(x.toFloat(), y.toFloat());
}

Fixed Point::get_y() const {
	return _y;
}

Fixed Point::get_x() const {
	return _x;
}

Fixed det(Point const a, Point const b) {
	return (a.get_x() * b.get_y() - a.get_y() * b.get_x());
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed r1;
	Fixed r2;

	Point b2(b - a);
	Point c2(c - a);
	r1 = (det(point, c2) - det(a, c2)) / det(b2,c2);
	r2 = (det(a, b2) - det(point, b2) ) / det(b2,c2);

	return (r1 > 0 && r2 > 0 && (r1 + r2) < 1);
}
