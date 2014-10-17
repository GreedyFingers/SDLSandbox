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

//TODO: add render method for animationless textures (like menus)