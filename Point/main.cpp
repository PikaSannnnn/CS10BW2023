#include <iostream>
#include <cmath>
#include "../sifunc.h"

using namespace std;

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

int main() {
	Point A;
	Point B(1);
	Point C(3, 4);

	// Test the functions here vvvvv
}
