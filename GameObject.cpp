#pragma once

#include "GameObject.h"
#include "Draw.h"

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

	delete _animations;
	_animations = NULL;
}

//initialize clips, object location, type, and texture
void GameObject::init(SDL_Renderer* renderer, int x, int y, ObjectID type, 
						std::string texturePath, int spriteCount, int animationCount)
{
	//set location
	_x = x;
	_y = y;

	//Set type
	_type = type;
	_texture = new Texture(renderer,texturePath);
	
	//Initialize sprites
	initClips(spriteCount);
	_currentClip = _clips[0];

	//Initialize animations
	initAnimations(animationCount);

	//Set flag of when to remove this object
	_remove = false;
}

//Create clips for individual sprites within texture
void GameObject::initClips(int spriteCount)
{
	_clips = (SDL_Rect*)malloc(sizeof(SDL_Rect)*spriteCount);
	if (_clips == NULL)
		printf("Error initializing clips for %s texture.\n", ObjectNames[_type]);
	else
	{
		for (int i = 0; i < spriteCount; i++)
		{
			//offset first sprite by sprite size per rectangle
			_clips[i].x = i * _sx;
			_clips[i].y = 0;
			_clips[i].w = _sx;
			_clips[i].h = _sy;
		}
	}
}

//TODO: Figure out how to make this object oriented so that I don't have to
//set all of my animations in the derived classes. I need a single constant with all
//of my constant arrays of frame durations
void GameObject::initAnimations(int animationCount)
{
	_animations = (Animation*)malloc(sizeof(Animation)*animationCount);
}

void GameObject::input()
{

}

//base update called to determine when this GameObject was last updated
void GameObject::update()
{
	_clock.setTimeSinceLastUpdate(SDL_GetTicks());
}

//render this object's texture with the current clip
void GameObject::render(SDL_Renderer* renderer)
{
	_clock.setTimeSinceLastDraw(SDL_GetTicks());
	if (_texture->render(renderer,_x, _y, &_currentClip))
		_remove = true;
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