#pragma once
#include "GameObject.h"

class UnitControlItem : public GameObject
{
	Texture _texture;
public:
	UnitControlItem();
	~UnitControlItem();

	void init(int x, int y, int size);
	void render();
};

