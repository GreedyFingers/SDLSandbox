#include "Item_Scout.h"
#include "Scout_Assets.h"
#include "Scout.h"


Item_Scout::Item_Scout(int UnitControlX, int UnitControlY,
						int UnitControlSizeX, int positionInContainer)
{
	_type = GameObject::ScoutItem;

	_itemTexture.setTexture(Draw::loadTexture(Scout_Assets::TEXTURE_PATH),
								Scout_Assets::SPRITE_COUNT,
								Scout_Assets::TEXTURE_SIZE_X,
								Scout_Assets::TEXTURE_SIZE_Y);
	init(UnitControlX, UnitControlY, UnitControlSizeX, positionInContainer);

	_currentItemTextureClip = Scout::Direction::Down;

	_selectable = true;
}


Item_Scout::~Item_Scout()
{
}

void Item_Scout::render()
{
	__super::render();
	_itemTexture.render(_x + (_sx / 2), _y + (_sy / 2), _currentItemTextureClip);
}