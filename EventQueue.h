#pragma once
#include <SDL.h>

class EventQueue
{
	SDL_Event _e;
	InputHandler* _inputHandler;

public:
	EventQueue(InputHandler* inputHandler);
	~EventQueue();

	bool eventLoop();
};

