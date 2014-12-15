#pragma once
#include "InputHandler.h"
#include "GameObject_Manager.h"
class Combat_GameState
{
	GameObject_Manager* _objectManager;
	InputHandler* _inputHandler;

public:
	Combat_GameState();
	~Combat_GameState();

	GameObject_Manager* getGameObject_Manager();
	InputHandler* getInputHandler();
};

