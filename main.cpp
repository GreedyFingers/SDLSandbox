#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include "Game.h"
#include "draw.h"

//Game constants
const static int SCREEN_WIDTH = 1200;
const static int SCREEN_HEIGHT = 900;

//SDL window handles
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

bool init()
{
	//Init time
	srand((unsigned int)time(0));

	//Init flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize. SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	//SDL_Init succeeded
	else
	{
		//Window creation
		window = SDL_CreateWindow(
			"Tutorial",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			SDL_WINDOW_OPENGL
			);
		if (window == NULL)
		{
			printf("Window could not be created. SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			Draw::initRenderer(window, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

			//Initialize PNG loading
			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) & imgFlags))
			{
				printf("SDL_image could not initialize. SDL_image Error: %s\n", IMG_GetError());
				success = false;
			}
		}
	}

	return success;
}

void close()
{
	//Deallocate surface
	SDL_DestroyRenderer(renderer);
	renderer = NULL;

	//Deallocate window
	SDL_DestroyWindow(window);
	window = NULL;

	IMG_Quit();
	SDL_Quit();

}

int main(int argc, char *argv[])
{

	//Initialize SDL and window 
	if (!init())
		printf("Failed to initialize.\n");

	//Create main game class
	Game game;

	//TODO: add onload waiter here until everything has loaded
	//SDL_Delay(100);
	//Game loop
	bool quit = false;
	while (!quit)
	{

		Draw::setRenderDrawColor(0x00, 0x00, 0x00, 0xFF);

		Draw::renderClear();
		
		//Main game processing (input, update, render)
		quit = game.gameLoop();

		Draw::renderPresent();

		//wait about 1/60 of a second
		SDL_Delay(30);
	}

	close();

	return 0;
}