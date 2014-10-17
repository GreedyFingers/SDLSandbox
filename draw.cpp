#pragma once
#include "draw.h"
#include "Global_Assets.h"

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
		else
			SDL_SetTextureBlendMode(newTexture,SDL_BLENDMODE_BLEND);
		SDL_FreeSurface(loadedSurface);
	}
	return newTexture;
}

bool Draw::draw(SDL_Renderer *renderer, SDL_Texture *texture, int rendX, int rendY, SDL_Rect* clip)
{
	if (texture == NULL || renderer == NULL)
		return false;
	SDL_Rect rendR;
	rendR.x = rendX;
	rendR.y = rendY;
	rendR.w = clip->w;
	rendR.h = clip->h;
	SDL_RenderCopy(renderer, texture, clip, &rendR);
	return true;
}

bool Draw::loadText(SDL_Renderer* renderer, std::string textureText, SDL_Color textColor,
					SDL_Texture* texture, int* sx, int* sy)
{
	bool drawSucceeded = false;
	SDL_Surface* textureSurface = TTF_RenderText_Solid(Global_Assets::_font, textureText.c_str(), textColor);
	if (textureSurface == NULL)
	{
		printf("Unable to render text surface. SDL_ttf Error: %s\n", TTF_GetError());
		drawSucceeded = false;
	}
	else
	{
		//Create texture from surface
		texture = SDL_CreateTextureFromSurface(renderer, textureSurface);
		if (texture == NULL)
		{
			printf("Unable to create texture from rendererd text. SDL Error: %s\n", SDL_GetError());
			drawSucceeded = false;
		}
		else
		{
			*sx = textureSurface->w;
			*sy = textureSurface->h;
			drawSucceeded = true;
		}
	}

	return drawSucceeded;
}

bool Draw::setTransparentColor(SDL_Surface *target, int R, int G, int B)
{
	if (target == NULL)
		return false;
	SDL_SetColorKey(target, SDL_TRUE | SDL_RLEACCEL,
		SDL_MapRGB(target->format, R, G, B));
	return true;
}