#include "Terrain.h"

Terrain::Terrain(SDL_Renderer* renderer, int x, int y)
{
	_sx = Terrain_Assets::TEXTURE_W;
	_sy = Terrain_Assets::TEXTURE_H;
	init(	renderer, 
			x, 
			y, 
			GameObject::UnitControl, 
			Terrain_Assets::TEXTURE_PATH, 
			Terrain_Assets::SPRITE_COUNT, 
			Terrain_Assets::ANIMATION_COUNT
		);
	_currentClip = _clips[0];
	_texture->setAlpha(128);

	_animations[Terrain_Assets::ANIMATIONS::NONE].init(Terrain_Assets::NO_ANIMATION, 
														sizeof(Terrain_Assets::NO_ANIMATION));
}


Terrain::~Terrain()
{
}
