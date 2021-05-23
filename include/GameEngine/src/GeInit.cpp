#include "../GameEngine.hpp"

using namespace Game;

bool Init::All()
{
    return (SDL() && SDLImage() && SDLWindow() && SDLRenderer() &&
            GameEntityManager());
}
bool Init::SDL()
{
    bool success = (SDL_Init(SDL_INIT_VIDEO) == 0);
    if (!success)
        Log::SDLError("SDL_Init failed.");
    return success;
}
bool Init::SDLImage()
{
    bool success = (IMG_Init(Settings::IMG_FLAGS));
    if (!success)
        Log::SDLError("IMG_Init failed.");
    return success;
}
bool Init::SDLWindow()
{
    _window =
        SDL_CreateWindow(Settings::WINDOW_TITLE.c_str(), SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED, Settings::WINDOW_WIDTH,
                         Settings::WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    bool success = (_window != NULL);
    if (!success)
        Log::SDLError("SDL_CreateWindow failed.");
    return success;
}
bool Init::SDLRenderer()
{
    _renderer = SDL_CreateRenderer(_window, -1, 0);
    bool success = (_renderer != NULL);
    if (!success)
        Log::SDLError("SDL_CreateRenderer failed.");
    else
        SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    return success;
}
bool Init::GameEntityManager()
{
    _entities = new EntityManager();
    return true;
}