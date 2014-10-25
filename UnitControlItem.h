#pragma once
#include "GameObject.h"

class UnitControlItem : public GameObject
{
	Texture _texture;
public:
	UnitControlItem(int UnitControlX, int UnitControlY, 
					int UnitControlSizeX, int positionInContainer);
	~UnitControlItem();

	void render();
};

