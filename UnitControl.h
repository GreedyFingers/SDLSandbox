#pragma once
#include "GameObject.h"

class UnitControl :
	public GameObject
{
private:
	const int UNIT_CONTROL_DOCK_X = 0;
	const int UNIT_CONTROL_DOCK_Y = 0;
	const float UNIT_CONTROL_DOCK_W = 0.1f;
	const float UNIT_CONTROL_DOCK_H = 0.5f;
	static SDL_Color UNIT_CONTROL_DOCK_COLOR;

	SDL_Rect unitControlViewPort;

public:
	UnitControl(SDL_Renderer* renderer, int rw, int rh);
	~UnitControl();
	void input();
	void update();
	void render();
};

