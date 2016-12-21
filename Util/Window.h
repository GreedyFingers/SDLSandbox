#pragma once

#ifdef WINDOW_EX
#define WINDOW_EX __declspec(dllexport)
#else
#define WINDOW_EX __declspec(dllimport)
#endif  

#include "stdafx.h"
#include "SDL.h"

namespace Util
{
	class WINDOW_EX Window
	{
		SDL_Window* _SDLWindow;

	public:
		Window();
		~Window();

		bool init(char* windowName, int screenWidth, int screenHeight);

		SDL_Window* getSDLWindow();

	};
}