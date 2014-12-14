#pragma once
#include "Character.h"
#include "GameObject.h"

class Physics
{
public:
	Physics();
	~Physics();

	static void ChooseRandomDirection(float* vx, float* vy);
	static Character::Direction DetermineDirection(float vx, float vy);
	static bool checkCollision(GameObject* object1, GameObject* object2);
	static bool checkCollision(GameObject* object, int x, int y);
};
