#include "SpriteSheetConfig.hpp"

SpriteSheetConfig::SpriteSheetConfig()
{
    SpriteSheetConfig(Vector(0, 0), 0, 0, 1, 1, 0, 0);
}

SpriteSheetConfig::SpriteSheetConfig(const Vector& p_textureOrigin,
                                     int p_spriteWidth, int p_spriteHeight)
{
    SpriteSheetConfig(p_textureOrigin, p_spriteWidth, p_spriteHeight, 1, 1, 0,
                      0);
}

SpriteSheetConfig::SpriteSheetConfig(const Vector& p_textureOrigin,
                                     int p_spriteWidth, int p_spriteHeight,
                                     int p_frameCount, int p_frameColumns,
                                     int p_frameColumnOffset,
                                     int p_frameRowOffset)
{
    textureOrigin = p_textureOrigin;
    spriteWidth = p_spriteWidth;
    spriteHeight = p_spriteHeight;
    frameCount = p_frameCount;
    frameColumns = p_frameColumns;
    frameColumnOffset = p_frameColumnOffset;
    frameRowOffset = p_frameRowOffset;
}

SDL_Rect SpriteSheetConfig::getFrameRect(int frame)
{
    if (frame >= frameCount || frame < 0)
        throw "Tried to get frame index " + to_string(frame) +
            " from SpriteSheetConfig with " + to_string(frameCount) +
            " frames.";

    int columnIndex = frame % frameColumns;
    int rowIndex = frame / frameColumns;
    int x = textureOrigin.x + (rowIndex * (spriteWidth + frameColumnOffset));
    int y = textureOrigin.y + (columnIndex * (spriteHeight + frameRowOffset));

    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = spriteWidth;
    rect.h = spriteHeight;
    return rect;
}