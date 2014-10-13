#pragma once
#include <string>
#include <SDL.h>
#include "Clock.h"
#include "Animation.h"

class Texture
{
	SDL_Texture* _texture;
	Animation* _animations;
	Animation _currentAnimation;
	int _currentAnimationIndex;

public:

	Texture(SDL_Renderer* renderer,std::string texturePath, int animationCount);
	~Texture();
	bool render(SDL_Renderer* renderer,int x, int y, SDL_Rect* clip, 
				int clipIndex, int timeSinceLastDraw);
	void setAlpha(Uint8 alpha);
	void initAnimations(int animationCount);

	Animation getCurrentAnimation();
	Animation* getAnimations();
	int getCurrentAnimationIndex();
	void setCurrentAnimationIndex(int value);
};

