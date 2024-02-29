#pragma once
#include "Component.h"

#include <vector>

// Structure représentant une boîte englobante
struct BoundingBox
{
	XMFLOAT3 min; // Coin inférieur de la boîte
	XMFLOAT3 max; // Coin supérieur de la boîte
};

// Structure représentant une sphère englobante
struct BoundingSphere {
	XMFLOAT3 center; // Centre de la sphère
	float radius;    // Rayon de la sphère
};

// Structure représentant un maillage de triangle
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