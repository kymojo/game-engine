#pragma once
#include "Vector.hpp"

class GameObject {
    public:
    GameObject();

    Vector getPosition();
    Vector moveTo(Vector p_position);
    Vector moveRelative(Vector p_position);

    private:
    Vector position;
    unsigned int objectId;

    virtual void render();
    
    virtual void update();
};