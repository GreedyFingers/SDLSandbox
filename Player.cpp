#include "Player.h"


Player::Player(SDL_Renderer* renderer,int x, int y)
{
	_sx = _textureSizeX;
	_sy = _textureSizeY;
	init(renderer, x, y,GameObject::player, _texturePath, 0, 0);
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