#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "Entity.hpp"
#include "Math.hpp"

Entity::Entity(Vector p_position, SDL_Texture* p_texture)
    : position(p_position), texture(p_texture)
{
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 32;
    currentFrame.h = 32;
}
// int Entity::setX(int p_x)
// {
//     int oldX = x;
//     x = p_x;
//     return oldX;
// }
// int Entity::setY(int p_y)
// {
//     int oldY = y;
//     y = p_y;
//     return oldY;
// }
SDL_Texture* Entity::setTexture(SDL_Texture* p_texture)
{
    SDL_Texture* oldTexture = texture;
    texture = p_texture;
    return oldTexture;
}
SDL_Rect Entity::getCurrentFrame()
{
    return currentFrame;
}
SDL_Rect Entity::setCurrentFrame(SDL_Rect p_rect)
{
    SDL_Rect oldRectangle = currentFrame;
    currentFrame = p_rect;
    return oldRectangle;
}