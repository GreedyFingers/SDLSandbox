#pragma once
#include <string>
#include <SDL.h>
#include <string>
#include "Clock.h"
#include "Animation.h"

class Texture
{

protected:
	SDL_Texture* _texture;
	int _spriteCount;
	SDL_Rect* _clips;

public:

	Texture();
	~Texture();
	bool render(int x, int y, int clipIndex);
	void setAlpha(Uint8 alpha);
	void setTexture(SDL_Texture* texture, int spriteCount, int sx, int sy);
	void initClips(int sx, int sy);
};

