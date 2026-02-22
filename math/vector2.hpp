#pragma once

#include <iostream>
#include <cmath>
#include <type_traits>
#include <stdexcept>

template<typename T>
class Vector2 {
public:
    T x;
    T y;

    constexpr Vector2() : x(0), y(0) {}
    constexpr Vector2(T x, T y) : x(x), y(y) {}

    // the compound operators
    constexpr Vector2& operator+=(const Vector2& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    constexpr Vector2& operator-=(const Vector2& other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    constexpr Vector2& operator*=(T scalar) {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    constexpr Vector2& operator/=(T scalar) {
        x /= scalar;
        y /= scalar;
        return *this;
    }

    // for indexing
    T& operator[](std::size_t index) {
        if (index == 0) return x;
        if (index == 1) return y;
        throw std::out_of_range("Vector2 index must be 0 or 1");
    }

    const T& operator[](std::size_t index) const {
        if (index == 0) return x;
        if (index == 1) return y;
        throw std::out_of_range("Vector2 index must be 0 or 1");
    }
};

// the free operators

template<typename T>
constexpr Vector2<T> operator+(Vector2<T> a, const Vector2<T>& b) {
    return a += b;
}

template<typename T>
constexpr Vector2<T> operator-(Vector2<T> a, const Vector2<T>& b) {
    return a -= b;
}

template<typename T>
constexpr Vector2<T> operator*(Vector2<T> v, T scalar) {
    return v *= scalar;
}

template<typename T>
constexpr Vector2<T> operator*(T scalar, Vector2<T> v) {
    return v *= scalar;
}

template<typename T>
constexpr Vector2<T> operator/(Vector2<T> v, T scalar) {
    return v /= scalar;
}

// comparison operators

template<typename T>
constexpr bool operator==(const Vector2<T>& a, const Vector2<T>& b) {
    return a.x == b.x && a.y == b.y;
}

template<typename T>
constexpr bool operator!=(const Vector2<T>& a, const Vector2<T>& b) {
    return !(a == b);
}

// utility functions

template<typename T>
constexpr T dot(const Vector2<T>& a, const Vector2<T>& b) {
    return a.x * b.x + a.y * b.y;
}

template<typename T>
constexpr T cross(const Vector2<T>& a, const Vector2<T>& b) {
    return a.x * b.y - a.y * b.x;
}

template<typename T>
auto distance_squared(const Vector2<T>& a, const Vector2<T>& b) {
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

template<typename T>
auto distance(const Vector2<T>& a, const Vector2<T>& b) {
    return sqrt(distance_squared(a, b));
}

// stream output

template<typename T>
std::ostream& operator<<(std::ostream& os, const Vector2<T>& v) {
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}

//  typedefs

using V2 = Vector2<int>;
using Vector2i = Vector2<int>;
using Vector2f = Vector2<float>;
using V2f = Vector2<float>;