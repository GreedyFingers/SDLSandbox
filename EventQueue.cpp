#pragma once
#include "EventQueue.h"
#include "InputHandler.h"
#include <stdio.h>

EventQueue::EventQueue(InputHandler* inputHandler)
{
	_inputHandler = inputHandler;
}

EventQueue::~EventQueue()
{
}

bool EventQueue::eventLoop()
{
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		switch (e.type)
		{
			case SDL_QUIT:
				return true;
			case SDL_MOUSEBUTTONUP:
				int x, y;
				SDL_GetMouseState(&x, &y);
				_inputHandler->mouseClick(x,y);
				break;
			default:
				break;
		}
	}

	return false;
}
