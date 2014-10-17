#include "Terrain.h"

Terrain::Terrain(SDL_Renderer* renderer, int x, int y)
{
	_sx = Terrain_Assets::TEXTURE_W;
	_sy = Terrain_Assets::TEXTURE_H;
	init(	renderer, 
			x, 
			y, 
			GameObject::UnitControl, 
			Terrain_Assets::SPRITE_COUNT
		);
	_currentClip = _clips[0];

	_texture.init(renderer, Terrain_Assets::TEXTURE_PATH);
}


Terrain::~Terrain()
{
}

void Terrain::render(SDL_Renderer* renderer)
{
	_texture.render(renderer, _x, _y, _clips, _currentClipIndex);
}
