#pragma once

#include <string>
#include "GameObject.h"
#include "Player_Assets.h"

class Player : public GameObject
{

public:
	Player(SDL_Renderer* renderer,int, int);
	~Player();

};

