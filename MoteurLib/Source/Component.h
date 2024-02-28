#pragma once

class GameObject;

class Component
{
public:
	Component();
	virtual ~Component();

	virtual int Update() { return 0; };

protected:

	GameObject* ownGameObject;

};