#pragma once
#include "vector2i.hpp"

template <typename v>
void eqOfLine(float& m, float& c, const v& p1, const v& p2) {
    //  gives the equation of a line given two points
    const float dy = p2.y - p1.y;
    const float dx = p2.x - p1.x;
    m = dy/dx;
    c = p1.y - (m*p1.x);
}

Vector2i pointOfIntersection(float m1, float c1, float m2, float c2) {
    //  given the equations of two lines find the point of intersection

    //  check the lines aren't parallel
    if (m1 == m2)
        throw std::invalid_argument("Lines are parallel, no intersection.");

    // Calculate the x-coordinate of the intersection
    float x = (c2 - c1) / (m1 - m2);
    // Calculate the y-coordinate of the intersection
    float y = m1 * x + c1;

    return Vector2i(x+0.5, y+0.5);
}