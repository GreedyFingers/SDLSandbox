#include <algorithm>
#include <functional>
#include "Game.h"
#include "GameObject.h"
#include "Player.h"
#include "Scout.h"

Game::Game(SDL_Renderer *renderer)
{
	int rw;
	int rh;
	SDL_GetRendererOutputSize(renderer,&rw,&rh);
	Player *player = new Player((float)rw / 2, (float)rh - 50, renderer);
	Scout *scout1 = new Scout((float)rw * 1 / 4, (float)rh - 200, renderer);
	Scout *scout2 = new Scout((float)rw * 2 / 4, (float)rh - 200, renderer);
	Scout *scout3 = new Scout((float)rw * 3 / 4, (float)rh - 200, renderer);
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
