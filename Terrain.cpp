#pragma once
#include "Terrain.h"
#include "draw.h"

Terrain::Terrain(int x, int y)
{
	_sx = Terrain_Assets::TEXTURE_W;
	_sy = Terrain_Assets::TEXTURE_H;
	init(	x, 
			y, 
			GameObject::UnitControl, 
			Terrain_Assets::SPRITE_COUNT
		);
	_currentClip = _clips[0];

	_texture.setTexture(Draw::loadTexture(Terrain_Assets::TEXTURE_PATH));
}


Terrain::~Terrain()
{
}

void Terrain::render()
{
	_texture.render(_x, _y, _clips, _currentClipIndex);
}
