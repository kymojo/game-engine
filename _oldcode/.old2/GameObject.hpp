#pragma once

#include "Vector.hpp"

class GameObject {
    public:
    GameObject(unsigned int p_id);

    virtual void onCreate();
    virtual void update();
    virtual void render();
    virtual void onDelete();

    unsigned int getId();
    
    private:
    unsigned int id;
};