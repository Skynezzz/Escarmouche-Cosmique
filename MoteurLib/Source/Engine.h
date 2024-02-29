#pragma once
#include "Window.h"
#include "Timer.h"   // Supposons que tu as une classe Time
>>>>>>> 06f004f7d84d3ea227f36d3c934a9c3e9876652e

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