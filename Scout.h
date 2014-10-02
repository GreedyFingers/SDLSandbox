#pragma once
#include "Enemy.h"
class Scout : public Enemy
{
	const char* _texturePath = "charizard.bmp";
	const int _textureSizeX = 32;
	const int _textureSizeY = 30;
	const int _spritestart = 64;
public:
	Scout(float, float, SDL_Renderer*);
	~Scout();
};

