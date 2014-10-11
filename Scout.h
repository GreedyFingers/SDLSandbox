#pragma once
#include "Automaton.h"
class Scout : public Automaton
{
	const char* TEXTURE_PATH = "charizard.bmp";
	const int TEXTURE_SIZE_X = 32;
	const int TEXTURE_SIZE_Y = 30;
	const int SPRITE_COUNT = 8;

	float _vx;
	float _vy;
	float _speed = 10.0f;
	unsigned int _nextActionTime; //ms
	int _movementCooldown = 1000; //ms

	static enum State { waiting, moving };

	State _currentState;

public:
	Scout(SDL_Renderer* renderer,int, int);
	~Scout();
	void chooseRandomDirection();
	void update();
};

