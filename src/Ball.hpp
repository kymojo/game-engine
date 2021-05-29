#pragma once

#include "../include/GameEngine/Game.hpp"
// #include "../include/GameEngine/Entity.hpp"
// #include "../include/GameEngine/Component.hpp"

struct PositionComponent : public Component
{
    PositionComponent(Vector2 p_position) : position(p_position) {}
    Vector2 position;
};

class Ball : public Entity
{
    public:
    Ball(int p_x, int p_y) : Entity(typeid(Ball).name())
    {
        add<PositionComponent>(new PositionComponent(Vector2(p_x,p_y)));
    }
    Ball() : Ball(0,0) {}
};