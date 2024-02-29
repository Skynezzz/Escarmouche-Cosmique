#include "pch.h"
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
<<<<<<< HEAD
            //mPlayer.Update(mTime);
=======
            // mPlayer.Update(mTime);
>>>>>>> 06f004f7d84d3ea227f36d3c934a9c3e9876652e

            // Display
        }
    }
}