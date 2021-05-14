#include <string>
#include <SDL2/SDL.h>
#include "include/GameEngine.hpp"

int main(int argc, char* args[])
{
    Game::WINDOW_TITLE = "Super Cool Game";
    
    Game_Init();
    Game_Launch();
    Game_CleanUp();

    return 0;
}