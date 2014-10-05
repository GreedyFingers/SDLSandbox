#include "UnitControl.h"
#include "draw.h"

SDL_Color UnitControl::UNIT_CONTROL_DOCK_COLOR;

UnitControl::UnitControl(SDL_Renderer* renderer, int rw, int rh)
{
	_renderer = renderer;

	UNIT_CONTROL_DOCK_COLOR = { 0x00, 0x00, 0x44, 0x10 };

	unitControlViewPort.x = UNIT_CONTROL_DOCK_X;
	unitControlViewPort.y = UNIT_CONTROL_DOCK_Y;
	unitControlViewPort.w = (int)(UNIT_CONTROL_DOCK_W * rw);
	unitControlViewPort.h = (int)(UNIT_CONTROL_DOCK_H * rh);

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
	Draw::drawRect(_renderer, unitControlViewPort.x, unitControlViewPort.y,
		unitControlViewPort.w, unitControlViewPort.h,
		UNIT_CONTROL_DOCK_COLOR.r, UNIT_CONTROL_DOCK_COLOR.g,
		UNIT_CONTROL_DOCK_COLOR.b, UNIT_CONTROL_DOCK_COLOR.a);
}
