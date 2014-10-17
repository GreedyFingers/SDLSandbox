#include "Sprite.h"
#include "Draw.h"

Sprite::Sprite(SDL_Renderer* renderer, std::string texturePath, int animationCount)
{
	_texture = Draw::loadTexture(renderer, texturePath);
	initAnimations(animationCount);
}

Sprite::~Sprite()
{
	delete _animations;
	_animations = NULL;
}

//Render a clip from the texture to screen
bool Sprite::render(SDL_Renderer* renderer, int x, int y, SDL_Rect* clip,
	int clipIndex, int timeSinceLastDraw)
{
	_currentAnimationIndex = _currentAnimation.getCurrentFrame(timeSinceLastDraw);
	if (Draw::draw(renderer, _texture, x, y, &clip[clipIndex + _currentAnimationIndex]) == false)
		return true;
	else
		return false;
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