#pragma once
class Scout_Assets
{
public:

	//Scout Assets
	static const char* TEXTURE_PATH;
	static const int TEXTURE_SIZE_X = 32;
	static const int TEXTURE_SIZE_Y = 30;
	static const int SPRITE_COUNT = 8;
	static const int ANIMATION_COUNT = 2;
	static const int NO_ANIMATION[1];
	static const int MOVING_ANIMATION[2];
	enum ANIMATIONS
	{
		NONE = 0,
		MOVING = 1
	};

	Scout_Assets();
	~Scout_Assets();
};

