#include "Entity.hpp"
#include "Math.hpp"
#include "Sprite.hpp"
#include "Util.hpp"
#include <SDL2/SDL.h>

Entity::Entity()
{
    imageFrame = 0;
}
Entity::~Entity() {}

void Entity::render(SDL_Renderer* p_renderer)
{
    if (sprite != NULL)
    {
        SDL_Rect spriteFrame = sprite->getFrame(imageFrame);
        SDL_Rect renderDestination;
        renderDestination.x = position.x;
        renderDestination.y = position.y;
        renderDestination.w = sprite->getWidth();
        renderDestination.h = sprite->getHeight();

        SDL_RenderCopy(p_renderer, sprite->getSdlTexture(), &spriteFrame,
                       &renderDestination);
    }
}

// GETTERS AND SETTERS

Sprite* Entity::setSprite(Sprite* p_sprite)
{
    return Util::setAndGetOld(p_sprite, &sprite);
}
Sprite* Entity::getSprite()
{
    return sprite;
}
Vector Entity::setPosition(const Vector& p_position)
{
    return Util::setAndGetOld(p_position, &position);
}
Vector Entity::setPositionRelative(const Vector& p_position)
{
    Vector exactPosition(p_position.x + position.x, p_position.y + position.y);
    return Util::setAndGetOld(exactPosition, &position);
}
Vector Entity::getPosition()
{
    return position;
}
int Entity::getImageFrame()
{
    return imageFrame;
}
int Entity::setImageFrame(int p_imageFrame)
{
    return Util::setAndGetOld(p_imageFrame, &imageFrame);
}