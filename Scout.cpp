#include "Scout.h"


Scout::Scout(float x, float y, SDL_Renderer* screen)
{
	init(x, y, _textureSizeX, _textureSizeY, GameObject::player, _texturePath, screen,_spritestart,0);
}


Scout::~Scout()
{
}
