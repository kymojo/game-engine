// #include <iostream>
#include <string>
#include "include/GameEngine/Game.hpp"
#include "src/Ball.hpp"

using namespace Game;

void GameUpdate(unsigned int delta);

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

    new Ball(16,16);
    new Ball(48,48);

    Game_Launch(&GameUpdate);
    Game_CleanUp();

    // Vector v;
    // Vector b(0,0);
    // v.add(b);

    return 0;
}

class BallUpdateSystem {
    public:
    static void update(unsigned int delta)
    {
        Entities::forEach<Ball>(&updateBall);
    }
    private:
    static void updateBall(Ball* ball)
    {
        PositionComponent* p = ball->get<PositionComponent>();
        int x = p->position.x;
        int y = p->position.y;
        Render::setColor(255,0,0);
        Render::drawRectangle(x,y,32,32);
    }
};

void GameUpdate(unsigned int delta)
{
    Render::clear();
    
    BallUpdateSystem::update(delta);

    Render::update();
}