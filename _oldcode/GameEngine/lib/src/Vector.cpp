#include "../Vector.hpp"

Vector Vector::add(Vector& p_vector)
{
    return Vector(x + p_vector.x, y + p_vector.y);
}