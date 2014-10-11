#include "UnitControl.h"
#include "draw.h"

UnitControl::UnitControl(SDL_Renderer* renderer,int rw, int rh)
{
	_sx = (int)(rw * UNIT_CONTROL_DOCK_W);
	_sy = (int)(rh * UNIT_CONTROL_DOCK_H);
	init(renderer,UNIT_CONTROL_DOCK_X, UNIT_CONTROL_DOCK_Y, 
			GameObject::player, _texturePath, 0, 0);

	_currentClip.x = 0;
	_currentClip.y = 0;
	_currentClip.w = _sx;
	_currentClip.h = _sy;
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
