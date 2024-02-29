#pragma once
#include "Component.h"

class Mesh;
class Texture;
class Shader;


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