#pragma once

#include <vector>
#include <SDL.h>
#include "GameObject.h"
#include "Player.h"

class Game
{
	//All game objects to loop through
	std::vector<GameObject*> _objects;

	//passed to the gameobjects for rendering
	SDL_Renderer* _renderer;

public:

	//receives renderer so that it can load textures onto it
	Game(SDL_Renderer* renderer);
	~Game();

	void gameLoop();

	//three methods which are repeatedly called for each GameObject
	void input(GameObject*);
	void update(GameObject*);
	void render(GameObject*);

};

