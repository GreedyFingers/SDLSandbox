#pragma once
#include "UnitControlItem.h"
#include "Texture.h"

class Item_Scout : 
	public UnitControlItem
{

public:
	Item_Scout(int UnitControlX, int UnitControlY,
				int UnitControlSizeX, int positionInContainer);
	~Item_Scout();

	void render();
};

