#pragma once
#include <SDL.h>
#include "CommonEnums.h"

#ifdef SDL_EVENTS_EX
#define SDL_EVENTS_EX __declspec(dllexport)
#else
#define SDL_EVENTS_EX __declspec(dllimport)
#endif 

namespace Util
{
	class SDL_EVENTS_EX SDLEvents
	{
	public:
		SDLEvents();
		~SDLEvents();

		struct SDL_Event_Props
		{
			CommonEnums::EventEnums event_type = CommonEnums::EventEnums::NO_EVENT;
			int x = -1;
			int y = -1;
		};

		static SDL_Event_Props eventLoop();

	};
}