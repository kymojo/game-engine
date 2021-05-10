#include "src/MyGame.cpp"

int main(int argc, char* args[])
{
    MyGame* game = new MyGame();
    game->run();
    delete game;
    return 0;
}