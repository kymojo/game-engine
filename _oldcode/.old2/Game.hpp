#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
// #include "SpriteManager.hpp"
// #include "TextureManager.hpp"
// #include "GameObjectManager.hpp"
// #include "CameraManager.hpp"

class Game {
    public:
    Game() : isInitialized(false), isRunning(true) {}

    protected:
    bool isInitialized, isRunning;
    // SpriteManager sprites;
    // TextureManager textures;
    // GameObjectManager objects;
    // CameraManager cameras;

    SDL_Window* window;
    SDL_Renderer* renderer;

    void initialize();
    void cleanUp();
    void checkWindowInput();
    void update();
    void render();
    virtual void onGameStart();
    virtual void onGameEnd();

    bool initializeSDL();
    bool initializeImageLoading();
    bool initializeWindow(const std::string& p_title, int p_width, int p_height);
    bool initializeRenderer();
    bool initializeTextureManager();
    bool initializeSpriteManager();
    void logErrorLine(const std::string& error);
    std::string getSdlErrorString();
};