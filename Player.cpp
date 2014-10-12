#include "Player.h"

const int Player::NO_ANIMATION[1] = { 0 };

Player::Player(SDL_Renderer* renderer,int x, int y)
{
	_sx = TEXTURE_SIZE_X;
	_sy = TEXTURE_SIZE_Y;
	init(renderer, x, y, GameObject::player, TEXTURE_PATH, SPRITE_COUNT, ANIMATION_COUNT);
	_animations[ANIMATIONS::NONE].init(NO_ANIMATION,sizeof(NO_ANIMATION));
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