#pragma once
#include "GameObject.h"

class Character : public GameObject
{
	const int INVALID_FRAME = -1;

public:

	enum Direction {
		Up = 0,
		Down = 2,
		Left = 4,
		Right = 6
	};

	Character();
	~Character();

	void render(SDL_Renderer* renderer);

protected:
	Direction _currentDirection = Direction::Up;

};

