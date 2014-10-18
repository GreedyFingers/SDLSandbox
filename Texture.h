#pragma once
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include "Clock.h"
#include "Animation.h"

//TODO: BREAK UP THIS CLASS INTO Image -> Texture and Image -> Text
class Texture
{

protected:
	SDL_Texture* _texture;


public:

	Texture();
	~Texture();
	void init(std::string texturePath);
	bool render(int x, int y, SDL_Rect* clip, int clipIndex);
	void setAlpha(Uint8 alpha);
};

