#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
#include <vector>

#include "../include/Entity.hpp"
#include "../include/RenderWindow.hpp"
#include "../include/Math.hpp"
#include "../include/Utils.hpp"

template <typename T> using d_array = std::vector<T>; // alias std::vector

using namespace std;

int main(int argc, char* args[])
{
    // INITIALIZE
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        cout << "SDL_Init failed. Error: " << SDL_GetError() << endl;
    else if (!IMG_Init(IMG_INIT_PNG))
        cout << "IMG_Init failed. Error: " << SDL_GetError() << endl;
    else
    // ON START
    {
        RenderWindow window("Game", 640, 480);
        cout << "Max FPS for Window: " << window.getRefreshRate() << endl;

        SDL_Texture* sheetTexture =
            window.loadTexture("res/images/goldenboy-sheet.png");
        // Entity block(16,16,sheetTexture);

        d_array<Entity> entities = {
            Entity(Vector(16, 16), sheetTexture),
            Entity(Vector(16, 32), sheetTexture),
        };

        bool gameRunning = true;
        SDL_Event event;

        const float timeStep = 0.01f;
        float accumulator = 0.0f;
        float currentTime = utils::hireTimeInSeconds();

        // GAME LOOP
        while (gameRunning)
        {
            int startTicks = SDL_GetTicks();

            float newTime = utils::hireTimeInSeconds();
            float frameTime = newTime - currentTime;
            currentTime = newTime;
            accumulator += frameTime;

            while (accumulator >= timeStep)
            {
                accumulator -= timeStep;
            }
            const float alpha = accumulator / timeStep;

            while (SDL_PollEvent(&event))
                if (event.type == SDL_QUIT) gameRunning = false;

            // RENDER
            window.clear();

            for (Entity &e : entities)
                window.render(e);

            window.display();

            int frameTicks = SDL_GetTicks() - startTicks;
            int msPerFrame = (1000 / window.getRefreshRate());
            if (frameTicks < msPerFrame)
                SDL_Delay(msPerFrame - frameTicks);
        }

        // ON END
        SDL_DestroyTexture(sheetTexture);
        sheetTexture = NULL;

        // CLEANUP
        window.cleanUp();
    }
    SDL_Quit();
    return 0;
}