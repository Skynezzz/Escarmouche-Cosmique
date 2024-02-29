#pragma once
#include "Window.h"
#include "Timer.h"   // Supposons que tu as une classe Time

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