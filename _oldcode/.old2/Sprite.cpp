#include "Sprite.hpp"

Texture* Sprite::getTexture()
{
    return texture;
}
SDL_Texture* Sprite::getSdlTexture()
{
    return texture->getSdlTexture();
}
SDL_Rect& Sprite::getFrame(int p_frameIndex, bool p_allowIndexOverflow = false)
{
    if ((p_frameIndex < 0 || p_frameIndex >= frames.size()) &&
        !p_allowIndexOverflow)
        throw "Cannot get frame index " + to_string(p_frameIndex) +
            " of sprite with " + to_string(frames.size()) + " frames";

    return frames.at(p_frameIndex % frames.size());
}
int Sprite::getWidth()
{
    return width;
}
int Sprite::getHeight()
{
    return height;
}