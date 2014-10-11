#pragma once
#include "GameObject.h"

class Character : public GameObject
{
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

