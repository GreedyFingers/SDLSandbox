#pragma once

#include <vector>
#include <SDL.h>
#include "GameObject.h"
#include "Player.h"
#include "EventQueue.h"
#include "Combat_GameState.h"

class Game
{
	EventQueue *_eventQueue = NULL;
	Combat_GameState *_gameState = NULL;

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

