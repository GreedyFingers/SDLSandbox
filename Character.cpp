#include "Character.h"


Character::Character()
{
}


Character::~Character()
{
}

void Character::init(SDL_Renderer* renderer, int x, int y, ObjectID type,
	std::string texturePath, int spriteCount, int animationCount)
{
	__super::init(renderer, x, y, type,spriteCount);
	_sprite = new Sprite(renderer, texturePath, animationCount);
}

void Character::render(SDL_Renderer* renderer)
{
		_currentClip = _clips[_currentDirection];
		_currentClipIndex = _currentDirection;
		_clock.setTimeSinceLastDraw(SDL_GetTicks());
		if (_sprite->render(renderer, _x, _y, _clips, _currentClipIndex, _clock.getTimeSinceLastDraw()))
			_remove = true;
}