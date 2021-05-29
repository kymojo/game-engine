#include "../GameEngine.hpp"

using namespace Game;

void Loop::Loop()
{
    unsigned int frameTime;
    while (_isRunning)
    {
        FrameCapStart(&frameTime);

        HandleWindowInput();
        if (!_isRunning)
            break;

        Update();
        Render();

        FrameCapEnd(&frameTime);
    }
}
void Loop::HandleWindowInput()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                _isRunning = false;
                break;
            default:
                break;
        }
    }
}
void Loop::FrameCapStart(unsigned int* p_frameTime)
{
    *p_frameTime = SDL_GetTicks();
}
void Loop::FrameCapEnd(unsigned int* p_frameTime)
{
    int minMilisPerFrame = 1000 / Settings::FPS_CAP;
    int frameTimeLengthInMilis = SDL_GetTicks() - *p_frameTime;
    if (minMilisPerFrame > frameTimeLengthInMilis)
        SDL_Delay(minMilisPerFrame - frameTimeLengthInMilis);
}
void Loop::Update()
{
    // TODO update objects
}
void Loop::Render()
{
    SDL_RenderClear(_renderer);
    // TODO render objects
    SDL_RenderPresent(_renderer);
}