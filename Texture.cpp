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

bool Texture::render(SDL_Renderer* renderer, int x, int y, int sx, int sy, int spritestart)
{
	if (Draw::draw(renderer, _texture, x, y, spritestart, 0, sx, sy) == false)
		return true;
}
