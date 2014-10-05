#pragma once
#include "Automotan.h"
class Scout : public Automotan
{
	const char* _texturePath = "charizard.bmp";
	const int _textureSizeX = 32;
	const int _textureSizeY = 30;
	const int _spritestart = 64;
public:
	Scout(int, int, SDL_Renderer*);
	~Scout();
};

