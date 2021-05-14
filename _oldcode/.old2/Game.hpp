#pragma once

#include "GameObject.hpp"
#include "GameObjectManager.hpp"
#include "TextureManager.hpp"
#include "SpriteManager.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>
#include <string>

class Game {
    public:
    Game();
    void run();

    static void log(const std::string& p_message);
    static void logError(const std::string& p_message);
    static void logSdlError(const std::string& p_message);

    protected:
    bool isRunning;
    SDL_Renderer* renderer;
    SDL_Window* window;
    GameObjectManager* objects;
    TextureManager* textures;
    SpriteManager* sprites;
    int fpsCap;

    bool initialize();
    void cleanUp();

    void checkWindowInput();
    void update();
    void render();
    void renderObjects();
    virtual void onGameStart() {}
    virtual void onGameEnd() {}
    void startFrameCap(unsigned int* p_frameTime);
    void endFrameCap(unsigned int* p_frameTime);

    template <class T> T* createObject()
    {
        return objects->addObject<T>();
    }

    void deleteObject(GameObject* p_object);
};