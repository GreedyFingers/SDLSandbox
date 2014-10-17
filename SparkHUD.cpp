#include "SparkHUD.h"
#include "GameObject.h"


SparkHUD::SparkHUD(SDL_Renderer* renderer, int x, int y)
{
	_sx = SparkHUD_Assets::TEXTURE_W;
	_sy = SparkHUD_Assets::TEXTURE_H;
	init(	renderer,
			x,
			y,
			GameObject::UnitControl,
			SparkHUD_Assets::SPRITE_COUNT
		);
	_currentClip = _clips[0];

	_texture.init(renderer, SparkHUD_Assets::TEXTURE_PATH);
}


SparkHUD::~SparkHUD()
{
}

void SparkHUD::render(SDL_Renderer* renderer)
{
	_texture.render(renderer, _x, _y, _clips, _currentClipIndex);
}
