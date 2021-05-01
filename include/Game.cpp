#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "Game.hpp"

using namespace std;

Game::Game() {}
Game::~Game() {}

void Game::init(const char* p_title, int p_width, int p_height)
{
    bool successful = true;
    successful = successful && initializeSDL();
    successful = successful && initializeImageLoading();
    successful = successful && initializeWindow(p_title, p_width, p_height);
    successful = successful && initializeRenderer();

    isRunning = successful;
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
void Game::update() {}
void Game::render()
{
    SDL_RenderClear(renderer);
    // Do render here
    SDL_RenderPresent(renderer);
}
void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

bool Game::initializeSDL()
{
    bool success = (SDL_Init(SDL_INIT_VIDEO) == 0);
    if (!success)
        cout << "SDL_Init failed. Error: " << SDL_GetError() << endl;
    return success;
}
bool Game::initializeImageLoading()
{
    bool success = IMG_Init(IMG_INIT_PNG);
    if (!success)
        cout << "IMG_Init failed. Error: " << SDL_GetError() << endl;
    return success;
}
bool Game::initializeWindow(const char* p_title, int p_width, int p_height)
{
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, p_width, p_height,
                              SDL_WINDOW_SHOWN);
    bool success = (window != NULL);
    if (!success)
        cout << "SDL_CreateWindow failed. Error: " << SDL_GetError() << endl;
    return success;
}
bool Game::initializeRenderer()
{
    renderer = SDL_CreateRenderer(window, -1, 0);
    bool success = (renderer != NULL);
    if (!success)
        cout << "SDL_CreateRenderer failed. Error: " << SDL_GetError() << endl;
    else
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    return success;
}