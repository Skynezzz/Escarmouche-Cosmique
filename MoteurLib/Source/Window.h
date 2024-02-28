#pragma once

#include <Windows.h>
#include <string>

class Window
{
public:
    Window(HINSTANCE hInstance);
    ~Window();

    bool Initialize();
    void Show();
    HWND GetHWND() const { return mhMainWnd; }
    int GetClientWidth() const { return mClientWidth; }
    int GetClientHeight() const { return mClientHeight; }

private:
    bool InitMainWindow();
    static LRESULT CALLBACK MainWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

private:
    HINSTANCE mhAppInst = nullptr; // application instance handle
    HWND      mhMainWnd = nullptr; // main window handle
    int mClientWidth = 800;
    int mClientHeight = 600;
    std::wstring mMainWndCaption = L"Window";
};