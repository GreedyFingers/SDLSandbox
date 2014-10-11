#include "UnitControl.h"
#include "draw.h"

UnitControl::UnitControl(SDL_Renderer* renderer,int rw, int rh)
{
	_sx = (int)(rw * UNIT_CONTROL_DOCK_W);
	_sy = (int)(rh * UNIT_CONTROL_DOCK_H);
	_spriteCount = 1;
	init(renderer,UNIT_CONTROL_DOCK_X, UNIT_CONTROL_DOCK_Y, 
			GameObject::player, TEXTURE_PATH, SPRITE_COUNT);
	_currentClip = _clips[0];
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
