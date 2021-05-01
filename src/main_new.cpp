#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../include/Game.hpp"

using namespace std;

int main(int argc, char* args[])
{
    // FPS cap
    const int maxFramesPerSecond = 60;
    const int minMilisPerFrame = 1000 / maxFramesPerSecond;
    Uint32 frameStartTimeInMilis;
    int frameTimeLengthInMilis;

    Game* game = new Game();
    game->init("GAME", 640, 480);
    while (game->running())
    {
        frameStartTimeInMilis = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();

        frameTimeLengthInMilis = SDL_GetTicks() - frameStartTimeInMilis;
        if (minMilisPerFrame > frameTimeLengthInMilis)
            SDL_Delay(minMilisPerFrame - frameTimeLengthInMilis);
    }
    game->clean();

    return 0;
}