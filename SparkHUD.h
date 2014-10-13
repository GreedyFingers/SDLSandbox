#pragma once
#include "GameObject.h"
#include "SparkHUD_Assets.h"

class SparkHUD : public GameObject
{

public:
	SparkHUD(SDL_Renderer* renderer, int x, int y);
	~SparkHUD();
};

