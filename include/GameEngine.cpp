#include "GameEngine.hpp"

std::string Game::WINDOW_TITLE = "Game";
int Game::WINDOW_WIDTH = 640;
int Game::WINDOW_HEIGHT = 480;
int Game::IMG_FLAGS = IMG_INIT_PNG;
int Game::FPS_CAP = 60;

void Game_Init()
{
    if (_initializeAttempted)
    {
        Log::Log("Game_Init failed because it has already been called once.");
        return;
    }
    _isInitialized = Init::All();
    _initializeAttempted = true;
}

void Game_Launch()
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
void Game_CleanUp()
{
    SDL_DestroyWindow(_window);
    SDL_DestroyRenderer(_renderer);
    SDL_Quit();
}

void Game_RegisterTexture();
void Game_LoadTexture();
void Game_UnloadTexture();
void Game_RegisterSprite();

void Game_AddObject();
void Game_RemoveObject();

void Loop::Loop()
{
    unsigned int frameTime;
    while (_isRunning)
    {
        Loop::FrameCapStart(&frameTime);

        Loop::HandleWindowInput();
        if (!_isRunning)
            break;

        Loop::Update();
        Loop::Render();

        Loop::FrameCapEnd(&frameTime);
    }
}
void Loop::HandleWindowInput()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                _isRunning = false;
                break;
            default:
                break;
        }
    }
}
void Loop::FrameCapStart(unsigned int* p_frameTime)
{
    *p_frameTime = SDL_GetTicks();
}
void Loop::FrameCapEnd(unsigned int* p_frameTime)
{
    int minMilisPerFrame = 1000 / Game::FPS_CAP;
    int frameTimeLengthInMilis = SDL_GetTicks() - *p_frameTime;
    if (minMilisPerFrame > frameTimeLengthInMilis)
        SDL_Delay(minMilisPerFrame - frameTimeLengthInMilis);
}
void Loop::Update()
{
    // TODO update objects
}
void Loop::Render()
{
    SDL_RenderClear(_renderer);
    // TODO render objects
    SDL_RenderPresent(_renderer);
}

void Log::Log(const std::string& p_message)
{
    SDL_Log((p_message + "\n").c_str());
}
void Log::Error(const std::string& p_message)
{
    SDL_LogError(0, (p_message + "\n").c_str());
}
void Log::SDLError(const std::string& p_message)
{
    Error(p_message + " Error: " + SDL_GetError());
}