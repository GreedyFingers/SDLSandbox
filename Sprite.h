#pragma once
#include "Texture.h"

class Sprite
{
	Texture _texture;
	Animation* _animations;
	Animation _currentAnimation;
	int _currentAnimationIndex;

public:
	Sprite(std::string texturePath, int animationCount, int spriteCount, int sx, int sy);
	~Sprite();

	void initAnimations(int animationCount);

	bool render(int x, int y, int clipIndex, int timeSinceLastDraw);

	Animation getCurrentAnimation();
	Animation* getAnimations();
	int getCurrentAnimationIndex();
	void setCurrentAnimationIndex(int value);


};

