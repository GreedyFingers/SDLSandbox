#include "Player.h"


Player::Player(SDL_Renderer* renderer,int x, int y)
{
	_sx = _textureSizeX;
	_sy = _textureSizeY;
	init(renderer, x, y,GameObject::player, _texturePath, 0, 0);

	_currentClip.x = 0;
	_currentClip.y = 0;
	_currentClip.w = _sx;
	_currentClip.h = _sy;
}


Player::~Player()
{

}

void update()
{

}

void input()
{

}