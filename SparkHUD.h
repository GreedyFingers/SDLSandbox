#pragma once
#include "GameObject.h"
#include "SparkHUD_Assets.h"

class SparkHUD : public GameObject
{
	Texture _texture;
public:
	SparkHUD(int x, int y);
	~SparkHUD();
	void render();
};

