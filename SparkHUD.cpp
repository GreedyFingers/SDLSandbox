#pragma once
#include "SparkHUD.h"
#include "GameObject.h"
#include "draw.h"


SparkHUD::SparkHUD(int x, int y)
{
	_sx = SparkHUD_Assets::TEXTURE_W;
	_sy = SparkHUD_Assets::TEXTURE_H;
	init(	x,
			y,
			GameObject::UnitControl,
			SparkHUD_Assets::SPRITE_COUNT
		);
	_currentClip = _clips[0];

	_texture.setTexture(Draw::loadTexture(SparkHUD_Assets::TEXTURE_PATH));
	_textBox.loadText("100", { 0, 0, 0 }, _sx, _sy);
}


SparkHUD::~SparkHUD()
{
}

void SparkHUD::render()
{
	_texture.render(_x, _y, _clips, _currentClipIndex);
	//_textBox.render(_x, _y);
}
