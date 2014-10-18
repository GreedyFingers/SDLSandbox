#pragma once
#include "Automaton.h"
#include "Scout_Assets.h"

class Scout : public Automaton
{

	float _vx;
	float _vy;
	float _speed = 10.0f;
	unsigned int _nextActionTime; //ms
	int _movementCooldown = 1000; //ms

	static enum State { waiting, moving };

	State _currentState;

public:
	Scout(int, int);
	~Scout();
	void chooseRandomDirection();
	void update();
};

