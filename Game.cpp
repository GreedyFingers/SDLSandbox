#include <algorithm>
#include <functional>
#include "Game.h"
#include "GameObject.h"
#include "Player.h"

Game::Game(SDL_Window *window)
{
	_screen = SDL_GetWindowSurface(window);
	Player *player = new Player((float)_screen->w / 2, (float)_screen->h - 50, _screen);
	_objects.push_back(player);
}

Game::~Game()
{
	_objects.clear();
}

void Game::gameLoop()
{
	for_each(_objects.begin(), _objects.end(), std::bind1st(std::mem_fun(&Game::input),this));

	for_each(_objects.begin(), _objects.end(), std::bind1st(std::mem_fun(&Game::update), this));;

	for_each(_objects.begin(), _objects.end(), std::bind1st(std::mem_fun(&Game::render), this));;
}

void Game::input(GameObject* object)
{
	object->input();
}

void Game::update(GameObject* object)
{
	object->update();
}

void Game::render(GameObject* object)
{
	object->render();
}

void Game::detectCollisions()
{

}
