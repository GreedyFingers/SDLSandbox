#pragma once
#include "GameObject.h"

//Any moving unit on the screen, including the player
class Character : public GameObject
{
	//Out of range frame indicator
	const int INVALID_FRAME = -1;

public:

	//Offset in sprite batch of various directions
	enum Direction {
		Up = 0,
		Down = 2,
		Left = 4,
		Right = 6
	};

	Character();
	~Character();

	//overrides GameObject::render()
	void render();

	//overrides GameObject::init()
	void init(int x, int y, ObjectID type, std::string texturePath, 
				int spriteCount, int animationCount);

protected:
	Direction _currentDirection = Direction::Up;
	Sprite* _sprite;

};

