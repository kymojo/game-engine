#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

class Game {
    public:
    Game();
    void run();

    protected:
    bool isRunning;
    SDL_Renderer* renderer;
    SDL_Window* window;

    bool initialize();
    void cleanUp();

    void log(const std::string& p_message);
    void logError(const std::string& p_message);
    void logSdlError(const std::string& p_message);

    void checkWindowInput();
    void update();
    void render();
    virtual void onGameStart() {}
    virtual void onGameEnd() {}
};