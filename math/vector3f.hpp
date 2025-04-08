#pragma once
#include <iostream>
#include <cmath>

class Vector3f { public:
	float x, y, z;

	Vector3f(float x=0, float y=0, float z=0) :x(x), y(y), z(z) {}

	friend std::ostream& operator<<(std::ostream& os, const Vector3f& v);

    Vector3f& operator+=(const Vector3f &other) {
	    x += other.x;
	    y += other.y;
        z += other.z;
	    return *this;
    }

    Vector3f operator+(const Vector3f &other) {
        Vector3f tmp;
        tmp.x = x + other.x;
	    tmp.y = y + other.y;
	    tmp.z = z + other.z;
        return tmp;
    }

    Vector3f operator/( float a) {
	    Vector3f tmp;
	    tmp.x = x / a;
	    tmp.y = y / a;
	    tmp.z = z / z;
        return tmp;
    }

    Vector3f operator*( float a) {
	    Vector3f tmp;
	    tmp.x = x * a;
	    tmp.y = y * a;
	    tmp.z = z * a;
        return tmp;
    }

    float distance_squared(Vector3f v1, Vector3f v2) {
	    return (v1.x-v2.x)*(v1.x-v2.x) 
            + (v1.y-v2.y)*(v1.y-v2.y)
            + (v1.z-v2.z)*(v1.z-v2.z);
    }

    float distance(Vector3f v1, Vector3f v2) {
	    return sqrt(distance_squared(v1, v2));
    }

    float norm() {
        return sqrt(distance({0,0,0}, *this));
    }

    Vector3f normalized() {    return (*this) / norm(); }

    float &operator[] (int index) {
        switch (index)
        {
        case 0:
            return x;
        case 1:
            return y;
        case 2:
            return z;
        default:
            break;
        }
    }
};

std::ostream& operator<<(std::ostream& os, const Vector3f &x) {
    os << "(" << x.x << ", " << x.y << ", " << x.z << ")";
    return os;
}