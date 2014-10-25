#pragma once

#include "GameObject.h"

char* GameObject::ObjectNames[4] = {
	"Player",
	"Scout",
	"UnitControl",
	"Terrain"
};

GameObject::GameObject()
{
}

//Cleanup
GameObject::~GameObject()
{
	delete _clips;
	_clips = NULL;
}

//initialize clips, object location, type, and texture
void GameObject::init(int x, int y, ObjectID type, int spriteCount)
{
	//Set location
	_x = x;
	_y = y;

	//Set type
	_type = type;
	
	//Initialize sprites
	_clips = initClips(spriteCount);
	_currentClip = _clips[0];
	_currentClipIndex = 0;

	//Set flag of when to remove this object
	_remove = false;
}

//Create clips for individual sprites within texture
SDL_Rect* GameObject::initClips(int spriteCount)
{
	SDL_Rect* clips = (SDL_Rect*)malloc(sizeof(SDL_Rect)*spriteCount);
	if (clips == NULL)
		printf("Error initializing clips for %s texture.\n", ObjectNames[_type]);
	else
	{
		for (int i = 0; i < spriteCount; i++)
		{
			//offset first sprite by sprite size per rectangle
			clips[i].x = i * _sx;
			clips[i].y = 0;
			clips[i].w = _sx;
			clips[i].h = _sy;
		}
	}
	return clips;
}

void GameObject::input()
{

}

//base update called to determine when this GameObject was last updated
void GameObject::update()
{
	_clock.setTimeSinceLastUpdate(SDL_GetTicks());
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