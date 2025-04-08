#pragma once

#include <iostream>
#include <cmath>

class Vector2f { public:
	float x, y;

	Vector2f(float a = 0, float b = 0) :x(a), y(b) {}

	friend std::ostream& operator<<(std::ostream& os, const Vector2f& v);

	Vector2f& operator+=(const Vector2f &other) {
		x += other.x;
		y += other.y;
		return *this;
	}

	 float &operator[] (int index) {
        switch (index)
        {
        case 0:
            return x;
        case 1:
            return y;

        default:
            break;
        }
    }
};

std::ostream& operator<<(std::ostream& os, const Vector2f &x) {
    os << "(" << x.x << ", " << x.y << ")";
    return os;
}

Vector2f operator-(Vector2f v1, Vector2f v2) {
	Vector2f tmp;
	tmp.x = v1.x - v2.x;
	tmp.y = v1.y - v2.y;
	return tmp;
}

Vector2f operator+(Vector2f v1, Vector2f v2) {
	Vector2f tmp;
	tmp.x = v1.x + v2.x;
	tmp.y = v1.y + v2.y;
	return tmp;
}


Vector2f operator/(Vector2f v, float a) {
	Vector2f tmp;
	tmp.x = v.x / a;
	tmp.y = v.y / a;
	return tmp;
}

Vector2f operator/=(Vector2f a, float b) {
	Vector2f tmp = a;
	a.x /= b;
	a.y /= b;
	return tmp;
}

Vector2f operator*(Vector2f v, float a) {
	Vector2f tmp;
	tmp.x = v.x * a;
	tmp.y = v.y * a;
	return tmp;
}

void operator*=(Vector2f &v, float c) {
	v = v*c;
}

int operator==(Vector2f v1, Vector2f v2) {
	return v1.x == v2.x && v1.y == v2.y;
}

float distance(Vector2f v1, Vector2f v2) {
	return sqrt((v1.x-v2.x)*(v1.x-v2.x)) + ((v1.y-v2.y)*(v1.y-v2.y));
}

float distance_squared(Vector2f v1, Vector2f v2) {
	return (v1.x-v2.x)*(v1.x-v2.x) + (v1.y-v2.y)*(v1.y-v2.y);
}

int cross_product(Vector2f v1, Vector2f v2) {
	return (v1.x * v2.x) - (v1.y * v2.y);
}