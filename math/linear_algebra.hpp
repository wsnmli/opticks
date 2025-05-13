#pragma once

template <typename v>
void eqOfLine(float& m, float& c, const v& p1, const v& p2) {
    const float dy = p2.y - p1.y;
    const float dx = p2.x - p1.x;
    m = dy/dx;
    c = p1.y - (m*p1.x);
}