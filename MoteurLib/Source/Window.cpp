#include"pch.h"
#include "window.h"

Window::Window(HINSTANCE hInstance, int nCmdShow) : hInstance(hInstance), nCmdShow(nCmdShow) {}

bool Window::Initialize() {
    if ( !CreateRenderWindow() ) {
        throw std::runtime_error("Failed to create render window");
        return false;
    }

    if ( !InitializeDirectX() ) {
        throw std::runtime_error("Failed to initialize DirectX");
        return false;
    }

    return true;
}

void Window::Run() {
    MSG msg = { 0 };

    while ( msg.message != WM_QUIT ) {
        if ( PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE) ) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
}

bool Window::CreateRenderWindow() {
    WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, WindowProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, TEXT("DirectX12 Window"), NULL };
    RegisterClassEx(&wc);
    hwnd = CreateWindow(wc.lpszClassName, TEXT("DirectX12 Window"), WS_OVERLAPPEDWINDOW, 100, 100, 800, 600, NULL, NULL, wc.hInstance, NULL);

    if ( !hwnd )
        return false;

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    return true;
}

LRESULT CALLBACK Window::WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch ( message ) {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
}

bool Window::InitializeDirectX() {
    UINT dxgiFactoryFlags = 0;
#ifdef _DEBUG
    {
        ComPtr<ID3D12Debug> debugController;
        if ( SUCCEEDED(D3D12GetDebugInterface(IID_PPV_ARGS(&debugController))) ) {
            debugController->EnableDebugLayer();
            dxgiFactoryFlags |= DXGI_CREATE_FACTORY_DEBUG;
        }
    }
#endif

    ComPtr<IDXGIFactory4> dxgiFactory;
    if ( FAILED(CreateDXGIFactory2(dxgiFactoryFlags, IID_PPV_ARGS(&dxgiFactory))) )
        return false;

    ComPtr<IDXGIAdapter1> adapter;
    if ( FAILED(dxgiFactory->EnumAdapters1(0, &adapter)) )
        return false;

    if ( FAILED(D3D12CreateDevice(adapter.Get(), D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS(&device))) )
        return false;

    D3D12_COMMAND_QUEUE_DESC queueDesc = {};
    queueDesc.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;
    queueDesc.Priority = D3D12_COMMAND_QUEUE_PRIORITY_NORMAL;
    queueDesc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;
    queueDesc.NodeMask = 0;

    if ( FAILED(device->CreateCommandQueue(&queueDesc, IID_PPV_ARGS(&commandQueue))) )
        return false;

    DXGI_SWAP_CHAIN_DESC1 swapChainDesc = {};
    swapChainDesc.BufferCount = 2;
    swapChainDesc.Width = 800;
    swapChainDesc.Height = 600;
    swapChainDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
    swapChainDesc.SampleDesc.Count = 1;

    ComPtr<IDXGISwapChain1> tempSwapChain;
    if ( FAILED(dxgiFactory->CreateSwapChainForHwnd(commandQueue.Get(), hwnd, &swapChainDesc, nullptr, nullptr, &tempSwapChain)) )
        return false;

    if ( FAILED(tempSwapChain.As(&swapChain)) )
        return false;

    return true;
}
