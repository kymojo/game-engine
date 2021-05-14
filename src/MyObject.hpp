#include "../include/GameObject.hpp"
#include "../include/Game.hpp"
#include "SpriteComponent.hpp"

class MyObject : public GameObject
{
    public:
    MyObject(unsigned int p_id) : GameObject(p_id)
    {

    }
    void update()
    {
        sprite.update();
    }
    void render()
    {
        sprite.render();
    }
    private:
    SpriteComponent sprite;
};