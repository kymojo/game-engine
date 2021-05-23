#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "src/EntityManager.hpp"

namespace Game
{
    void Game_Init();
    void Game_Launch();
    void Game_CleanUp();

    extern bool _isRunning;
    extern bool _isInitialized;
    extern bool _initializeAttempted;
    
    extern SDL_Window* _window;
    extern SDL_Renderer* _renderer;
    extern EntityManager* _entities;

    namespace Settings
    {
        extern std::string WINDOW_TITLE;
        extern int WINDOW_WIDTH;
        extern int WINDOW_HEIGHT;
        extern int IMG_FLAGS;
        extern int FPS_CAP;
    }

    namespace Init
    {
        bool All();
        bool SDL();
        bool SDLImage();
        bool SDLWindow();
        bool SDLRenderer();
        bool GameEntityManager();
    }

    namespace Loop
    {
        void Loop();
        void HandleWindowInput();
        void FrameCapStart(unsigned int* p_frameTime);
        void FrameCapEnd(unsigned int* p_frameTime);
        void Update();
        void Render();
    }

    namespace Log
    {
        void Log(const std::string& p_message);
        void Error(const std::string& p_message);
        void SDLError(const std::string& p_message);
    }

    namespace Entities
    {
        template <class T> Entity* create(T* p_entity);
        void destroy(unsigned int p_entityId);
        template <class T> Entity** withComponent();
        template <class T> Entity** ofType();
    }

    namespace Resources
    {
        // void Game_RegisterTexture();
        // void Game_LoadTexture();
        // void Game_UnloadTexture();
        // void Game_RegisterSprite();
    }
}