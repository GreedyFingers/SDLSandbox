#pragma once
#include <algorithm>
#include <functional>
#include "Game.h"
#include "draw.h"
#include "Physics.h"
#include "EventQueue.h"
#include "Combat_GameState.h"

Game::Game()
{
	
	//renderer width and height, so that the GameObjects know where they will be drawing
	int rw;
	int rh;

	//Initialize common assets
	Draw::getRendererSize(&rw, &rh);
	Physics::initPhysics(Draw::getRWNormalized(), Draw::getRHNormalized());

	_gameState = new Combat_GameState();
	_eventQueue = new EventQueue(_gameState->getInputHandler());

}

Game::~Game()
{
}

//Loop through vector of GameObjects and run the appropriate functions for each
bool Game::gameLoop()
{
	bool quit = false;
	//TODO: use same for loop that UnitControl uses
	quit = _eventQueue->eventLoop();

	_gameState->getGameObject_Manager()->update();
	_gameState->getGameObject_Manager()->render();

	return quit;
}