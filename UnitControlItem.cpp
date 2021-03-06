#include "UnitControl_Assets.h"
#include "UnitControlItem.h"
#include "UnitControlItem_Assets.h"
#include "Global_Assets.h"

UnitControlItem::UnitControlItem(int UnitControlX, int UnitControlY,
									int UnitControlSizeX, int positionInContainer)
{
	init(UnitControlX, UnitControlY, UnitControlSizeX, positionInContainer);
}

UnitControlItem::UnitControlItem()
{

}

UnitControlItem::~UnitControlItem()
{
}

void UnitControlItem::init(int UnitControlX, int UnitControlY,
							int UnitControlSizeX, int positionInContainer)
{
	int size = UnitControlSizeX - (UnitControl_Assets::ITEM_MARGIN * 2);
	int x = UnitControl_Assets::ITEM_MARGIN + UnitControlX;
	int y = UnitControlY
			+ (UnitControl_Assets::ITEM_MARGIN + (UnitControl_Assets::ITEM_MARGIN * positionInContainer))
			+ (size*positionInContainer);

	__super::init(x, y, _type, size, size);

	_texture.setTexture(Draw::loadTexture(UnitControlItem_Assets::TEXTURE_PATH), 
						UnitControlItem_Assets::SPRITE_COUNT, _sx, _sy);
	_texture.setAlpha(128);
}

void UnitControlItem::render()
{
	_texture.render(_x, _y, _currentTextureClip);
}