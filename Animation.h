#pragma once
#include <map>
#include "Clock.h"

class Animation
{

	//Array of frame times (how long each frame in animation should last
	int* _frameDurations;
	int _currentFrame;
	//How long current frame has been displayed
	int _currentFrameTime;
	int _numberOfFrames;

public:
	Animation();
	~Animation();

	void init(const int frameTimes[], int size);
	void beginAnimation();
	int getCurrentFrame(int timeSinceLastDraw);
};

