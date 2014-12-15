#pragma once
#include <algorithm>
#include <functional>
#include "UnitControl.h"
#include "UnitControlItem.h"
#include "Item_Scout.h"
#include "draw.h"

UnitControl::UnitControl(int x, int y)
{

	init(	x, 
			y,
			GameObject::UnitControl,
			UnitControl_Assets::TEXTURE_W,
			UnitControl_Assets::TEXTURE_H
		);

	//Load this object's textures
	_texture.setTexture(Draw::loadTexture(UnitControl_Assets::TEXTURE_PATH),
											UnitControl_Assets::SPRITE_COUNT, 
											_sx, 
											_sy);
	_texture.setAlpha(128);

	//Create items contained in this object
	UnitControlItem* scoutItem = new Item_Scout(x, y, _sx, 0);
	_controlItems.push_back(scoutItem);
	scoutItem = new UnitControlItem(x, y, _sx, 1);
	_controlItems.push_back(scoutItem);
}

UnitControl::~UnitControl()
{
	_controlItems.clear();
}

void UnitControl::update()
{

}

GameObject::ObjectID UnitControl::select(int x, int y)
{
	for (auto &object : _controlItems)
	{
		if (object->containsPoint(x, y))
			return object->getType();
	}
	return _type;
}


void UnitControl::render()
{
	_texture.render(_x, _y, _currentTextureClip);
	for (auto &item : _controlItems)
	{
		item->render();
	}
}