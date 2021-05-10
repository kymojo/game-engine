#include "Texture.hpp"

Texture::Texture(const string& p_file, SDL_Renderer* p_renderer)
{
    isLoaded = false;
    filename = p_file;
    renderer = p_renderer;
}
SDL_Texture* Texture::getSdlTexture()
{
    return texture;
}
int Texture::getWidth(){
    if (!isLoaded)
        throw "Cannot get width of texture file '" + filename + "' when it is not loaded.";
    
    return width;
}
int Texture::getHeight(){
    if (!isLoaded)
        throw "Cannot get height of texture file '" + filename + "' when it is not loaded.";
    
    return height;
}
void Texture::loadTexture()
{
    if (isLoaded)
        return;

    SDL_Surface* surface = IMG_Load(filename.c_str());
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_QueryTexture(texture,NULL,NULL,&width,&height);

    isLoaded = true;
}
void Texture::unloadTexture()
{
    if (!isLoaded)
        return;

    SDL_DestroyTexture(texture);
    isLoaded = false;
}
bool Texture::loaded()
{
    return isLoaded;
}