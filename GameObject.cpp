#pragma once

#include "GameObject.h"
#include "Draw.h"


GameObject::GameObject()
{
}


GameObject::~GameObject()
{
	SDL_DestroyTexture(_texture);
}

void GameObject::init(float x, float y, int sx, int sy, ObjectID type,
	std::string texturePath, SDL_Renderer *renderer, int spritestart = 0, int spriteend = 0 )
{
	_x = x;
	_y = y;
	_spritestart = spritestart;
	_spriteend = spriteend;
	_sx = sx;
	_sy = sy;
	_type = type;
	_texture = Draw::loadTexture(renderer, texturePath);
	_renderer = renderer;
	_remove = false;
}

void GameObject::input()
{

}

void GameObject::update()
{

}

void GameObject::render()
{
	if (Draw::draw(_renderer, _texture, _x, _y, _spritestart, 0, _sx, _sy) == false)
		_remove = true;
}

float GameObject::getX()
{
	return _x;
}

float GameObject::getY()
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

SDL_Texture* GameObject::getTexture()
{
	return _texture;
}