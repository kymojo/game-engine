#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <vector>
#include "Entity.hpp"
#include "Component.hpp"
#include "EntityManager.hpp"
#include "Vector2.hpp"
#include "Texture.hpp"
// .tpp files included at bottom

namespace Game
{
    void Game_Init();
    void Game_Launch(void(*p_update)(unsigned int));
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
        void Loop(void(*p_update)(unsigned int));
        void HandleWindowInput();
        void FrameCapStart(unsigned int* p_gameTicks);
        unsigned int FrameCapEnd(unsigned int* p_gameTicks);
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
        template <class E> void add(E* p_entity, const std::string &p_type);
        template <class E> void remove(E* p_entity);
        template <class C, class E> void addComponentTo(C* p_component, E* p_entity);
        template <class C, class E> void removeComponentFrom(E* p_entity);
        template <class C> std::vector<Entity*> getAllWithComponent();
        template <class E> std::vector<E*> getAllOfClass();
        template <class E> void forEach(void(*p_each)(E*));
        template <class C, class E> C* getComponentOf(E* p_entity);
        template <class E, class T> bool isEntityOfType(E* p_entity);
    }

    namespace Resources
    {
        // void Game_RegisterTexture();
        // void Game_LoadTexture();
        // void Game_UnloadTexture();
        // void Game_RegisterSprite();
    }

    namespace Render
    {
        void clear();
        void update();
        void setColor(unsigned short p_r, unsigned short p_g, unsigned short p_b, unsigned short p_a = 255);

        void drawPoint(int p_x, int p_y);
        void drawPoint(const Vector2 &p_position);
        void drawLine(int p_x1, int p_y1, int p_x2, int p_y2);
        void drawLine(const Vector2 &p_start, const Vector2 &p_end);
        void drawRectangle(int p_x, int p_y, int p_w, int p_h, bool filled = true);
        void drawRectangle(const Vector2 &p_position, const Vector2 &p_dimension, bool filled = true);
        void drawTexture(int p_x, int p_y, const Texture &p_texture);
    }
}
#include "Game.tpp"
// .hpp files included at top
#include "EntityManager.tpp"
#include "Entity.tpp"