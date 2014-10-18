#pragma once
#include "GameObject.h"
#include "UnitControl_Assets.h"
#include "Texture.h"

class UnitControl :
	public GameObject
{
	Texture _texture;
public:
	UnitControl(int x, int y);
	~UnitControl();
	void input();
	void update();
	void render();
};

