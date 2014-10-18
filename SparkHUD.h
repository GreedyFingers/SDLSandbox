#pragma once
#include "GameObject.h"
#include "SparkHUD_Assets.h"
#include "Text.h"

class SparkHUD : public GameObject
{
	Texture _texture;
	Text _textBox;
public:
	SparkHUD(int x, int y);
	~SparkHUD();
	void render();
};

