#pragma once

#include "../include/GameEngine/lib/Entity.hpp"
#include "../include/GameEngine/lib/Component.hpp"

struct PositionComponent : public Component
{
    PositionComponent(int p_x, int p_y) : x(p_x), y(p_y) {}
    int x, y;
};

class Ball : public Entity
{
    public:
    Ball();
};