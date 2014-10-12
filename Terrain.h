#pragma once
#include "GameObject.h"
#include "Terrain_Assets.h"

class Terrain : public GameObject
{

public:
	Terrain(SDL_Renderer* renderer, int x, int y);
	~Terrain();
};

