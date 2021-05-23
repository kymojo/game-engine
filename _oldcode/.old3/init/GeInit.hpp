#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../entities/EntityManager.hpp"
#include "../log/GeLog.hpp"
#include "../core/GeCore.hpp"

using namespace Game;

/** @brief Game initialization */
namespace Init
{
    bool All();
    bool SDL();
    bool SDLImage();
    bool SDLWindow();
    bool SDLRenderer();
    bool GameEntityManager();
}