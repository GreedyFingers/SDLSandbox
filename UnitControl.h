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
	
	std::vector<UnitControlItem*> _controlItems;
public:
	UnitControl(int x, int y);
	~UnitControl();
	GameObject::ObjectID select(int x, int y);
	void update();
	void render();
};

