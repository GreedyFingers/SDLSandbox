#include "Character.h"


Character::Character()
{
}


Character::~Character()
{
}

void Character::render(SDL_Renderer* renderer)
{
		_currentClip = _clips[_currentDirection];
		_currentClipIndex = _currentDirection;
		__super::render(renderer);
}