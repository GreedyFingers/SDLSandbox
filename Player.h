#pragma once

#include <string>
#include "GameObject.h"
#include "Player_Assets.h"
#include "Character.h"

class Player : public Character
{

public:
	Player(int x, int y);
	~Player();

};

