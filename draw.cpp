#pragma once
#include "draw.h"

SDL_Texture* Draw::loadTexture(SDL_Renderer* renderer, std::string fileName)
{
	//the final texture
	SDL_Texture *newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(fileName.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s. SDL_Error: %s\n\n", fileName.c_str(), SDL_GetError());
	}
	else
	{
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (newTexture == NULL)
			printf("Unable to create texture from %s. SDL Error: %s\n", fileName.c_str(), SDL_GetError());
		SDL_FreeSurface(loadedSurface);
	}
	return newTexture;
}

bool Draw::draw(SDL_Renderer *renderer, SDL_Texture *texture, int rendX, int rendY,
						int texX, int texY, int width, int height)
{
	if (texture == NULL || renderer == NULL)
		return false;
	SDL_Rect rendR;
	rendR.x = rendX;
	rendR.y = rendY;
	rendR.w = width;
	rendR.h = height;
	SDL_Rect texR;
	texR.x = texX;
	texR.y = texY;
	texR.w = width;
	texR.h = height;
	SDL_RenderCopy(renderer, texture, &texR, &rendR);
	return true;
}

bool Draw::setTransparentColor(SDL_Surface *target, int R, int G, int B)
{
	if (target == NULL)
		return false;
	SDL_SetColorKey(target, SDL_TRUE | SDL_RLEACCEL,
		SDL_MapRGB(target->format, R, G, B));
	return true;
}

void Draw::drawRect(SDL_Renderer* renderer, int x, int y, int rw, int rh,
						Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	SDL_Rect fillRect = { x, y, rw, rh };
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
	SDL_RenderFillRect(renderer, &fillRect);
}