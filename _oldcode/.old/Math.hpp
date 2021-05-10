#pragma once

struct Vector
{
    Vector() : x(0), y(0) {}
    Vector(int p_x, int p_y) : x(p_x), y(p_y) {}
    int x, y;
};