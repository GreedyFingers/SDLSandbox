#include "Animation.h"


Animation::Animation()
{
	_numberOfFrames = 0;
}


Animation::~Animation()
{
	delete _frameDurations;
}

void Animation::init(const int frameTimes[], int size)
{
	_numberOfFrames = size / sizeof(int);
	_frameDurations = (int*)malloc(sizeof(int) * _numberOfFrames);
	for (int i = 0; i < _numberOfFrames; i++)
	{
		_frameDurations[i] = frameTimes[i];
	}
}

void Animation::beginAnimation()
{
	_currentFrame = 0;
	_currentFrameTime = 0;
}

int Animation::getCurrentFrame(int timeSinceLastDraw)
{
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