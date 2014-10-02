#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <string>

class Draw
{
public:
	static SDL_Texture* loadTexture(SDL_Renderer* renderer, std::string fileName);
	static bool draw(SDL_Renderer *dest, SDL_Texture* src, int destX,
						int destY);
	static bool draw(SDL_Renderer *dest, SDL_Texture* src, float destX,
						float destY, int srcX, int srcY, int width, int height);
	static bool setTransparentColor(SDL_Surface *target, int R, int G, int B);
};