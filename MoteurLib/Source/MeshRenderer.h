#pragma once
#include "Component.h"

#include "Mesh.h"
#include "Texture.h"
#include "Shader.h"


class MeshRenderer : public Component
{
public:
	MeshRenderer();
	~MeshRenderer() override;

	int Update(float deltaTime) override;

private:
	Mesh* mesh;
	Texture* texture;
	Shader* shader;
};