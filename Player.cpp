#include "Player.h"


Player::Player(int x, int y, SDL_Renderer* renderer)
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