#include "Player.h"


Player::Player(SDL_Renderer* renderer,int x, int y)
{
	_sx = TEXTURE_SIZE_X;
	_sy = TEXTURE_SIZE_Y;
	init(renderer, x, y, GameObject::player, TEXTURE_PATH, SPRITE_COUNT);
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