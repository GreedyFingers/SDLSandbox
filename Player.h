#pragma once

#include <string>
#include "GameObject.h"

class Player : public GameObject
{
	const char* _texturePath = "bulbasaur.bmp";
	const int _textureSizeX = 32;
	const int _textureSizeY = 30;
public:
	Player(SDL_Renderer* renderer,int, int);
	~Player();

};

