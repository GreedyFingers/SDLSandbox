#include "Clock.h"
#include <SDL.h>


Clock::Clock()
{
}


Clock::~Clock()
{
}

int Clock::getTimeSinceLastUpdate()
{
	return _timeSinceLastUpdate;
}

int Clock::getTimeSinceLastDraw()
{
	return _timeSinceLastDraw;
}

void Clock::setTimeSinceLastUpdate(int time)
{
	int currentTime = time;
	_timeSinceLastUpdate = currentTime - _lastUpdateTime;
	_lastUpdateTime = currentTime;
}

void Clock::setTimeSinceLastDraw(int time)
{
	int currentTime = time;
	_timeSinceLastDraw = currentTime - _lastDrawTime;
	_lastDrawTime = currentTime;
}