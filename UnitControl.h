#pragma once
#include "GameObject.h"

class UnitControl :
	public GameObject
{
private:
	const int UNIT_CONTROL_DOCK_X = 0;
	const int UNIT_CONTROL_DOCK_Y = 0;
	const float UNIT_CONTROL_DOCK_W = 0.1f;
	const float UNIT_CONTROL_DOCK_H = 1.0f;
	const char* TEXTURE_PATH = "unitcontrol.png";
	const int SPRITE_COUNT = 1;
	const int ANIMATION_COUNT = 1;
	static const int NO_ANIMATION[1];

	enum ANIMATIONS
	{
		NONE = 0
	};

public:
	UnitControl(SDL_Renderer* renderer,int rw, int rh);
	~UnitControl();
	void input();
	void update();
};

