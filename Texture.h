#pragma once
#include <string>
#include <SDL.h>
#include "Clock.h"
#include "Animation.h"

class Texture
{
	SDL_Texture* _texture;

public:

	Texture(SDL_Renderer* renderer,std::string texturePath);
	~Texture();
	bool render(SDL_Renderer* renderer,int x, int y, SDL_Rect* clip);
	void setAlpha(Uint8 alpha);
};

