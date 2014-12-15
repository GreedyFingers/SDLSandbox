#pragma once
#include "SparkHUD.h"
#include "GameObject.h"
#include "draw.h"

SparkHUD::SparkHUD(int x, int y)
{
	init(	x,
			y,
			GameObject::UnitControl,
			SparkHUD_Assets::TEXTURE_W,
			SparkHUD_Assets::TEXTURE_H
		);

	_texture.setTexture(Draw::loadTexture(SparkHUD_Assets::TEXTURE_PATH), 
						SparkHUD_Assets::SPRITE_COUNT, 
						_sx, 
						_sy);

	//_textBox.loadText("100", { 0, 0, 0 }, _sx, _sy);
}


SparkHUD::~SparkHUD()
{
}

void SparkHUD::render()
{
	_texture.render(_x, _y, _currentTextureClip);
}
