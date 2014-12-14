#pragma once
#include <SDL.h>
#include "InputHandler.h"

class EventQueue
{
	SDL_Event _e;
	InputHandler* _inputHandler = NULL;

public:
	EventQueue(InputHandler* inputHandler);
	~EventQueue();

	bool eventLoop();
};

