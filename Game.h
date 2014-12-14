#pragma once

#include <vector>
#include <SDL.h>
#include "GameObject.h"
#include "Player.h"

class Game
{
	Combat_GameState *_gameState;
	EventQueue* _eventQueue;

public:

	//receives renderer so that it can load textures onto it
	Game();
	~Game();

	bool gameLoop();

	//three methods which are repeatedly called for each GameObject
	void selectObject(int x, int y);
	void update(GameObject*);
	void render(GameObject*);

};

