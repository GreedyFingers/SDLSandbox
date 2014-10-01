#include "GameObject.h"
#include "csurface.h"


GameObject::GameObject()
{
}


GameObject::~GameObject()
{
	delete _texture;
}

void GameObject::init(float x, float y, float sx, float sy, ObjectID type,
						std::string texturePath, SDL_Surface *screen)
{
	_x = x;
	_y = y;
	_sx = sx;
	_sy = sy;
	_type = type;
	_texture = CSurface::onLoad(texturePath);
	_screen = screen;
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
	if (CSurface::onDraw(_texture, _screen, _x, _y, 0, 0, _sx, _sy) == false)
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

float GameObject::getSX()
{
	return _sx;
}

float GameObject::getSY()
{
	return _sy;
}