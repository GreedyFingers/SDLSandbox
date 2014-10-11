#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <string>

class Draw
{
public:
	static SDL_Texture* loadTexture(SDL_Renderer* renderer, std::string fileName);
	static bool draw(SDL_Renderer *renderer, SDL_Texture* texture, int rendX,
						int rendY, SDL_Rect* clip);
	static bool setTransparentColor(SDL_Surface *target, int R, int G, int B);
};