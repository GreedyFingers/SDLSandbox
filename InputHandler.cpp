#pragma once
#include "InputHandler.h"
#include "Game.h"

InputHandler::InputHandler(Game* game)
{
	_game = game;
}

InputHandler::~InputHandler()
{
}

void InputHandler::mouseClick(int x, int y)
{
	_game->selectObject(x, y);
}