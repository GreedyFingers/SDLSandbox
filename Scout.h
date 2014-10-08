#pragma once
#include "Automaton.h"
class Scout : public Automaton
{
	const char* _texturePath = "charizard.bmp";
	const int _textureSizeX = 32;
	const int _textureSizeY = 30;
	const int _spritestart = 64;

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

