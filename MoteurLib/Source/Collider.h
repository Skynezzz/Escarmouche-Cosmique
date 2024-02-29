#pragma once
#include "Component.h"

#include <vector>

// Structure repr�sentant une bo�te englobante
struct BoundingBox
{
	XMFLOAT3 min; // Coin inf�rieur de la bo�te
	XMFLOAT3 max; // Coin sup�rieur de la bo�te
};

// Structure repr�sentant une sph�re englobante
struct BoundingSphere {
	XMFLOAT3 center; // Centre de la sph�re
	float radius;    // Rayon de la sph�re
};

// Structure repr�sentant un maillage de triangle
struct Triangle {
	XMFLOAT3 v0;
	XMFLOAT3 v1;
	XMFLOAT3 v2;
};

class Collider : public Component
{
public:
	Collider();
	~Collider() override;

	int Update(float deltaTime) override;

private:

	bool IsCollisionBox(const BoundingBox&, const BoundingBox&);
	bool IsCollisionSphere(const BoundingSphere&, const BoundingSphere&);

};