#include "Scout.h"
#include "Physics.h"


Scout::Scout(SDL_Renderer* renderer,int x, int y)
{
	_sx = _textureSizeX;
	_sy = _textureSizeY;
	init(renderer, x, y, GameObject::player, _texturePath,_spritestart,0);
	_nextActionTime = SDL_GetTicks() + _movementCooldown;

	_currentState = State::waiting;

	_currentClip.x = 0;
	_currentClip.y = 0;
	_currentClip.w = _sx;
	_currentClip.h = _sy;
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
				_nextActionTime += 500;
				_currentState = State::moving;
			}
			break;
		case State::moving :
			if (SDL_GetTicks() >= _nextActionTime)
			{
				_nextActionTime += 1000;
				_currentState = State::waiting;
			}
			else
			{
				_x += (int)(_speed * _vx * ((float)_timeSinceLastUpdate / _damping));
				_y += (int)(_speed * _vy * ((float)_timeSinceLastUpdate / _damping));
			}
			break;
	}
}