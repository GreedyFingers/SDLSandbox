#pragma once

#include "GameObject.h"
#include "Draw.h"


GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

void GameObject::init(SDL_Renderer* renderer, int x, int y, ObjectID type,
	std::string texturePath, int spritestart = 0, int spriteend = 0 )
{
	_x = x;
	_y = y;
	_spritestart = spritestart;
	_spriteend = spriteend;
	_type = type;
	_texture = new Texture(renderer,texturePath);
	_remove = false;
}

void GameObject::input()
{

}

void GameObject::update()
{
	int currentTime = SDL_GetTicks();
	_timeSinceLastUpdate = currentTime - _lastUpdateTime;
	_lastUpdateTime = currentTime;
}

void GameObject::render(SDL_Renderer* renderer)
{
	if (_texture->render(renderer,_x, _y, _sx, _sy, _spritestart))
		_remove = true;
}

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

Texture* GameObject::getTexture()
{
	return _texture;
}