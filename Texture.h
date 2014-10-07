#pragma once
#include <string>
#include <SDL.h>
class Texture
{
	SDL_Texture* _texture;

public:
	Texture(SDL_Renderer* renderer,std::string texturePath);
	~Texture();
	bool render(SDL_Renderer* renderer,int x, int y, int sx, int sy, int spritestart);

};

