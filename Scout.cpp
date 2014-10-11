#include "Scout.h"
#include "Physics.h"


Scout::Scout(SDL_Renderer* renderer,int x, int y)
{
	_sx = TEXTURE_SIZE_X;
	_sy = TEXTURE_SIZE_Y;
	init(renderer, x, y, GameObject::player, TEXTURE_PATH, SPRITE_COUNT);
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
			}
			else
			{
				_x += (int)(_speed * _vx * ((float)_timeSinceLastUpdate / _damping));
				_y += (int)(_speed * _vy * ((float)_timeSinceLastUpdate / _damping));
			}
			break;
	}
}