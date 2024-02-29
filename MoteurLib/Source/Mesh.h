#pragma once
#include "pch.h"
#include <array>

class Mesh
{
public :

    Mesh();
    ~Mesh();

    void BuildBox();

private :

    Microsoft::WRL::ComPtr<ID3D12Resource> CreateDefaultBuffer(
        ID3D12Device* device,
        ID3D12GraphicsCommandList* cmdList,
        const void* initData, UINT64 byteSize,
        Microsoft::WRL::ComPtr<ID3D12Resource>& uploadBuffer);

    Vertex vertex;

};

struct Vertex
{
    XMFLOAT3 Position;
    XMFLOAT4 Color;
};
