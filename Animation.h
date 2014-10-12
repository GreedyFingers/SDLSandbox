#pragma once
#include <map>
#include "Clock.h"

class Animation
{

	int* _frameDurations;
	int _currentFrame;
	int _currentFrameTime;
	int _numberOfFrames;

public:
	Animation();
	~Animation();

	void init(const int frameTimes[], int size);
	void beginAnimation();
	int getCurrentFrame(int timeSinceLastDraw);
};

