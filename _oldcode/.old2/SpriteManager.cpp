#include "SpriteManager.hpp"

void SpriteManager::registerSprite(const string& p_spriteId, Texture* p_texture,
                                   SpriteSheetConfig* p_config)
{
    if (sprites.find(p_spriteId) != sprites.end())
        throw "Cannot register sprite with id '" + p_spriteId +
            "' because that id already exists.";

    Sprite* sprite = new Sprite(p_texture, p_config);
    sprites[p_spriteId] = sprite;
}

Sprite* SpriteManager::getSprite(const string& p_spriteId)
{
    if (sprites.find(p_spriteId) == sprites.end())
        throw "Cannot find sprite with id '" + p_spriteId + "'.";

    return sprites[p_spriteId];
}

void SpriteManager::cleanUp()
{
    unordered_map<string, Sprite*>::iterator i;
    for (i = sprites.begin(); i != sprites.end(); i++)
    {
        string spriteId = i->first;
        delete sprites[spriteId];
    }
    sprites.clear();
}
