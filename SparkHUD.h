#pragma once
#include "GameObject.h"
#include "SparkHUD_Assets.h"

class SparkHUD : public GameObject
{
	Texture _texture;
public:
	SparkHUD(SDL_Renderer* renderer, int x, int y);
	~SparkHUD();
	void render(SDL_Renderer* renderer);
};

