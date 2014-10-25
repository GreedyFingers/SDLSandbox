#include "UnitControlItem.h"
#include "UnitControlItem_Assets.h"


UnitControlItem::UnitControlItem()
{
}

UnitControlItem::~UnitControlItem()
{
}

//This is a box, so only one size is necessary
void UnitControlItem::init(int x, int y, int size)
{
	_sx = size;
	_sy = size;
	__super::init(x, y, GameObject::UnitControl, UnitControlItem_Assets::SPRITE_COUNT);

	_texture.setTexture(Draw::loadTexture(UnitControlItem_Assets::TEXTURE_PATH));
	_texture.setAlpha(128);
}

void UnitControlItem::render()
{
	_texture.render(_x, _y, _clips, _currentClipIndex);
}