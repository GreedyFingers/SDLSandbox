#pragma once
#include <vector>
#include "GameObject.h"
#include "InputHandler.h"
class Combat_GameState
{
	//All game objects to loop through
	std::vector<GameObject*> _objects;
	InputHandler* _inputHandler;

public:
	Combat_GameState(int rw, int rh);
	~Combat_GameState();

	void selectObject(int x, int y);
	void update();
	void render();

	InputHandler* getInputHandler();
};

