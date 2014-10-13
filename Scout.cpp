#include "Scout.h"
#include "Physics.h"

Scout::Scout(SDL_Renderer* renderer,int x, int y)
{
	_sx = Scout_Assets::TEXTURE_SIZE_X;
	_sy = Scout_Assets::TEXTURE_SIZE_Y;
	init(	renderer, 
			x, 
			y, 
			GameObject::Scout, 
			Scout_Assets::TEXTURE_PATH,
			Scout_Assets::SPRITE_COUNT,
			Scout_Assets::ANIMATION_COUNT
		);

	_texture->getAnimations()[Scout_Assets::ANIMATIONS::NONE].init(Scout_Assets::NO_ANIMATION,
		sizeof(Scout_Assets::NO_ANIMATION));
	_texture->getAnimations()[Scout_Assets::ANIMATIONS::MOVING].init(Scout_Assets::MOVING_ANIMATION,
		sizeof(Scout_Assets::MOVING_ANIMATION));

	_nextActionTime = SDL_GetTicks() + _movementCooldown;

	_currentState = State::waiting;

}

Scout::~Scout()
{
}

//update override
void Scout::update()
{
	//log time since last update
	__super::update();

	switch (_currentState)
	{
		case State::waiting :
			if (SDL_GetTicks() >= _nextActionTime)
			{
				Physics::ChooseRandomDirection(&_vx, &_vy);
				_currentDirection = Physics::DetermineDirection(_vx, _vy);
				_nextActionTime += 500;
				_texture->setCurrentAnimationIndex(Scout_Assets::ANIMATIONS::MOVING);
				_currentState = State::moving;
			}
			break;
		case State::moving :
			if (SDL_GetTicks() >= _nextActionTime)
			{
				_nextActionTime += 1000;
				_currentState = State::waiting;
				_vx = 0;
				_vy = 0;
				_texture->setCurrentAnimationIndex(Scout_Assets::ANIMATIONS::NONE);
			}
			else
			{
				_x += (int)(_speed * _vx * ((float)_clock.getTimeSinceLastUpdate() / _damping));
				_y += (int)(_speed * _vy * ((float)_clock.getTimeSinceLastUpdate() / _damping));
			}
			break;
	}
}

void Scout::render(SDL_Renderer* renderer)
{
	__super::render(renderer);
}