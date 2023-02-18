#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <cmath>
using std::cout, std::endl, std::ostream;

class Point {
protected:
	double x, y;
public:
	// Constructors
	Point() : x(0), y(0) { }
	Point(double x) { this->x = x; }
	Point(double, double);

	// Mutator Function
	void Scale(double);

	// Accessor Functions
	Point Add(double a) const { return Point(x + a, y + a); }
	Point Add(double x, double y) const { return Point(this->x + x, this->y + y); }
	Point Sub(double a) const { return Point(x + a, y + a); }
	Point Sub(double x, double y) const { return Point(this->x - x, this->y - y); }
	Point Mult(double a) const { return Point(x + a, y + a); }
	Point Mult(double x, double y) const {return Point(this->x * x, this->y * y); }
	Point Div(double a) const { return Point(x + a, y + a); }
	Point Div(double x, double y) const { return Point(this->x / x, this->y / y); }
	void Print() const { cout << "(" << x << ", " << y << ")" << endl; }
	double Vectorize() const;
	double Vectorize(const Point&) const;

	// Overloads
	Point operator+(const Point&);
	Point operator-(const Point&);
	Point operator*(const Point&);
	Point operator/(const Point&);
	bool operator<(const Point&);
	bool operator>(const Point&);
	bool operator==(const Point&);
	friend ostream& operator<<(ostream& out, Point& p) {
		out << "(" << p.x << ", " << p.y << ")";
		return out;
	}
};

#endif 