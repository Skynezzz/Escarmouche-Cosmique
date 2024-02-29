#pragma once

class GameObject;

class Component
{
public:
	Component();
	virtual ~Component();

	virtual int Update(float deltaTime) { return 0; };

protected:

	GameObject* ownGameObject;

};