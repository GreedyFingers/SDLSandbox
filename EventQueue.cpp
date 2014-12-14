#pragma once
#include "EventQueue.h"
#include "InputHandler.h"

EventQueue::EventQueue(InputHandler* inputHandler)
{
	_inputHandler = inputHandler;
}

EventQueue::~EventQueue()
{
}

bool EventQueue::eventLoop()
{
	while (SDL_PollEvent(&_e) != 0)
	{
		switch (_e.type)
		{
			case SDL_QUIT:
				return true;
			case SDL_MOUSEBUTTONUP:
				int x, y;
				SDL_GetMouseState(&x, &y);
				_inputHandler->mouseClick(x,y);
				break;
		}
	}

	return false;
}
