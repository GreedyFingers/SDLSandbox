#pragma once
#include "Character.h"

class Physics
{
public:
	Physics();
	~Physics();

	static void ChooseRandomDirection(float* vx, float* vy);
	static Character::Direction DetermineDirection(float vx, float vy);
};
