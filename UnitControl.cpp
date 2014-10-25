#pragma once
#include <algorithm>
#include <functional>
#include "UnitControl.h"
#include "UnitControlItem.h"
#include "draw.h"

UnitControl::UnitControl(int x, int y)
{
	_sx = UnitControl_Assets::TEXTURE_W;
	_sy = UnitControl_Assets::TEXTURE_H;
	init(	x, 
			y,
			GameObject::UnitControl, 
			UnitControl_Assets::SPRITE_COUNT
		);

	//Load this object's textures
	_texture.setTexture(Draw::loadTexture(UnitControl_Assets::TEXTURE_PATH));
	_texture.setAlpha(128);

	//Create items contained in this object
	int itemMargin = UnitControl_Assets::ITEM_MARGIN;
	UnitControlItem* scoutItem = new UnitControlItem(x, y, _sx, 0);
	_controlItems.push_back(scoutItem);
	scoutItem = new UnitControlItem(x, y, _sx, 1);
	_controlItems.push_back(scoutItem);
	scoutItem = new UnitControlItem(x, y, _sx, 2);
	_controlItems.push_back(scoutItem);
}

UnitControl::~UnitControl()
{
	_controlItems.clear();
}

void UnitControl::input()
{

}

void UnitControl::update()
{

}

void UnitControl::render()
{
	_texture.render(_x, _y, _clips, _currentClipIndex);
	for (auto &item : _controlItems)
	{
		item->render();
	}
}