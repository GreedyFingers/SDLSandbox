#include "Player.h"


Player::Player(float x, float y, SDL_Renderer* renderer)
{
	init(x, y, _textureSizeX, _textureSizeY, GameObject::player, _texturePath, renderer, 0, 0);
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