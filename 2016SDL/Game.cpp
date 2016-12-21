#pragma once
#include <algorithm>
#include <functional>
#include "Game.h"
#include "SDLEvents.h"

Game::Game(Util::Renderer* renderer)
{

	_renderer = renderer;
	//Physics::initPhysics(Draw::getRWNormalized(), Draw::getRHNormalized());

}

Game::~Game()
{
}

void Game::start()
{
	run();
}

void Game::run()
{
	Util::SDLEvents::SDL_Event_Props s;

	while (s.event_type!=Util::CommonEnums::QUIT)
	{
		s = Util::SDLEvents::eventLoop();
		update();
		render();
	}

	//_gameState->getGameObject_Manager()->update();
	//_gameState->getGameObject_Manager()->render();

}

void Game::stop()
{

}

void Game::update()
{

}

void Game::render()
{
	_renderer->setRenderDrawColor(0xFF, 0x00, 0x00, 0xFF);

	_renderer->renderClear();

	_renderer->renderPresent();

	//wait about 1/60 of a second
	SDL_Delay(30);
}

