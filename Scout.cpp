#include "Scout.h"
#include "Physics.h"

const int Scout::NO_ANIMATION[1] = { 0 };
const int Scout::MOVING_ANIMATION[2] = { 50, 50 };

Scout::Scout(SDL_Renderer* renderer,int x, int y)
{
	_sx = TEXTURE_SIZE_X;
	_sy = TEXTURE_SIZE_Y;
	init(renderer, x, y, GameObject::player, TEXTURE_PATH, SPRITE_COUNT,ANIMATION_COUNT);

	_animations[ANIMATIONS::NONE].init(NO_ANIMATION, sizeof(NO_ANIMATION));
	_animations[ANIMATIONS::MOVING].init(MOVING_ANIMATION, sizeof(MOVING_ANIMATION));

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
				_currentAnimation = _animations[ANIMATIONS::MOVING];
				_currentAnimation.beginAnimation();
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
				_currentAnimation = _animations[ANIMATIONS::NONE];
				_currentAnimation.beginAnimation();
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