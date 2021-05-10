#pragma once
#include "SpriteSheetConfig.hpp"
#include "Texture.hpp"
#include <SDL2/SDL.h>
#include <string>
#include <vector>

template <typename T> using d_array = std::vector<T>;
using namespace std;

class Sprite {
    public:
    /**
     * @brief Construct a new Sprite object
     * @param p_texture Pointer to Texture this sprite will use
     * @param p_config Pointer to SpriteSheetConfig this sprite will use
     */
    Sprite(Texture* p_texture, SpriteSheetConfig* p_config = NULL);
    /**
     * @brief Get the Texture object
     * 
     * @return Texture* 
     */
    Texture* getTexture();
    SDL_Texture* getSdlTexture();
    SDL_Rect& getFrame(int p_frameIndex, bool p_allowIndexOverflow = false);
    int getWidth();
    int getHeight();

    private:
    Texture* texture;
    d_array<SDL_Rect> frames;
    int width, height;
    void initializeFrames(SpriteSheetConfig* p_config);
};