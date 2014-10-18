#pragma once
#include "Character.h"


Character::Character()
{
}


Character::~Character()
{
}

void Character::init(int x, int y, ObjectID type,
	std::string texturePath, int spriteCount, int animationCount)
{
	__super::init(x, y, type,spriteCount);
	_sprite = new Sprite(texturePath, animationCount);
}

void Character::render()
{
		_currentClip = _clips[_currentDirection];
		_currentClipIndex = _currentDirection;
		_clock.setTimeSinceLastDraw(SDL_GetTicks());
		if (_sprite->render(_x, _y, _clips, _currentClipIndex, _clock.getTimeSinceLastDraw()))
			_remove = true;
}