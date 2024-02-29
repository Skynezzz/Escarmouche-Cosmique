#include "Mesh.h"
#include "pch.h"

Mesh::Mesh(ID3D12Device* device, ID3D12GraphicsCommandList* commandList, const void* vertices, UINT vertexCount, UINT vertexStride, const void* indices, UINT indexCount) : indexCount(indexCount) {
    // Création du buffer de vertex
    UINT vertexBufferSize = vertexCount * vertexStride;
    D3D12_HEAP_PROPERTIES heapProps = CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_UPLOAD);
    D3D12_RESOURCE_DESC bufferDesc = CD3DX12_RESOURCE_DESC::Buffer(vertexBufferSize);
    device->CreateCommittedResource(
        &heapProps,
        D3D12_HEAP_FLAG_NONE,
        &bufferDesc,
        D3D12_RESOURCE_STATE_GENERIC_READ,
        nullptr,
        IID_PPV_ARGS(&vertexBuffer)
    );

    // Copie des données de vertex dans le buffer
    UINT8* pVertexDataBegin;
    CD3DX12_RANGE readRange(0, 0); // On ne lit pas la mémoire avant d'écrire
    vertexBuffer->Map(0, &readRange, reinterpret_cast< void** >(&pVertexDataBegin));
    memcpy(pVertexDataBegin, vertices, vertexBufferSize);
    vertexBuffer->Unmap(0, nullptr);

    // Création de la vue sur le buffer de vertex
    vertexBufferView.BufferLocation = vertexBuffer->GetGPUVirtualAddress();
    vertexBufferView.StrideInBytes = vertexStride;
    vertexBufferView.SizeInBytes = vertexBufferSize;

    // Création du buffer d'indices (similaire au buffer de vertex)
    UINT indexBufferSize = indexCount * sizeof(UINT16);
    bufferDesc = CD3DX12_RESOURCE_DESC::Buffer(indexBufferSize);
    device->CreateCommittedResource(
        &heapProps,
        D3D12_HEAP_FLAG_NONE,
        &bufferDesc,
        D3D12_RESOURCE_STATE_GENERIC_READ,
        nullptr,
        IID_PPV_ARGS(&indexBuffer)
    );

    UINT8* pIndexDataBegin;
    indexBuffer->Map(0, &readRange, reinterpret_cast< void** >(&pIndexDataBegin));
    memcpy(pIndexDataBegin, indices, indexBufferSize);
    indexBuffer->Unmap(0, nullptr);

    // Création de la vue sur le buffer d'indices
    indexBufferView.BufferLocation = indexBuffer->GetGPUVirtualAddress();
    indexBufferView.Format = DXGI_FORMAT_R16_UINT;
    indexBufferView.SizeInBytes = indexBufferSize;
}

Mesh::~Mesh() {}
