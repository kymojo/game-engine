#pragma once

#include <SDL2/SDL.h>

class Camera {
    public:
    Camera() : x(0), y(0), width(0), height(0) {}

    private:
    int x, y, width, height;
    void render() {}
};