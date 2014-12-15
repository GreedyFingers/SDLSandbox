#pragma once
#include <SDL.h>
#include "InputHandler.h"

class EventQueue
{
	InputHandler* _inputHandler = NULL;

public:
	EventQueue(InputHandler* inputHandler);
	~EventQueue();

	bool eventLoop();
};

