#pragma once
class SparkHUD_Assets
{

public:
	
	static const int TEXTURE_W = 75;
	static const int TEXTURE_H = 75;
	static const char* TEXTURE_PATH;
	static const int SPRITE_COUNT = 1;
	static const int ANIMATION_COUNT = 1;
	static const int NO_ANIMATION[1];

	enum ANIMATIONS
	{
		NONE = 0
	};

	SparkHUD_Assets();
	~SparkHUD_Assets();
};

