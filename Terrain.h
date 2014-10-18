#pragma once
#include "GameObject.h"
#include "Terrain_Assets.h"

class Terrain : public GameObject
{
	Texture _texture;
public:
	Terrain(int x, int y);
	~Terrain();
	void render();
};

