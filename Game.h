#pragma once

#include <vector>
#include <SDL.h>
#include "GameObject.h"
#include "Player.h"

class Game
{
	std::vector<GameObject*> _objects;

	SDL_Renderer* _renderer;

public:
	Game(SDL_Renderer*);
	~Game();

	void gameLoop(SDL_Renderer* renderer);
	void input(GameObject*);
	void update(GameObject*);
	void render(GameObject*);
	void detectCollisions();
	
};

