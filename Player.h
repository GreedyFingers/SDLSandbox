#pragma once

#include <string>
#include "GameObject.h"

class Player : public GameObject
{
	const char* TEXTURE_PATH = "bulbasaur.bmp";
	const int TEXTURE_SIZE_X = 32;
	const int TEXTURE_SIZE_Y = 30;
	const int SPRITE_COUNT = 8;
	const int ANIMATION_COUNT = 1;
	static const int NO_ANIMATION[1];

	enum ANIMATIONS
	{
		NONE = 0
	};

public:
	Player(SDL_Renderer* renderer,int, int);
	~Player();

};

