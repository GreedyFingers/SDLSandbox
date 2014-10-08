#include <SDL.h>
#include <SDL_image.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include "Game.h"

//Game constants
const static int SCREEN_WIDTH = 800;
const static int SCREEN_HEIGHT = 600;

//SDL window handles
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

bool init()
{
	//Init time
	srand(time(0));

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
		//SDL_CreateWindow succeeded
		else
		{
			//Create renderer for window
			renderer = SDL_CreateRenderer(window,-1, SDL_RENDERER_ACCELERATED);
			if (renderer == NULL)
			{
				printf("Renderer could not be created. SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			//SDL_CreateRenderer succeeded
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize. SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
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

	//TODO: rewrite as an adapter class
	SDL_Event e;

	//Create main game class
	Game game(renderer);

	//Game loop
	bool quit = false;
	while (!quit)
	{
		//process all inputs
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
				quit = true;
		}

		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);

		SDL_RenderClear(renderer);
		
		//Main game processing (input, update, render)
		game.gameLoop();

		SDL_RenderPresent(renderer);

		//wait about 1/60 of a second
		SDL_Delay(30);

	}

	close();

	return 0;
}