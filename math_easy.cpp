#include <iostream>
#include <cmath>
using namespace std;

class Point {
public:
	double a, b;
	void read() {
		cin >> a >> b;
	}
	double distance(Point p) {
		return sqrt((p.a - a)*(p.a - a) + (p.b - b)*(p.b - b));
	}
};

class Rectangle {
public:
	Point x, y;
	void read() {
		x.read();
		y.read();
	}
	double square() {
		return (y.a - x.a) * (y.b - x.b);
	}
	bool is_inside(Point p) {
		return (p.a >= x.a && p.a <= y.a && p.b >= x.b && p.b <= y.b);
	}
};

class Triangle {
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
	float sign(Point p1, Point p2, Point p3) {
		return (p1.a - p3.a) * (p2.b - p3.b) - (p2.a - p3.a) * (p1.b - p3.b);
	}
	bool is_inside(Point p) {
		bool b1, b2, b3;

		b1 = sign(p, x, y) < 0.0f;
		b2 = sign(p, y, z) < 0.0f;
		b3 = sign(p, z, x) < 0.0f;

		return ((b1 == b2) && (b2 == b3));
	}
};

class Picture {
public:
	Rectangle rec;
	Triangle tri;
	Point p;
	void read() {
		rec.read();
		tri.read();
		p.read();
	}
	bool intersect() {
		return ( rec.is_inside(tri.x) && rec.is_inside(tri.y) && rec.is_inside(tri.z) && tri.is_inside(p) );
	}
};

int main() {
	Picture pic;
	pic.read();
	if (pic.intersect()) cout << "YES";
	else cout << "NO";
	return 0;
}
