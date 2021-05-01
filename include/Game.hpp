#pragma once

#include <SDL2/SDL.h>

class Game {
    public:
    Game();
    ~Game();

    void init(const char* p_title, int p_width, int p_height);
    void handleEvents();
    void update();
    void render();
    void clean();
    bool running()
    {
        return isRunning;
    }

    private:
    bool isRunning;
    SDL_Window* window;
    SDL_Renderer* renderer;

    bool initializeSDL();
    bool initializeImageLoading();
    bool initializeWindow(const char* p_title, int p_width, int p_height);
    bool initializeRenderer();
};