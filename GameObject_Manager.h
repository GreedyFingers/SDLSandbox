#pragma once
#include <vector>
#include "GameObject.h"
class GameObject_Manager
{
	//All game objects to loop through
	std::vector<GameObject*> _objects;
public:

	GameObject_Manager();
	~GameObject_Manager();

	void selectObject(int x, int y);
	void update();
	void render();

	void createObject(GameObject::ObjectID type, int x, int y);
	void execute(GameObject::ObjectID type);
};

