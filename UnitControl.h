#pragma once
#include "GameObject.h"
#include "UnitControl_Assets.h"

class UnitControl :
	public GameObject
{
private:

public:
	UnitControl(SDL_Renderer* renderer,int x, int y);
	~UnitControl();
	void input();
	void update();
};

