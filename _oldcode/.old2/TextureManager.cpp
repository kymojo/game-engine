#include "TextureManager.hpp"

TextureManager::TextureManager(SDL_Renderer* p_renderer)
{
    renderer = p_renderer;
}
Texture* TextureManager::getTexture(const string& p_textureId)
{
    if (textures.find(p_textureId) == textures.end())
        throw "Cannot get texture with id '" + p_textureId +
            "' because that id does not exist.";

    return textures[p_textureId];
}
Texture* TextureManager::registerTexture(const string& p_textureId,
                                         const string& p_textureFile,
                                         bool p_loadTexture = false)
{
    if (textures.find(p_textureId) != textures.end())
        throw "Cannot register texture with id '" + p_textureId +
            "' because that id already exists.";

    Texture* texture = new Texture(p_textureFile, renderer);
    textures[p_textureId] = texture;
    loadTexture(p_textureId);
    return texture;
}
void TextureManager::loadTexture(const string& p_textureId)
{
    if (textures.find(p_textureId) == textures.end())
        throw "Cannot load texture with id '" + p_textureId +
            "' because that id does not exist.";

    textures[p_textureId]->loadTexture();
}
void TextureManager::unloadTexture(const string& p_textureId)
{
    if (textures.find(p_textureId) == textures.end())
        throw "Cannot unload texture with id '" + p_textureId +
            "' because that id does not exist.";

    textures[p_textureId]->unloadTexture();
}
void TextureManager::clean()
{
    unordered_map<string, Texture*>::iterator i;
    for (i = textures.begin(); i != textures.end(); i++)
    {
        string textureId = i->first;
        delete textures[textureId];
    }
    textures.clear();
}