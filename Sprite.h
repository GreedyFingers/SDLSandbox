#pragma once
#include "Texture.h"

class Sprite : public Texture
{

	Animation* _animations;
	Animation _currentAnimation;
	int _currentAnimationIndex;

public:
	Sprite(SDL_Renderer* renderer, std::string texturePath, int animationCount);
	~Sprite();

	void initAnimations(int animationCount);

	bool render(SDL_Renderer* renderer, int x, int y, SDL_Rect* clip,
		int clipIndex, int timeSinceLastDraw);

	Animation getCurrentAnimation();
	Animation* getAnimations();
	int getCurrentAnimationIndex();
	void setCurrentAnimationIndex(int value);
};

