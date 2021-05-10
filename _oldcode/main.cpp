#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

#include "../include/Game.hpp"
#include "../include/Entity.hpp"
#include "../include/Sprite.hpp"
#include "../include/Texture.hpp"
#include "../include/SpriteSheetConfig.hpp"
#include "../include/TextureManager.hpp"
#include "../include/SpriteManager.hpp"
#include "../include/Math.hpp"

using namespace std;

class MyGame : public Game {
    private:
    Entity* objGoldenboy;

    public:
    void onStart()
    {
        textures->registerTexture("sheet","res/images/goldenboy-sheet.png",true);
        sprites->registerSprite("goldenboy",textures->getTexture("sheet"),Vector(16,0),16,16);
        sprites->registerSprite("block",textures->getTexture("sheet"),Vector(0,0),16,16);
        
        objGoldenboy = new Entity();
        objGoldenboy->setSprite(sprites->getSprite("goldenboy"));
    }
    void update()
    {
        const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
        if (currentKeyStates[SDL_SCANCODE_UP])
        {
            objGoldenboy->setPositionRelative(Vector(0,-4));
        }
        if (currentKeyStates[SDL_SCANCODE_DOWN])
        {
            objGoldenboy->setPositionRelative( Vector(0,4));
        }
        if (currentKeyStates[SDL_SCANCODE_LEFT])
        {
            objGoldenboy->setPositionRelative(Vector(-4,0));
        }
        if (currentKeyStates[SDL_SCANCODE_RIGHT])
        {
            objGoldenboy->setPositionRelative(Vector(4,0));
        }

        objGoldenboy->render(renderer);
    }
    void onEnd()
    {
        delete objGoldenboy;
    }
};

int main(int argc, char* args[])
{
    MyGame* game = new MyGame();
    game->run("GAME", 640, 480);
    return 0;
}
