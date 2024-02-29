#pragma once
#include <array>

class Mesh {
public:
    Mesh(ID3D12Device* device, ID3D12GraphicsCommandList* commandList, const void* vertices, UINT vertexCount, UINT vertexStride, const void* indices, UINT indexCount);
    ~Mesh();

private:
    Microsoft::WRL::ComPtr<ID3D12Resource> vertexBuffer;
    Microsoft::WRL::ComPtr<ID3D12Resource> indexBuffer;
    D3D12_VERTEX_BUFFER_VIEW vertexBufferView;
    D3D12_INDEX_BUFFER_VIEW indexBufferView;
    UINT indexCount;
};

struct Vertex
{
    XMFLOAT3 Position;
    XMFLOAT4 Color;
};



