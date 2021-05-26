#include "Ball.hpp"

Ball::Ball()
{
    add<PositionComponent>(new PositionComponent(0, 0));
}