#pragma once
#include "InputHandler.h"
#include "Game.h"

InputHandler::InputHandler(GameObject_Manager *objectManager)
{
	_objectManager = objectManager;
}

InputHandler::~InputHandler()
{
}

void InputHandler::mouseClick(int x, int y)
{
	_objectManager->selectObject(x, y);
}