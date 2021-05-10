#include "Game.hpp"

Game::Game() : isRunning(true) {}

void Game::run()
{
    if (initialize())
    {
        onGameStart();
        while (isRunning)
        {
            checkWindowInput();
            if (!isRunning)
                continue;

            update();
            render();
        }
        onGameEnd();
    }
    cleanUp();
}

bool Game::initialize()
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        logSdlError("SDL_Init failed.");
    else if (!IMG_Init(IMG_INIT_PNG))
        logSdlError("IMG_Init failed.");
    else
    {
        std::string windowName = "Game";
        int windowWidth = 640, windowHeight = 480;
        window = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_UNDEFINED,
                                  SDL_WINDOWPOS_UNDEFINED, windowWidth,
                                  windowHeight, SDL_WINDOW_SHOWN);
        if (window == NULL)
            logSdlError("SDL_CreateWindow failed.");
        else
        {
            renderer = SDL_CreateRenderer(window, -1, 0);
            if (renderer == NULL)
                logSdlError("SDL_CreateRenderer failed.");
            else
            {
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                return true; // success!
            }
        }
    }
    return false;
}

void Game::cleanUp()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

void Game::checkWindowInput()
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

void Game::update()
{
    // TODO update objects
}

void Game::render()
{
    SDL_RenderClear(renderer);
    // TODO render objects
    SDL_RenderPresent(renderer);
}

void Game::log(const std::string& p_message)
{
    SDL_Log((p_message + "\n").c_str());
}

void Game::logError(const std::string& p_message)
{
    SDL_LogError(0, (p_message + "\n").c_str());
}

void Game::logSdlError(const std::string& p_message)
{
    logError(p_message + " Error: " + SDL_GetError());
}