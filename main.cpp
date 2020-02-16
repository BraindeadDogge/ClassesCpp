#include <iostream>
#include <cmath>
using namespace std;

class Point{
public:
	double a, b;
	void read() {
		cin >> a >> b;
	}
	double distance(Point p) {
		return sqrt((p.a - a)*(p.a - a) + (p.b - b)*(p.b - b));
	}
};

class Rectangle{
public:
	Point x, y;
	void read() {
		x.read();
		y.read();
	}
	double square() {
		return (y.a - x.a) * (y.b - x.b);
	}
};

class Triangle{
public:
	Point x, y, z;
	void read() {
		x.read();
		y.read();
		z.read();
	}
	double square() {
		double p = x.distance(y) + x.distance(z) + y.distance(z);
		p /= 2;
		return sqrt(p * (p - x.distance(y)) * (p - x.distance(z)) * (p - y.distance(z)));
	}
};

int main() {
	Rectangle rec;
	Triangle tri;
	rec.read();
	tri.read();
	cout << rec.square() << endl;
	cout << tri.square();
	return 0;
}
