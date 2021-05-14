#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

void Game_Init();
void Game_Launch();
void Game_CleanUp();

// void Game_RegisterTexture();
// void Game_LoadTexture();
// void Game_UnloadTexture();
// void Game_RegisterSprite();

// void Game_AddObject();
// void Game_RemoveObject();

namespace Game
{
    extern std::string WINDOW_TITLE;
    extern int WINDOW_WIDTH;
    extern int WINDOW_HEIGHT;
    extern int IMG_FLAGS;
    extern int FPS_CAP;
}

namespace // Private members
{
    bool _isRunning = true;
    bool _isInitialized = false;
    bool _initializeAttempted = false;

    SDL_Window* _window;
    SDL_Renderer* _renderer;

    namespace Loop
    {
        void Loop();
        void HandleWindowInput();
        void FrameCapStart(unsigned int* p_frameTime);
        void FrameCapEnd(unsigned int* p_frameTime);
        void Update();
        void Render();
    }

    namespace Init
    {
        bool All();
        bool SDL();
        bool SDLImage();
        bool SDLWindow();
        bool SDLRenderer();
    }
}

namespace Log
{
    void Log(const std::string& p_message);
    void Error(const std::string& p_message);
    void SDLError(const std::string& p_message);
}