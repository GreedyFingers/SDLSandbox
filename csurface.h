#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <string>

class CSurface
{
public:
	static SDL_Surface* onLoad(std::string fileName);
	static bool onDraw(SDL_Surface* src, SDL_Surface *dest, int destX,
						int destY);
	static bool onDraw(SDL_Surface* src, SDL_Surface *dest, int destX,
						int destY, int srcX, int srcY, int width, int height);
	static bool setTrasnparentColor(SDL_Surface *target, int R, int G, int B);
};