#pragma once

using Microsoft::WRL::ComPtr;

class Window {
public:
    Window(HINSTANCE hInstance, int nCmdShow);
    bool Initialize();
    void Run();

    HINSTANCE hInstance;
    HWND hwnd;
    int nCmdShow;

private:

    ComPtr<ID3D12Device> device;
    ComPtr<ID3D12CommandQueue> commandQueue;
    ComPtr<IDXGISwapChain4> swapChain;

    bool CreateRenderWindow();
    static LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    bool InitializeDirectX();
};
