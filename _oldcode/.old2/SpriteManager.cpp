#include "SpriteManager.hpp"

void SpriteManager::registerSprite(const string& p_spriteId, Texture* p_texture)
{
    if (sprites.find(p_spriteId) != sprites.end())
        throw "Cannot register sprite with id '" + p_spriteId +
            "' because that id already exists.";

    Sprite* sprite = new Sprite(p_texture);
    sprites[p_spriteId] = sprite;
}

void SpriteManager::registerSprite(const string& p_spriteId, Texture* p_texture,
                                   const Vector& p_textureOrigin,
                                   int p_spriteWidth, int p_spriteHeight)
{
    registerSprite(p_spriteId, p_texture, p_textureOrigin, p_spriteWidth,
                   p_spriteHeight, 1, 1, 0, 0);
}

void SpriteManager::registerSprite(const string& p_spriteId, Texture* p_texture,
                                   const Vector& p_textureOrigin,
                                   int p_spriteWidth, int p_spriteHeight,
                                   int p_frameCount, int p_frameColumns,
                                   int p_frameColumnOffset,
                                   int p_frameRowOffset)
{
    if (sprites.find(p_spriteId) != sprites.end())
        throw "Cannot register sprite with id '" + p_spriteId +
            "' because that id already exists.";

    SpriteSheetConfig config;
    config.textureOrigin = p_textureOrigin;
    config.spriteWidth = p_spriteWidth;
    config.spriteHeight = p_spriteHeight;
    config.frameCount = p_frameCount;
    config.frameColumns = p_frameColumns;
    config.frameColumnOffset = p_frameColumnOffset;
    config.frameRowOffset = p_frameRowOffset;

    Sprite* sprite = new Sprite(p_texture, &config);
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
