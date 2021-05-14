#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>

#include "Game.hpp"
#include "SpriteManager.hpp"
#include "TextureManager.hpp"

using namespace std;

Game::Game()
{
    isInitialized = false;
    isRunning = true;
}
Game::~Game() {}

void Game::run(const string& p_title, int p_width, int p_height)
{
    init(p_title, p_width, p_height);
    if (isInitialized)
    {
        const int maxFramesPerSecond = 60;
        const int minMilisPerFrame = 1000 / maxFramesPerSecond;
        Uint32 frameStartTimeInMilis;
        int frameTimeLengthInMilis;

        try
        {
            onStart();
            while (isRunning)
            {
                frameStartTimeInMilis = SDL_GetTicks();

                handleEvents();

                SDL_RenderClear(renderer);
                update();
                SDL_RenderPresent(renderer);

                frameTimeLengthInMilis = SDL_GetTicks() - frameStartTimeInMilis;
                if (minMilisPerFrame > frameTimeLengthInMilis)
                    SDL_Delay(minMilisPerFrame - frameTimeLengthInMilis);
            }
            onEnd();
        }
        catch (string& error)
        {
            logErrorLine("Game encountered an unexpected error: " + error);
        }
    }
    clean();
}
void Game::init(const string& p_title, int p_width, int p_height)
{
    bool successful = true;
    successful = successful && initializeSDL();
    successful = successful && initializeImageLoading();
    successful = successful && initializeWindow(p_title, p_width, p_height);
    successful = successful && initializeRenderer();
    successful = successful && initializeTextureManager();
    successful = successful && initializeSpriteManager();

    isInitialized = successful;
}
void Game::handleEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                isRunning = false;
                break;
            default:
                break;
        }
    }
}
void Game::clean()
{
    textures->clean();
    sprites->clean();
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

bool Game::initializeSDL()
{
    bool success = (SDL_Init(SDL_INIT_VIDEO) == 0);
    if (!success)
    {
        logErrorLine("SDL_Init failed. Error: " + getSdlErrorString());
    }
    return success;
}
bool Game::initializeImageLoading()
{
    bool success = IMG_Init(IMG_INIT_PNG);
    if (!success)
        logErrorLine("IMG_Init failed. Error: " + getSdlErrorString());
    return success;
}
bool Game::initializeWindow(const string& p_title, int p_width, int p_height)
{
    window = SDL_CreateWindow(p_title.c_str(), SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, p_width, p_height,
                              SDL_WINDOW_SHOWN);
    bool success = (window != NULL);
    if (!success)
        logErrorLine("SDL_CreateWindow failed. Error: " + getSdlErrorString());
    return success;
}
bool Game::initializeRenderer()
{
    renderer = SDL_CreateRenderer(window, -1, 0);
    bool success = (renderer != NULL);
    if (!success)
        logErrorLine("SDL_CreateRenderer failed. Error: " + getSdlErrorString());
    else
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    return success;
}
bool Game::initializeTextureManager()
{
    bool success = true;
    try
    {
        textures = new TextureManager(renderer);
    }
    catch (const string& error)
    {
        success = false;
        logErrorLine("TextureManager failed to initialize. Error: " + error);
    }
    return success;
}
bool Game::initializeSpriteManager()
{
    bool success = true;
    try
    {
        sprites = new SpriteManager();
    }
    catch (const string& error)
    {
        success = false;
        logErrorLine("SpriteManager failed to initialize. Error: " + error);
    }
    return success;
}
void Game::logErrorLine(const string& error)
{
    SDL_LogError(0,(error + "\n").c_str());
}
string Game::getSdlErrorString()
{
    return to_string(*SDL_GetError());
}