#pragma once
#include "Combat_GameState.h"
#include "UnitControl_Assets.h"
#include "SparkHUD_Assets.h"

Combat_GameState::Combat_GameState()
{

	InputHandler* inputHandler = new InputHandler();
	_objectManager = new GameObject_Manager();
	//Make some objects for start of game
	_objectManager->createObject(GameObject::Terrain, 200, 0);
	_objectManager->createObject(GameObject::Player, 400, 550);
	_objectManager->createObject(GameObject::Scout, 300, 300);
	_objectManager->createObject(GameObject::Scout, 400, 300);
	_objectManager->createObject(GameObject::Scout, 500, 300);
	_objectManager->createObject(GameObject::UnitControl, 0, 0);
	_objectManager->createObject(	GameObject::SparkHUD, 
									UnitControl_Assets::TEXTURE_W + 5, 
									UnitControl_Assets::TEXTURE_H - SparkHUD_Assets::TEXTURE_H - 5);
}

Combat_GameState::~Combat_GameState()
{
}


GameObject_Manager* Combat_GameState::getGameObject_Manager()
{
	return _objectManager;
}

InputHandler* Combat_GameState::getInputHandler()
{
	return _inputHandler;
}

