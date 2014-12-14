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
	printf("%d", SDL_PollEvent(&_e));
	while (SDL_PollEvent(&_e) == 1 && &_e != NULL)
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
			default:
				break;
		}
	}

	return false;
}
