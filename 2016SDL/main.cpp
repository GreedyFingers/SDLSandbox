#pragma once
#include <SDL.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Renderer.h"
#include "Window.h"
#include "Game.h"
//Game constants
const static int SCREEN_WIDTH = 1200;
const static int SCREEN_HEIGHT = 900;

//SDL window handles
Util::Window* Window = new Util::Window();
Util::Renderer* Renderer = new Util::Renderer();
//Util::Renderer* renderer = NULL;

bool init()
{
	//Init time
	srand((unsigned int)time(0));

	if (!Window->init("2016 SDL", SCREEN_WIDTH, SCREEN_HEIGHT))
		return false;
	else
	{
		if (!Renderer->initRenderer(Window, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC))
			return false;
	}

}

void close()
{

	delete(Renderer);
	delete(Window);

	IMG_Quit();
	SDL_Quit();

}

int main(int argc, char *argv[])
{

	//Initialize SDL and window 
	if (!init())
		printf("Failed to initialize.\n");

	//Create main game class
	Game* game = new Game(Renderer);

	game->start();

	close();

	return 0;
}