#pragma once
#include "stdafx.h"
#include "Renderer.h"

namespace Util
{

	Renderer::Renderer()
	{

	}

	Renderer::~Renderer()
	{
		SDL_DestroyRenderer(_SDLRenderer);
		_SDLRenderer = NULL;
	}

	bool Renderer::initRenderer(Util::Window* window, Uint32 flags)
	{

		_SDLRenderer = SDL_CreateRenderer(window->getSDLWindow(), -1, flags);

		int rw, rh;
		getRendererSize(&rw, &rh);
		_rwNormalized = rw / 800.0f;
		_rhNormalized = rh / 600.0f;

		//Create renderer for window
		if (_SDLRenderer == NULL)
		{
			printf("Renderer could not be created. SDL Error: %s\n", SDL_GetError());
			return false;
		}

		//Initialize PNG loading
		int imgFlags = IMG_INIT_PNG;
		if (!(IMG_Init(imgFlags) & imgFlags))
		{
			printf("SDL_image could not initialize. SDL_image Error: %s\n", IMG_GetError());
			return false;
		}

		//Init video
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			printf("SDL could not initialize. SDL_Error: %s\n", SDL_GetError());
			return false;
		}


		//SDL_CreateRenderer succeeded
	}

	SDL_Texture* Renderer::loadTexture(std::string fileName)
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
			newTexture = SDL_CreateTextureFromSurface(_SDLRenderer, loadedSurface);
			if (newTexture == NULL)
				printf("Unable to create texture from %s. SDL Error: %s\n", fileName.c_str(), SDL_GetError());
			else
				SDL_SetTextureBlendMode(newTexture, SDL_BLENDMODE_BLEND);
			SDL_FreeSurface(loadedSurface);
		}
		return newTexture;
	}

	bool Renderer::draw(SDL_Texture *texture, int rendX, int rendY, SDL_Rect* clip)
	{
		if (texture == NULL || _SDLRenderer == NULL)
			return false;
		SDL_Rect rendR;
		rendR.x = (int)(rendX*_rwNormalized);
		rendR.y = (int)(rendY*_rhNormalized);
		rendR.w = (int)((clip->w)*(_rwNormalized)); //to resize texture on screen, these values must be changed
		rendR.h = (int)((clip->h)*(_rhNormalized));
		SDL_RenderCopy(_SDLRenderer, texture, clip, &rendR);
		return true;
	}

	void Renderer::loadText(std::string textureText, SDL_Color textColor,
		int* sx, int* sy)
	{
		//TODO: change to use OpenGL fonts or something
	}

	bool Renderer::setTransparentColor(SDL_Surface *target, int R, int G, int B)
	{
		if (target == NULL)
			return false;
		SDL_SetColorKey(target, SDL_TRUE | SDL_RLEACCEL,
			SDL_MapRGB(target->format, R, G, B));
		return true;
	}

	void Renderer::getRendererSize(int* rw, int* rh)
	{
		SDL_GetRendererOutputSize(_SDLRenderer, rw, rh);
	}

	void Renderer::setRenderDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
	{
		//Set renderer color
		SDL_SetRenderDrawColor(_SDLRenderer, r, g, b, a);
	}

	void Renderer::renderClear()
	{
		SDL_RenderClear(_SDLRenderer);
	}

	void Renderer::renderPresent()
	{
		SDL_RenderPresent(_SDLRenderer);
	}

	float Renderer::getRWNormalized()
	{
		return _rwNormalized;
	}

	float Renderer::getRHNormalized()
	{
		return _rhNormalized;
	}

}