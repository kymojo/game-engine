#pragma once

class Vector {
    public:
    Vector() : x(0), y(0) {}
    Vector(int p_x, int p_y) : x(p_x), y(p_y) {}

    int x, y;

    Vector add(Vector& p_vector);
};