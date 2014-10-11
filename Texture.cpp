#include "Texture.h"
#include "Draw.h"


Texture::Texture(SDL_Renderer* renderer,std::string texturePath)
{
	_texture = Draw::loadTexture(renderer,texturePath);
}


Texture::~Texture()
{
	SDL_DestroyTexture(_texture);
	_texture = NULL;
}

bool Texture::render(SDL_Renderer* renderer, int x, int y, SDL_Rect* clip)
{
	if (Draw::draw(renderer, _texture, x, y, clip) == false)
		return true;
}

void Texture::setAlpha(Uint8 alpha)
{
	SDL_SetTextureAlphaMod(_texture, alpha);
}
