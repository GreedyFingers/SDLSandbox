#pragma once

#include "GameObject.h"
#include "Draw.h"


GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

//initialize clips, object location, type, and texture
void GameObject::init(SDL_Renderer* renderer, int x, int y, ObjectID type, 
						std::string texturePath, int spriteCount)
{

	_x = x;
	_y = y;
	_type = type;
	_texture = new Texture(renderer,texturePath);

	_spriteCount = spriteCount;
	initClips();
	_currentClip = _clips[0];

	_remove = false;

}

void GameObject::initClips()
{
	_clips = (SDL_Rect*)malloc(sizeof(SDL_Rect)*_spriteCount);
	for (int i = 0; i < _spriteCount; i++)
	{
		_clips[i].x = i * _sx;
		_clips[i].y = 0;
		_clips[i].w = _sx;
		_clips[i].h = _sy;
	}
}

void GameObject::input()
{

}

//base update called to determine when this GameObject was last updated
void GameObject::update()
{
	int currentTime = SDL_GetTicks();
	_timeSinceLastUpdate = currentTime - _lastUpdateTime;
	_lastUpdateTime = currentTime;
}

//render this object's texture with the current clip
void GameObject::render(SDL_Renderer* renderer)
{
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