#pragma once
// #include "../../GameEngine.hpp"

/** @brief Game loop */
namespace Loop
{
    void Loop();
    void HandleWindowInput();
    void FrameCapStart(unsigned int* p_frameTime);
    void FrameCapEnd(unsigned int* p_frameTime);
    void Update();
    void Render();
}