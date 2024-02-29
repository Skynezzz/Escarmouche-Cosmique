#pragma once

#include "Window.h"
#include "Timer.h"

class Engine
{
public:
    Engine(HINSTANCE hInstance);
    ~Engine();

    bool Initialize();
    void Run();

private:
    Window mWindow;
    Timer mTime;
};