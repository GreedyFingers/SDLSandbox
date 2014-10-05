#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <string>

class Draw
{
public:
	static SDL_Texture* loadTexture(SDL_Renderer* renderer, std::string fileName);
	static bool draw(SDL_Renderer *renderer, SDL_Texture* texture, int rendX,
						int rendY);
	static bool draw(SDL_Renderer *renderer, SDL_Texture* texture, int rendX,
						int rendY, int textX, int texY, int width, int height);
	static bool setTransparentColor(SDL_Surface *target, int R, int G, int B);
	static void drawRect(SDL_Renderer* renderer, int x, int y, int rw, int rh,
		Uint8 r, Uint8 g, Uint8 b, Uint8 a);
};