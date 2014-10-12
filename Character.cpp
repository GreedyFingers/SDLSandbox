#include "Character.h"


Character::Character()
{
}


Character::~Character()
{
}

void Character::render(SDL_Renderer* renderer)
{
	int animationFrame = _currentAnimation.getCurrentFrame(_clock.getTimeSinceLastDraw());
	if (animationFrame == -1)
	{
		printf("Animation not fully loaded yet! %d\n",_clock.getTimeSinceLastDraw());
		_currentClip = _clips[_currentDirection];
		__super::render(renderer);
	}
	else
	{
		_currentClip = _clips[_currentDirection + animationFrame];
		__super::render(renderer);
	}

}