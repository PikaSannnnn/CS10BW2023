#include <iostream>

using namespace std;

class Point {
private:
	int x, y;
public:
	Point() : x(0), y(0) {}
	Point(int x) {
		this->x = x;
	}
	Point(int, int);
};

Point::Point(int x, int y) {
	this->x = x;
	this->y = y;
}

int main() {
	Point A;
	Point B(1);
	Point C(3, 4); 

}
