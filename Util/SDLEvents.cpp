#pragma once
#include "stdafx.h"
#include "SDLEvents.h"
#include <stdio.h>

namespace Util
{
	SDLEvents::SDLEvents()
	{

	}

	SDLEvents::~SDLEvents()
	{

	}

	//TODO: make into vector
	SDLEvents::SDL_Event_Props SDLEvents::eventLoop()
	{

		SDLEvents::SDL_Event_Props s;

		SDL_Event e;
		while (SDL_PollEvent(&e))
		{
			switch (e.type)
			{
			case SDL_QUIT:
				s.event_type = CommonEnums::EventEnums::QUIT;
				break;
			case SDL_MOUSEBUTTONUP:
				int x, y;
				SDL_GetMouseState(&x, &y);
				s.x = x;
				s.y = y;
				s.event_type = CommonEnums::EventEnums::LEFT_MOUSE_CLICK;
				//_inputHandler->mouseClick(x, y);
				break;
			default:
				break;
			}
		}
		return s;
	}
}