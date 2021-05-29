#include "Game.hpp"

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

void Game::Game_Launch(void(*p_update)(unsigned int))
{
    if (!_isInitialized)
    {
        Log::Error("Game_Launch failed because Game_Init has not successfully "
                   "been called.");
        return;
    }
    try
    {
        // TODO onGameStart();

        Loop::Loop(p_update);
        
        // TODO onGameEnd();
    } catch (std::string &err)
    {
        Log::Error(err);
    }
}
void Game::Game_CleanUp()
{
    SDL_DestroyWindow(_window);
    SDL_DestroyRenderer(_renderer);
    SDL_Quit();
}

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

void Loop::Loop(void(*p_update)(unsigned int))
{
    unsigned int gameTicks;
    unsigned int prevFrameTime;
    while (_isRunning)
    {
        FrameCapStart(&gameTicks);

        HandleWindowInput();
        if (!_isRunning)
            break;

        p_update(prevFrameTime);

        prevFrameTime = FrameCapEnd(&gameTicks);
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
void Loop::FrameCapStart(unsigned int* p_gameTicks)
{
    *p_gameTicks = SDL_GetTicks();
}
unsigned int Loop::FrameCapEnd(unsigned int* p_gameTicks)
{
    unsigned int minMilisPerFrame = 1000 / Settings::FPS_CAP;
    unsigned int frameTimeLengthInMilis = SDL_GetTicks() - *p_gameTicks;
    if (minMilisPerFrame > frameTimeLengthInMilis)
        SDL_Delay(minMilisPerFrame - frameTimeLengthInMilis);
    return std::max<unsigned int>(frameTimeLengthInMilis,minMilisPerFrame);
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

void Render::clear()
{
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    SDL_RenderClear(_renderer);
}
void Render::update()
{
    SDL_RenderPresent(_renderer);
}
void Render::setColor(unsigned short p_r, unsigned short p_g, unsigned short p_b, unsigned short p_a)
{
    SDL_SetRenderDrawColor(_renderer,p_r,p_g,p_b,p_a);
}
void Render::drawPoint(int p_x, int p_y)
{
    SDL_RenderDrawPoint(_renderer,p_x,p_y);
}
void Render::drawPoint(const Vector2 &p_position)
{
    drawPoint(p_position.x,p_position.y);
}
void Render::drawLine(int p_x1, int p_y1, int p_x2, int p_y2)
{
    SDL_RenderDrawLine(_renderer,p_x1,p_y1,p_x2,p_y2);
}
void Render::drawLine(const Vector2 &p_start, const Vector2 &p_end)
{
    drawLine(p_start.x,p_start.y,p_end.x,p_end.y);
}
void Render::drawRectangle(int p_x, int p_y, int p_w, int p_h, bool filled)
{
    SDL_Rect rect;
    rect.x = p_x;
    rect.y = p_y;
    rect.w = p_w;
    rect.h = p_h;
    if (filled)
        SDL_RenderFillRect(_renderer,&rect);
    else
        SDL_RenderDrawRect(_renderer,&rect);
}
void Render::drawRectangle(const Vector2 &p_position, const Vector2 &p_dimension, bool filled)
{
    drawRectangle(p_position.x,p_position.y,p_dimension.x,p_dimension.y,filled);
}