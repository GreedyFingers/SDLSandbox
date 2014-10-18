#pragma once
#include "Sprite.h"
#include "Draw.h"

Sprite::Sprite(std::string texturePath, int animationCount)
{
	_texture.setTexture(Draw::loadTexture(texturePath));
	initAnimations(animationCount);
}

Sprite::~Sprite()
{
	delete _animations;
	_animations = NULL;
}

//Render a clip from the texture to screen
bool Sprite::render(int x, int y, SDL_Rect* clip,
	int clipIndex, int timeSinceLastDraw)
{
	_currentAnimationIndex = _currentAnimation.getCurrentFrame(timeSinceLastDraw);
	return _texture.render(x, y, clip, clipIndex + _currentAnimationIndex);
}

void Sprite::initAnimations(int animationCount)
{
	_animations = (Animation*)malloc(sizeof(Animation)*animationCount);
}

Animation Sprite::getCurrentAnimation()
{
	return _currentAnimation;
}

Animation* Sprite::getAnimations()
{
	return _animations;
}

int Sprite::getCurrentAnimationIndex()
{
	return _currentAnimationIndex;
}

void Sprite::setCurrentAnimationIndex(int value)
{
	_currentAnimationIndex = value;
	_currentAnimation = _animations[_currentAnimationIndex];
	_currentAnimation.beginAnimation();
}