#pragma once
#include "Texture.h"
#include "Draw.h"
#include "Global_Assets.h"

//Create and initialize texture for current renderer
Texture::Texture()
{
}

//Destroy texture
Texture::~Texture()
{
	delete _clips;
	_clips = NULL;
	SDL_DestroyTexture(_texture);
	_texture = NULL;
}

//Set transparency of texture
void Texture::setAlpha(Uint8 alpha)
{
	SDL_SetTextureAlphaMod(_texture, alpha);
}

bool Texture::render(int x, int y, int clipIndex)
{
	if (Draw::draw(_texture, x, y, &_clips[clipIndex]) == false)
		return true;
	else
		return false;
}

void Texture::setTexture(SDL_Texture* texture, int spriteCount, int sx, int sy)
{
	_texture = texture;
	_spriteCount = spriteCount;
	initClips(sx, sy);
}

//Create clips for individual sprites within texture
void Texture::initClips(int sx, int sy)
{
	_clips = (SDL_Rect*)malloc(sizeof(SDL_Rect)*_spriteCount);
	if (_clips == NULL)
		printf("Error initializing clips for %texture");
	else
	{
		for (int i = 0; i < _spriteCount; i++)
		{
			//offset first sprite by sprite size per rectangle
			_clips[i].x = i * sx;
			_clips[i].y = 0;
			_clips[i].w = sx;
			_clips[i].h = sy;
		}
	}
}