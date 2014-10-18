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

	void render();
	void init(int x, int y, ObjectID type, std::string texturePath, 
				int spriteCount, int animationCount);

protected:
	Direction _currentDirection = Direction::Up;
	Sprite* _sprite;

};

