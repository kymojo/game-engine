// #include <iostream>
// #include <string>
#include "include/GameEngine/GameEngine.hpp"
#include "src/Ball.hpp"

using namespace Game;

int main(int argc, char* args[])
{
    Settings::WINDOW_TITLE = "Super Cool Game";

    Game_Init();

    /*
        Create Room
        Create Views
        Register Textures
        Register Sprites
        Load Room
    */

   Entities::add(new Ball());

    Game_Launch();
    Game_CleanUp();

    // Vector v;
    // Vector b(0,0);
    // v.add(b);

    return 0;
}