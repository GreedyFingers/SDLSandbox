#include "UnitControl_Assets.h"
#include "UnitControlItem.h"
#include "UnitControlItem_Assets.h"

//This is a box, so only one size is necessary
UnitControlItem::UnitControlItem(int UnitControlX, int UnitControlY, 
									int UnitControlSizeX, int positionInContainer)
{
	int size = UnitControlSizeX - (UnitControl_Assets::ITEM_MARGIN * 2);
	int x = UnitControl_Assets::ITEM_MARGIN + UnitControlX;
	int y = UnitControlY 
			+ (UnitControl_Assets::ITEM_MARGIN + (UnitControl_Assets::ITEM_MARGIN * positionInContainer))
			+ (size*positionInContainer);
	_sx = size;
	_sy = size;
	__super::init(x, y, GameObject::UnitControl, UnitControlItem_Assets::SPRITE_COUNT);

	_clips = __super::initClips(UnitControlItem_Assets::SPRITE_COUNT);

	_texture.setTexture(Draw::loadTexture(UnitControlItem_Assets::TEXTURE_PATH));
	_texture.setAlpha(128);
}

UnitControlItem::~UnitControlItem()
{
}


void UnitControlItem::render()
{
	_texture.render(_x, _y, _clips, _currentClipIndex);
}