#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "../entities/EntityManager.hpp"
#include "../init/GeInit.hpp"
#include "../log/GeLog.hpp"
#include "../loop/GeLoop.hpp"

namespace Game
{
    /** @brief Initialize game */
    void Game_Init();

    /** @brief Launch game loop */
    void Game_Launch();

    /** @brief Clean game and uninitialize */
    void Game_CleanUp();

    /** @brief Game environment variables */
    namespace Settings
    {
        /** @brief Title of the game window */
        extern std::string WINDOW_TITLE;

        /** @brief Width of game window in pixels */
        extern int WINDOW_WIDTH;

        /** @brief Height of game window in pixels */
        extern int WINDOW_HEIGHT;

        /** @brief Flags for SDL_image init */
        extern int IMG_FLAGS;

        /** @brief Max number of frames per second allowed */
        extern int FPS_CAP;
    }

    /** @brief Flag identifying if game is running */
    bool _isRunning = true;

    /** @brief Flag identifying if game is initialized */
    bool _isInitialized = false;

    /** @brief Flag identifying if game initialization was attempted */
    bool _initializeAttempted = false;

    /** @brief Game window */
    SDL_Window* _window;

    /** @brief Game renderer */
    SDL_Renderer* _renderer;

    /** @brief Game entity manager */
    EntityManager* _entities;
}