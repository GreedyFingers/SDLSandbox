#include "Scout.h"


Scout::Scout(float x, float y, SDL_Surface* screen)
{
	init(x, y, _textureSizeX, _textureSizeY, GameObject::player, _texturePath, screen,_spritestart,0);
}


Scout::~Scout()
{
}
