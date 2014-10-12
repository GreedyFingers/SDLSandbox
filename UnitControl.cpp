#include "UnitControl.h"
#include "draw.h"

const int UnitControl::NO_ANIMATION[1] = { 0 };

UnitControl::UnitControl(SDL_Renderer* renderer,int rw, int rh)
{
	_sx = (int)(rw * UNIT_CONTROL_DOCK_W);
	_sy = (int)(rh * UNIT_CONTROL_DOCK_H);
	init(renderer,UNIT_CONTROL_DOCK_X, UNIT_CONTROL_DOCK_Y, 
			GameObject::player, TEXTURE_PATH, SPRITE_COUNT, ANIMATION_COUNT);
	_currentClip = _clips[0];
	_texture->setAlpha(128);

	_animations[ANIMATIONS::NONE].init(NO_ANIMATION, sizeof(NO_ANIMATION));
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
