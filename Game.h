#pragma once

#include <vector>
#include <SDL.h>
#include "GameObject.h"
#include "Player.h"
#include "InputHandler.h"

class Game
{
	//All game objects to loop through
	std::vector<GameObject*> _objects;
	InputHandler _inputHandler;

public:

	//receives renderer so that it can load textures onto it
	Game();
	~Game();

	void gameLoop();

	//three methods which are repeatedly called for each GameObject
	void selectObject(int x, int y);
	void update(GameObject*);
	void render(GameObject*);

};

