#pragma once
#include <complex>
#include <vector>
#include <algorithm>
using namespace std;


#include "vector2f.hpp"
#include "vector2i.hpp"

float degrestoradians(float degree) {
    return (degree * M_PI * 2) / 360;
}

Vector2f rotatevector(Vector2f v, float t) {
    // rotate a vector t degrees about the origin
    // first convert v to the complex number c
    std::complex<float> c = {v.x, v.y};

    // calcluate the rotation number
    std::complex<float> r = { sinf(degrestoradians(t)), 
                              cosf(degrestoradians(t)) };
    auto result = c*r;
    return Vector2f(result.real(), result.imag());
}

// vector functions as in the memory type

template <typename T>
bool in(T t, vector<T> v) { // returns true if element t is in v
	return find(v.begin(), v.end(), t) != v.end();
}

template <typename T>
int find_index(T t, vector<T> v) { /* returns the index of the first
	element of v in t, returns -1 if v not in t */
	auto it = find(v.begin(), v.end(), t);
	if (it != v.end()) {
		int index = distance(v.begin(), it);
		return index;
	} else return -1;
}
