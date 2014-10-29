#pragma once
#include "Terrain.h"
#include "draw.h"

Terrain::Terrain(int x, int y)
{
	init(	x, 
			y, 
			GameObject::UnitControl,
			Terrain_Assets::TEXTURE_W,
			Terrain_Assets::TEXTURE_H
		);

	_texture.setTexture(Draw::loadTexture(Terrain_Assets::TEXTURE_PATH),
						Terrain_Assets::SPRITE_COUNT, 
						_sx,
						_sy);
}


Terrain::~Terrain()
{
}

void Terrain::render()
{
	_texture.render(_x, _y, _currentTextureClip);
}
