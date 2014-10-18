#pragma once
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include "Clock.h"
#include "Animation.h"

class Texture
{

protected:
	SDL_Texture* _texture;


public:

	Texture();
	~Texture();
	bool render(int x, int y, SDL_Rect* clip, int clipIndex = 0);
	void setAlpha(Uint8 alpha);
	void setTexture(SDL_Texture* texture);
};

