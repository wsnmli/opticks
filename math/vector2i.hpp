#pragma once

#include <iostream>
#include <cmath>
#include <utility>

class Vector2i { public:
	int x, y;

	Vector2i(int a = 0, int b = 0) :x(a), y(b) {}

	friend std::ostream& operator<<(std::ostream& os, const Vector2i& v);

	Vector2i& operator+=(const Vector2i &other) {
		x += other.x;
		y += other.y;
		return *this;
	}

	Vector2i& operator*=(const int n) {
		x *= n;
		y *= n;
		return *this;
	}
};

std::ostream& operator<<(std::ostream& os, const Vector2i &x) {
    os << "(" << x.x << ", " << x.y << ")";
    return os;
}

Vector2i operator-(Vector2i v1, Vector2i v2) {
	Vector2i tmp;
	tmp.x = v1.x - v2.x;
	tmp.y = v1.y - v2.y;
	return tmp;
}

Vector2i operator+(Vector2i v1, Vector2i v2) {
	Vector2i tmp;
	tmp.x = v1.x + v2.x;
	tmp.y = v1.y + v2.y;
	return tmp;
}


Vector2i operator/(Vector2i v, int a) {
	Vector2i tmp;
	tmp.x = v.x / a;
	tmp.y = v.y / a;
	return tmp;
}

Vector2i operator/=(Vector2i a, int b) {
	Vector2i tmp = a;
	a.x /= b;
	a.y /= b;
	return tmp;
}

Vector2i operator*(Vector2i v, int a) {
	Vector2i tmp;
	tmp.x = v.x * a;
	tmp.y = v.y * a;
	return tmp;
}

int operator==(Vector2i v1, Vector2i v2) {
	return v1.x == v2.x && v1.y == v2.y;
}

int operator!=(Vector2i v1, Vector2i v2) {
	return !(v1 == v2);
}

float distance(Vector2i v1, Vector2i v2) {
	return sqrt((v1.x-v2.x)*(v1.x-v2.x)) + ((v1.y-v2.y)*(v1.y-v2.y));
}

int distance_squared(Vector2i v1, Vector2i v2) {
	return (v1.x-v2.x)*(v1.x-v2.x) + (v1.y-v2.y)*(v1.y-v2.y);
}

int cross_product(Vector2i v1, Vector2i v2) {
	return (v1.x * v2.x) - (v1.y * v2.y);
}

Vector2i randVector(int x, int y) {
	Vector2i tmp;
	tmp.x = rand() % x;
	tmp.y = rand() % y;

	return tmp;
}

void swap(Vector2i& v1, Vector2i& v2) {
    std::swap(v1.x, v2.x);
    std::swap(v1.y, v2.y);
}