#pragma once

#include <string>
#include "GameObject.h"
#include "Player_Assets.h"
#include "Character.h"

class Player : public Character
{

public:
	Player(SDL_Renderer* renderer,int, int);
	~Player();

};

