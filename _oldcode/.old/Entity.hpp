#pragma once
#include "Math.hpp"
#include "Sprite.hpp"
#include <SDL2/SDL.h>

class Entity {
    public:
    Entity();
    ~Entity();
    Sprite* setSprite(Sprite* p_sprite);
    Sprite* getSprite();
    Vector setPosition(const Vector& p_position);
    Vector setPositionRelative(const Vector& p_position);
    Vector getPosition();
    int getImageFrame();
    int setImageFrame(int p_imageFrame);

    void render(SDL_Renderer* p_renderer);

    private:
    Vector position;
    Sprite* sprite;
    int imageFrame;
    // imageScale, imageColorize, imageRotation, imageAlpha, currentFrame,
    // imageSpeed
};