#pragma once
class Terrain_Assets
{
public:

	static const int TEXTURE_W = 500;
	static const int TEXTURE_H = 800;
	static const char* TEXTURE_PATH;
	static const int SPRITE_COUNT = 1;
	static const int ANIMATION_COUNT = 1;
	static const int NO_ANIMATION[1];

	enum ANIMATIONS
	{
		NONE = 0
	};

	Terrain_Assets();
	~Terrain_Assets();
};

