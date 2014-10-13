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
			SparkHUD_Assets::TEXTURE_PATH,
			SparkHUD_Assets::SPRITE_COUNT,
			SparkHUD_Assets::ANIMATION_COUNT
		);
	_currentClip = _clips[0];

	_texture->getAnimations()[SparkHUD_Assets::ANIMATIONS::NONE].init(SparkHUD_Assets::NO_ANIMATION,
														sizeof(SparkHUD_Assets::NO_ANIMATION));
}


SparkHUD::~SparkHUD()
{
}
