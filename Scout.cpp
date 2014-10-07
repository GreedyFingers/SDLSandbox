#include "Scout.h"


Scout::Scout(SDL_Renderer* renderer,int x, int y)
{
	_sx = _textureSizeX;
	_sy = _textureSizeY;
	init(renderer, x, y, GameObject::player, _texturePath,_spritestart,0);
}


Scout::~Scout()
{
}
