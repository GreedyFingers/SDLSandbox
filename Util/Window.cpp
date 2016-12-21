#pragma once
#include "stdafx.h"
#include <stdio.h>
#include "Window.h"

namespace Util
{
	Window::Window()
	{

	}

	Window::~Window()
	{
		//Deallocate window
		SDL_DestroyWindow(_SDLWindow);
		_SDLWindow = NULL;
	}

	bool Window::init(char* windowName,int screenWidth, int screenHeight)
	{

		_SDLWindow = SDL_CreateWindow(
			windowName,
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			screenWidth,
			screenHeight,
			SDL_WINDOW_OPENGL
		);
		if (_SDLWindow == NULL)
		{
			printf("Window could not be created. SDL_Error: %s\n", SDL_GetError());
			return false;
		}

	}

	SDL_Window* Window::getSDLWindow() 
	{ 
		return _SDLWindow; 
	}
}