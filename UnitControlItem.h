#pragma once
#include "GameObject.h"

class UnitControlItem : public GameObject
{
	Texture _texture;

protected:
	Texture _itemTexture;
	int _currentItemTextureClip;

public:
	UnitControlItem(int UnitControlX, int UnitControlY,
					int UnitControlSizeX, int positionInContainer);
	UnitControlItem();
	~UnitControlItem();

	void init(int UnitControlX, int UnitControlY,
				int UnitControlSizeX, int positionInContainer);
	void render();
};

