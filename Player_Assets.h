#pragma once
class Player_Assets
{
public:

	//Player Assets
	static const char* TEXTURE_PATH;
	static const int TEXTURE_SIZE_X = 32;
	static const int TEXTURE_SIZE_Y = 30;
	static const int SPRITE_COUNT = 8;
	static const int ANIMATION_COUNT = 1;
	static const int NO_ANIMATION[1];
	enum ANIMATIONS
	{
		NONE = 0
	};

	Player_Assets();
	~Player_Assets();
};

