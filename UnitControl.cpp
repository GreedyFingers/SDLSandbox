#pragma once
#include "UnitControl.h"
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
	_currentClip = _clips[0];
	//_sprite->setAlpha(128);

	_texture.setTexture(Draw::loadTexture(UnitControl_Assets::TEXTURE_PATH));
}

UnitControl::~UnitControl()
{
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
}