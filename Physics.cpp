#pragma once
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Physics.h"
#include "Character.h"


Physics::Physics()
{
}


Physics::~Physics()
{
}

//Will always make character go maximum possible distance / speed
void Physics::ChooseRandomDirection(float* vx, float* vy)
{
	float tempX;
	float tempY;

	tempX = (rand() % 100) / 100.0f;
	tempY = sqrt(1 - pow(tempX, 2));
	
	//randomly choose negative or positive
	if ((rand() % 2) == 1)
		tempX = -tempX;

	if ((rand() % 2) == 1)
		tempY = -tempY;

	*vx = tempX;
	*vy = tempY;
}

Character::Direction Physics::DetermineDirection(float vx, float vy)
{
	bool _facingLeftOrRight = abs(vx) > abs(vy);

	if (abs(vx) > abs(vy))
		if (vx > 0)
			return Character::Direction::Right;
		else
			return Character::Direction::Left;
	else
		if (vy > 0)
			return Character::Direction::Down;
		else
			return Character::Direction::Up;
}

bool Physics::checkCollision(GameObject* object1, GameObject* object2)
{
	return
		(
		//object1's right side to the right of object2's left side
		((object1->getX() + object1->getSX()) > object2->getX())
		//object1's bottom side below object2's top
		&& ((object1->getY() + object2->getSY()) > object2->getY())
		//object1's left side to the left of object2's right side
		&& (object1->getX() < (object2->getX() + object2->getSX()))
		//object1's top above object2's bottom
		&& (object1->getY() < (object2->getY() + object2->getSY()))
		);
}

bool Physics::checkCollision(GameObject* object, int x, int y)
{
	return
		(
		x > object->getX()
		&& x < object->getX() + object->getSX()
		&& y > object->getY()
		&& y < object->getY() + object->getSY()
		);
}