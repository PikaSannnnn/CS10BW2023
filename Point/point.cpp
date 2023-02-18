#include "point.h"

Point::Point(double x, double y) {
	this->x = x;
	this->y = y;
}

void Point::Scale(double s) {
	this->x *= s;
	this->y *= s;
}

double Point::Vectorize() const {
	return sqrt((x * x) + (y * y));
}

double Point::Vectorize(const Point& other) const {
	double x = this->x - other.x;
	double y = this->y - other.y;
	return sqrt((x * x) + (y * y));
}

Point Point::operator+(const Point& rhs) {
	return Point(x + rhs.x, y + rhs.y);
}
Point Point::operator-(const Point& rhs) {
	return Point(x - rhs.x, y - rhs.y);
}
Point Point::operator*(const Point& rhs) {
	return Point(x * rhs.x, y * rhs.y);
}
Point Point::operator/(const Point& rhs) {
	return Point(x / rhs.x, y / rhs.y);
}
bool Point::operator<(const Point& rhs) {
	return Vectorize() < rhs.Vectorize();	// Be aware, rhs is a const... any functions it calls need to be const too!
}
bool Point::operator>(const Point& rhs) {
	return Vectorize() < rhs.Vectorize();
}
bool Point::operator==(const Point& rhs) {
	return fabs(Vectorize() - rhs.Vectorize()) <= 0.001;	// floating point comparison
}