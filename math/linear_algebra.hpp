#pragma once
#include "vector2.hpp"

template <typename v>
void eqOfLine(float& m, float& c, const v& p1, const v& p2) {
    //  gives the equation of a line given two points
    const float dy = p2.y - p1.y;
    const float dx = p2.x - p1.x;
    m = dy/dx;
    c = p1.y - (m*p1.x);
}

template <typename v>
void eqOfline2(double& l, double& m, double& n, const v& p1, const v& p2) {
    //  gives the equation of a line given two points
    // equation of a line in the form of ly + mx + n = 0

    const double dy = p2.y - p1.y;
    const double dx = p2.x - p1.x;

    m = dy;
    l = -dx;

    n = -(m * p1.x + l * p1.y);
}

double angleBetweenLines(double l1, double m1, double l2, double m2) {
    return atan2( (l1*m2 - l2*m1), (l1*l2 + m1*m2) );
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

Vector2f pointOfIntersection2(
    double l1, double m1, double n1,
    double l2, double m2, double n2)
{
    // using crammers rule
    double D = (m1*l2) - (m2*l1);
    
    Vector2f result;
    result.x = (l1 * n2 - l2 * n1) / D;
    result.y = (m2 * n1 - m1 * n2) / D;

    return result;
}