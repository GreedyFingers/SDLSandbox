#include "SparkHUD.h"
#include "GameObject.h"


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

	_texture.init(SparkHUD_Assets::TEXTURE_PATH);
}


SparkHUD::~SparkHUD()
{
}

void SparkHUD::render()
{
	_texture.render(_x, _y, _clips, _currentClipIndex);
}
