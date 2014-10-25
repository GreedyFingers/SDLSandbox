#pragma once
#include <vector>
#include "GameObject.h"
#include "UnitControl_Assets.h"
#include "Texture.h"
#include "UnitControlItem.h"

class UnitControl :
	public GameObject
{
	Texture _texture;
	
	std::vector<UnitControlItem> _controlItems;
public:
	UnitControl(int x, int y);
	~UnitControl();
	void input();
	void update();
	void render();
};

