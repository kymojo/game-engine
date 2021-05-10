#pragma once

#include "Vector.hpp"
#include <SDL2/SDL.h>
#include <string>

using namespace std;

struct SpriteSheetConfig
{
    /** @brief Make new config for Sprite parsing from Texture */
    SpriteSheetConfig();

    /**
     * @brief Make new config for Sprite parsing from Texture
     * @param p_textureOrigin Vector position of first Sprite frame relative to
     * Texture origin
     * @param p_spriteWidth Width of Sprite in pixels
     * @param p_spriteHeight Height of Sprite in pixels
     */
    SpriteSheetConfig(const Vector& p_textureOrigin, int p_spriteWidth,
                      int p_spriteHeight);

    /**
     * @brief Make new config for Sprite parsing from Texture
     * @param p_textureOrigin Origin of spritesheet in Texture
     * @param p_spriteWidth Width of spritesheet Sprite in pixels
     * @param p_spriteHeight Height of spritesheet Sprite in pixels
     * @param p_frameCount Number of frames in this spritesheet
     * @param p_frameColumns Number of columns in this spritesheet
     * @param p_frameColumnOffset Horizontal margin between spritesheet frames
     * (in pixels)
     * @param p_frameRowOffset Vertical margin between spritesheet frames (in
     * pixels)
     */
    SpriteSheetConfig(const Vector& p_textureOrigin, int p_spriteWidth,
                      int p_spriteHeight, int p_frameCount, int p_frameColumns,
                      int p_frameColumnOffset, int p_frameRowOffset);

    int frameCount;
    int spriteWidth, spriteHeight;
    Vector textureOrigin;
    int frameColumns;
    int frameColumnOffset;
    int frameRowOffset;
    SDL_Rect getFrameRect(int frame);
};