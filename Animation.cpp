#pragma once
#include "Animation.h"

//Until initialized, presume this animation has no frames
Animation::Animation()
{
	_numberOfFrames = 0;
}

//Clean up
Animation::~Animation()
{
	delete _frameDurations;
}

//Set this animation's time delays based on the constant array received
void Animation::init(const int frameTimes[], int size)
{
	//Determine number of frames from array size
	_numberOfFrames = size / sizeof(int);
	_frameDurations = (int*)malloc(sizeof(int) * _numberOfFrames);
	for (int i = 0; i < _numberOfFrames; i++)
	{
		_frameDurations[i] = frameTimes[i];
	}
}

//reset the current animation to the first frame
void Animation::beginAnimation()
{
	_currentFrame = 0;
	_currentFrameTime = 0;
}

//Determine which frame should currently be displayed for rendering
int Animation::getCurrentFrame(int timeSinceLastDraw)
{
	//Handles if animation hasn't been initialized yet, 
	//or if the animation has only one frame (no animation)
	if (_numberOfFrames <= 1)
		_currentFrame = 0; 
	else
	{
		_currentFrameTime += timeSinceLastDraw;
		if (_currentFrameTime > _frameDurations[_currentFrame])
		{
			//trim off how long this frame took in case of lag, so
			//it will skip to which ever frame it SHOULD be on
			_currentFrameTime -= _frameDurations[_currentFrame];
			_currentFrame = (_currentFrame + 1) % _numberOfFrames;
		}
	}
	return _currentFrame;
}