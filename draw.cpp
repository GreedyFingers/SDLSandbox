#pragma once
#include "draw.h"
#include "Global_Assets.h"

SDL_Renderer* Draw::_renderer;
static float _rwNormalized;
static float _rhNormalized;

void Draw::initRenderer(SDL_Window* window, Uint32 flags)
{
	_renderer = SDL_CreateRenderer(window, -1, flags);
	int rw, rh;
	Draw::getRendererSize(&rw, &rh);
	_rwNormalized = rw / 800.0f;
	_rhNormalized = rh / 600.0f;
	//Create renderer for window
	if (_renderer == NULL)
	{
		printf("Renderer could not be created. SDL Error: %s\n", SDL_GetError());
		//TODO: return false or something
	}
	//SDL_CreateRenderer succeeded
}

SDL_Texture* Draw::loadTexture(std::string fileName)
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
		newTexture = SDL_CreateTextureFromSurface(_renderer, loadedSurface);
		if (newTexture == NULL)
			printf("Unable to create texture from %s. SDL Error: %s\n", fileName.c_str(), SDL_GetError());
		else
			SDL_SetTextureBlendMode(newTexture,SDL_BLENDMODE_BLEND);
		SDL_FreeSurface(loadedSurface);
	}
	return newTexture;
}

bool Draw::draw(SDL_Texture *texture, int rendX, int rendY, SDL_Rect* clip)
{
	if (texture == NULL || _renderer == NULL)
		return false;
	SDL_Rect rendR;
	rendR.x = (int)(rendX*_rwNormalized);
	rendR.y = (int)(rendY*_rhNormalized);
	rendR.w = (int)(clip->w)*(_rwNormalized); //to resize texture on screen, these values must be changed
	rendR.h = (int)(clip->h)*(_rhNormalized);
	SDL_RenderCopy(_renderer, texture, clip, &rendR);
	return true;
}

void Draw::loadText(std::string textureText, SDL_Color textColor,
					int* sx, int* sy)
{
	//TODO: change to use OpenGL fonts or something
}

bool Draw::setTransparentColor(SDL_Surface *target, int R, int G, int B)
{
	if (target == NULL)
		return false;
	SDL_SetColorKey(target, SDL_TRUE | SDL_RLEACCEL,
		SDL_MapRGB(target->format, R, G, B));
	return true;
}

void Draw::getRendererSize(int* rw, int* rh)
{
	SDL_GetRendererOutputSize(_renderer,rw, rh);
}

void Draw::setRenderDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	//Set renderer color
	SDL_SetRenderDrawColor(_renderer, r, g, b, a);
}

void Draw::renderClear()
{
	SDL_RenderClear(_renderer);
}

void Draw::renderPresent()
{
	SDL_RenderPresent(_renderer);
}

float Draw::getRWNormalized()
{
	return _rwNormalized;
}

float Draw::getRHNormalized()
{
	return _rhNormalized;
}