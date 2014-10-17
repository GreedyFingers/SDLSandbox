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
	SDL_DestroyTexture(_texture);
	_texture = NULL;
}

//Set transparency of texture
void Texture::setAlpha(Uint8 alpha)
{
	SDL_SetTextureAlphaMod(_texture, alpha);
}

bool Texture::render(SDL_Renderer* renderer, int x, int y, SDL_Rect* clip, int clipIndex)
{
	if (Draw::draw(renderer, _texture, x, y, &clip[clipIndex]) == false)
		return true;
	else
		return false;
}

void Texture::init(SDL_Renderer* renderer, std::string texturePath)
{
	_texture = Draw::loadTexture(renderer, texturePath);
}