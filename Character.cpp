#pragma once
#include "Character.h"


Character::Character()
{
}


Character::~Character()
{
}

//Initialize the sprite batch and animations
void Character::init(int x, int y, ObjectID type, std::string texturePath, 
						int spriteCount, int animationCount, int sx, int sy)
{
	__super::init(x, y, type, sx, sy);
	_sprite = new Sprite(texturePath, animationCount, spriteCount, sx, sy);
}

//Render sprite clip based on the character's direction
void Character::render()
{
		_currentTextureClip = _currentDirection;
		_clock.setTimeSinceLastDraw(SDL_GetTicks());
		if (_sprite->render(_x, _y, _currentTextureClip, _clock.getTimeSinceLastDraw()))
			_remove = true;
}