#pragma once
#include "Math.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Entity {
    public:
    Entity(Vector p_position, SDL_Texture* p_texture);
    Vector& getPosition()
    {
        return position;
    }
    // int setX(int p_x);
    // int setY(int p_y);
    SDL_Texture* getTexture()
    {
        return texture;
    }
    SDL_Texture* setTexture(SDL_Texture* p_texture);
    SDL_Rect getCurrentFrame();
    SDL_Rect setCurrentFrame(SDL_Rect p_rect);

    private:
    Vector position;
    SDL_Texture* texture;
    SDL_Rect currentFrame;
};