#include "Engine.h"

Engine::Engine(HINSTANCE hInstance) : mWindow(hInstance)
{}

Engine::~Engine()
{}

bool Engine::Initialize()
{
    if ( !mWindow.Initialize() )
    {
        return false;
    }

    // All init //

    return true;
}

void Engine::Run()
{
    MSG msg = { 0 };

    while ( msg.message != WM_QUIT )
    {
        // Input
        if ( PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE) )
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {
            // Mettre à jour le temps
            mTime.Tick();

            // Update
            mPlayer.Update(mTime);

            // Display
        }
    }
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pCmdLine, int nShowCmd)
{
    Engine engine(hInstance);

    if ( !engine.Initialize() )
    {
        return 1;
    }

    engine.Run();

    return 0;
}