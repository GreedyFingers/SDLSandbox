#pragma once
#include "GameObject.h"
#include "Terrain_Assets.h"

class Terrain : public GameObject
{
	Texture _texture;
public:
	Terrain(SDL_Renderer* renderer, int x, int y);
	~Terrain();
	void render(SDL_Renderer* renderer);
};

