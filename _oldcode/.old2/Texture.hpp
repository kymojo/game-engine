#pragma once
#include <SDL2/SDL.h>
#include <string>

using namespace std;

class Texture
{
    public:
    Texture(const string& p_file, SDL_Renderer* p_renderer);
    SDL_Texture* getSdlTexture();
    void loadTexture();
    void unloadTexture();
    bool loaded();
    int getWidth();
    int getHeight();

    private:
    bool isLoaded;
    string filename;
    int width;
    int height;
    SDL_Texture* texture;
    SDL_Renderer* renderer;
};