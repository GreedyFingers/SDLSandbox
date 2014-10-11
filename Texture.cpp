#include "Texture.h"
#include "Draw.h"

//Create and initialize texture for current renderer
Texture::Texture(SDL_Renderer* renderer,std::string texturePath)
{
	_texture = Draw::loadTexture(renderer,texturePath);
}

//Destroy texture
Texture::~Texture()
{
	SDL_DestroyTexture(_texture);
	_texture = NULL;
}

//Render a clip from the texture to screen
bool Texture::render(SDL_Renderer* renderer, int x, int y, SDL_Rect* clip)
{
	if (Draw::draw(renderer, _texture, x, y, clip) == false)
		return true;
}

//Set transparency of texture
void Texture::setAlpha(Uint8 alpha)
{
	SDL_SetTextureAlphaMod(_texture, alpha);
}
