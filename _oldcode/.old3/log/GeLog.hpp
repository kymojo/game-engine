#pragma once
// #include "../../GameEngine.hpp"
#include <string>

/** @brief Game logging */
namespace Log
{
    void Log(const std::string& p_message);
    void Error(const std::string& p_message);
    void SDLError(const std::string& p_message);
}