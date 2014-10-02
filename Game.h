#pragma once

#include <vector>
#include <SDL.h>
#include "GameObject.h"
#include "Player.h"

class Game
{
	std::vector<GameObject*> _objects;

	SDL_Surface* _screen;

public:
	Game(SDL_Surface*);
	~Game();

	void gameLoop();
	void input(GameObject*);
	void update(GameObject*);
	void render(GameObject*);
	void detectCollisions();
	
};

