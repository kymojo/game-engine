#include "../GameEngine.hpp"

bool Game::_isRunning = true;
bool Game::_isInitialized = false;
bool Game::_initializeAttempted = false;
SDL_Window* Game::_window;
SDL_Renderer* Game::_renderer;
EntityManager* Game::_entities;

std::string Game::Settings::WINDOW_TITLE = "Game";
int Game::Settings::WINDOW_WIDTH = 640;
int Game::Settings::WINDOW_HEIGHT = 480;
int Game::Settings::IMG_FLAGS = IMG_INIT_PNG;
int Game::Settings::FPS_CAP = 60;

void Game::Game_Init()
{
    if (_initializeAttempted)
    {
        Log::Log("Game_Init failed because it has already been called once.");
        return;
    }
    _isInitialized = Init::All();
    _initializeAttempted = true;
}

void Game::Game_Launch()
{
    if (!_isInitialized)
    {
        Log::Error("Game_Launch failed because Game_Init has not successfully "
                   "been called.");
        return;
    }
    // TODO onGameStart();
    Loop::Loop();
    // TODO onGameEnd();
}
void Game::Game_CleanUp()
{
    SDL_DestroyWindow(_window);
    SDL_DestroyRenderer(_renderer);
    SDL_Quit();
}