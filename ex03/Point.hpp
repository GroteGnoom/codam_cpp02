#include "Fixed.hpp"

class Point {
	public:
		Point();
		Point(const float x, const float y);
		~Point();
		Point(const Point &point);
		Point &operator=(const Point &other);
		Fixed get_x() const;
		Fixed get_y() const;
		Point operator-(const Point &other) const;
	private:
		const Fixed _x;
		const Fixed _y;
};

std::ostream &operator<<(std::ostream &out, const Point &p);

Fixed det(Point const a, Point const b);
bool bsp(Point const a, Point const b, Point const c, Point const point);
