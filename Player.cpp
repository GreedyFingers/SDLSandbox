#include "Player.h"


Player::Player(float x, float y, SDL_Surface* screen)
{
	init(x, y, _textureSizeX, _textureSizeY, GameObject::player, _texturePath, screen,0,0);
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