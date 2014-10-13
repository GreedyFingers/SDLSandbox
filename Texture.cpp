#include "Texture.h"
#include "Draw.h"

//Create and initialize texture for current renderer
Texture::Texture(SDL_Renderer* renderer,std::string texturePath, int animationCount)
{
	_texture = Draw::loadTexture(renderer,texturePath);
	initAnimations(animationCount);
}

//Destroy texture
Texture::~Texture()
{
	SDL_DestroyTexture(_texture);
	_texture = NULL;
	delete _animations;
	_animations = NULL;
}

//Render a clip from the texture to screen
bool Texture::render(SDL_Renderer* renderer, int x, int y, SDL_Rect* clip, 
						int clipIndex, int timeSinceLastDraw)
{
	_currentAnimationIndex = _currentAnimation.getCurrentFrame(timeSinceLastDraw);
	if (Draw::draw(renderer, _texture, x, y, &clip[clipIndex+_currentAnimationIndex]) == false)
		return true;
	else
		return false;
}

//Set transparency of texture
void Texture::setAlpha(Uint8 alpha)
{
	SDL_SetTextureAlphaMod(_texture, alpha);
}

void Texture::initAnimations(int animationCount)
{
	_animations = (Animation*)malloc(sizeof(Animation)*animationCount);
}

Animation Texture::getCurrentAnimation()
{
	return _currentAnimation;
}

Animation* Texture::getAnimations()
{
	return _animations;
}

int Texture::getCurrentAnimationIndex()
{
	return _currentAnimationIndex;
}

void Texture::setCurrentAnimationIndex(int value)
{
	_currentAnimationIndex = value;
	_currentAnimation = _animations[_currentAnimationIndex];
	_currentAnimation.beginAnimation();
}