#include <algorithm>
#include <functional>
#include "Game.h"
#include "GameObject.h"
#include "Player.h"
#include "Scout.h"

Game::Game(SDL_Surface *screen)
{
	_screen = screen;
	Player *player = new Player((float)screen->w / 2, (float)screen->h - 50, screen);
	Scout *scout1 = new Scout((float)screen->w * 1 / 4, (float)screen->h - 200, screen);
	Scout *scout2 = new Scout((float)screen->w * 2 / 4, (float)screen->h - 200, screen);
	Scout *scout3 = new Scout((float)screen->w * 3 / 4, (float)screen->h - 200, screen);
	_objects.push_back(player);
	_objects.push_back(scout1);
	_objects.push_back(scout2);
	_objects.push_back(scout3);
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
