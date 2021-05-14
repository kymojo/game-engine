#include "Sprite.hpp"

Sprite::Sprite(Texture* p_texture, SpriteSheetConfig* p_config) : texture(p_texture)
{
    initializeFrames(p_config);
}

Texture* Sprite::getTexture()
{
    return texture;
}
SDL_Texture* Sprite::getSdlTexture()
{
    return texture->getSdlTexture();
}
SDL_Rect& Sprite::getFrame(int p_frameIndex, bool p_allowIndexOverflow)
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
void Sprite::initializeFrames(SpriteSheetConfig* p_config)
{
    int frameCount = p_config->frameCount;
    for(int frame = 0; frame < frameCount; frame++)
        frames.push_back(p_config->getFrameRect(frame));
}