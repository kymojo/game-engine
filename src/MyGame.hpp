#include "../include/Game.hpp"
#include "MyObject.hpp"

class MyGame : public Game {
    protected:
    void onGameStart()
    {
        MyObject* obj = createObject<MyObject>();
    }
    void onGameEnd() {
        // TODO
    }
};