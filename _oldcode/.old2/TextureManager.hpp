#pragma once
#include "Texture.hpp"
#include <SDL2/SDL.h>
#include <string>
#include <unordered_map>

using namespace std;

class TextureManager {
    public:
    TextureManager(SDL_Renderer* p_renderer);
    Texture* getTexture(const string& p_textureId);
    Texture* registerTexture(const string& p_textureId,
                             const string& p_textureFile, bool p_loadTexture);
    void loadTexture(const string& p_textureId);
    void unloadTexture(const string& p_textureId);
    void cleanUp();

    private:
    SDL_Renderer* renderer;
    unordered_map<string, Texture*> textures;
};