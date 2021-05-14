#pragma once

#include "SpriteManager.hpp"
#include "TextureManager.hpp"
#include <SDL2/SDL.h>
#include <string>

/*
    Game
    - texture bank (textures have code names)
    - sprites bank (sprites have code names)
    - room
    - viewport

    Game:
        Room
        View
        Object
*/

template <typename T> using d_array = std::vector<T>;
using namespace std;

class Game {
    public:
    Game();
    ~Game();

    void run(const string& p_title, int p_width, int p_height);
    void init(const string& p_title, int p_width, int p_height);
    void handleEvents();
    virtual void update() {}
    void clean();
    bool initialized()
    {
        return isInitialized;
    }
    bool running()
    {
        return isRunning;
    }
    virtual void onStart() {}
    virtual void onEnd() {}

    protected:
    bool isInitialized;
    bool isRunning;
    SDL_Window* window;
    SDL_Renderer* renderer;
    TextureManager* textures;
    SpriteManager* sprites;

    bool initializeSDL();
    bool initializeImageLoading();
    bool initializeWindow(const string& p_title, int p_width, int p_height);
    bool initializeRenderer();
    bool initializeTextureManager();
    bool initializeSpriteManager();
    
    void logErrorLine(const string& error);
    string getSdlErrorString();
};