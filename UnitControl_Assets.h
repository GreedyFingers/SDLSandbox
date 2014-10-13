#pragma once
class UnitControl_Assets
{
public:
	//Player Assets
	static const int TEXTURE_W = 100;
	static const int TEXTURE_H = 760;
	static const char* TEXTURE_PATH;
	static const int SPRITE_COUNT = 1;
	static const int ANIMATION_COUNT = 1;
	static const int NO_ANIMATION[1];

	enum ANIMATIONS
	{
		NONE = 0
	};

	UnitControl_Assets();
	~UnitControl_Assets();
};

