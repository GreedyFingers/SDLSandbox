#include "UnitControl.h"
#include "draw.h"

UnitControl::UnitControl(SDL_Renderer* renderer,int x, int y)
{
	_sx = UnitControl_Assets::TEXTURE_W;
	_sy = UnitControl_Assets::TEXTURE_H;
	init(	renderer, 
			x, 
			y,
			GameObject::UnitControl, 
			UnitControl_Assets::TEXTURE_PATH, 
			UnitControl_Assets::SPRITE_COUNT, 
			UnitControl_Assets::ANIMATION_COUNT
		);
	_currentClip = _clips[0];
	_texture->setAlpha(128);

	_texture->getAnimations()[UnitControl_Assets::ANIMATIONS::NONE].init(UnitControl_Assets::NO_ANIMATION,
														sizeof(UnitControl_Assets::NO_ANIMATION));
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
