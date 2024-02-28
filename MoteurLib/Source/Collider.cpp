#include "Collider.h"
#include <cmath>

Collider::Collider()
{
}

Collider::~Collider()
{
}

// Fonction de test de collision de boîte englobante
bool Collider::IsCollisionBox(const BoundingBox& box1, const BoundingBox& box2)
{
    // Teste si les boîtes se chevauchent sur l'axe x
    bool overlapX = (box1.min.x <= box2.max.x) && (box1.max.x >= box2.min.x);

    // Teste si les boîtes se chevauchent sur l'axe y
    bool overlapY = (box1.min.y <= box2.max.y) && (box1.max.y >= box2.min.y);

    // Teste si les boîtes se chevauchent sur l'axe z
    bool overlapZ = (box1.min.z <= box2.max.z) && (box1.max.z >= box2.min.z);

    // Si les boîtes se chevauchent sur tous les axes, il y a une collision
    return overlapX && overlapY && overlapZ;

}

// Fonction de test de collision de sphère englobande
bool Collider::IsCollisionSphere(const BoundingSphere& sphere1, const BoundingSphere& sphere2)
{
    // Calcul de la distance entre les centres des deux sphères
    float distance = sqrt(pow(sphere1.center.x - sphere2.center.x, 2) +
        pow(sphere1.center.y - sphere2.center.y, 2) +
        pow(sphere1.center.z - sphere2.center.z, 2));

    // Si la distance est inférieure à la somme des rayons, il y a une collision
    return distance < (sphere1.radius + sphere2.radius);
}