#pragma once

#include "GameObject.h"
#include "Physics.h"

char* GameObject::ObjectNames[5] = {
	"Player",
	"Scout",
	"UnitControl",
	"SparkHUD",
	"Terrain"
};

GameObject::GameObject()
{
}

//Cleanup
GameObject::~GameObject()
{
}

//initialize clips, object location, type, and texture
void GameObject::init(int x, int y, ObjectID type, int sx, int sy)
{
	//Set location
	_x = x;
	_y = y;
	_sx = sx;
	_sy = sy;

	//Set type
	_type = type;

	//Set flag of when to remove this object
	_remove = false;
}

void GameObject::select()
{

}

//base update called to determine when this GameObject was last updated
void GameObject::update()
{
	_clock.setTimeSinceLastUpdate(SDL_GetTicks());
}

void GameObject::render()
{

}

//positional getters
int GameObject::getX()
{
	return _x;
}

int GameObject::getY()
{
	return _y;
}

int GameObject::getSX()
{
	return _sx;
}

int GameObject::getSY()
{
	return _sy;
}

//get object type
GameObject::ObjectID GameObject::getType()
{
	return _type;
}

bool GameObject::containsPoint(int x, int y)
{
	return Physics::checkCollision(this, x, y);
}