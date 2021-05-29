#include "../GameEngine.hpp"

using namespace Game;

void Log::Log(const std::string& p_message)
{
    SDL_Log((p_message + "\n").c_str());
}
void Log::Error(const std::string& p_message)
{
    SDL_LogError(0, (p_message + "\n").c_str());
}
void Log::SDLError(const std::string& p_message)
{
    Error(p_message + " Error: " + SDL_GetError());
}