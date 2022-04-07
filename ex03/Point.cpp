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

float cross(Point const a, Point const b) {
	return (a.get_x().toFloat() * b.get_y().toFloat()
			- a.get_y().toFloat() * b.get_x().toFloat());
}


bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Point atob = b - a;
	Point btoc = c - b;
	Point ctoa = a - c;
	Point atop = point - a;
	Point btop = point - b;
	Point ctop = point - c;
	float crossa = cross(atob, atop);
	float crossb = cross(btoc, btop);
	float crossc = cross(ctoa, ctop);
	if ((crossa < 0 && crossb < 0 && crossc < 0) || (crossa > 0 && crossb > 0 && crossc > 0))
		return true;
	return false;
}

