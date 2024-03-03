#include "pch.h"
#include "Engine.h"

Engine::Engine(HINSTANCE hInstance) : mWindow(hInstance, SW_SHOWNORMAL)
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
            // Mettre � jour le temps
            mTime.Tick();

            // Update

            //mPlayer.Update(mTime);
             
            // Display
        }
    }
}