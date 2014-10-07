#include <algorithm>
#include <functional>
#include "Game.h"
#include "GameObject.h"
#include "Player.h"
#include "Scout.h"
#include "UnitControl.h"

Game::Game(SDL_Renderer *renderer)
{
	int rw;
	int rh;
	_renderer = renderer;
	SDL_GetRendererOutputSize(renderer,&rw,&rh);
	Player *player = new Player(renderer, rw / 2, rh - 50);
	Scout *scout1 = new Scout(renderer, rw * 1 / 4, rh - 200);
	Scout *scout2 = new Scout(renderer, rw * 2 / 4, rh - 200);
	Scout *scout3 = new Scout(renderer, rw * 3 / 4, rh - 200);
	UnitControl *control1 = new UnitControl(renderer, rw, rh);
	_objects.push_back(player);
	_objects.push_back(scout1);
	_objects.push_back(scout2);
	_objects.push_back(scout3);
	_objects.push_back(control1);
}

Game::~Game()
{
	_objects.clear();
}

void Game::gameLoop(SDL_Renderer* renderer)
{
	for_each(_objects.begin(), _objects.end(), std::bind1st(std::mem_fun(&Game::input),this));

	for_each(_objects.begin(), _objects.end(), std::bind1st(std::mem_fun(&Game::update), this));

	for_each(_objects.begin(), _objects.end(), std::bind1st(std::mem_fun(&Game::render), this));
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
	object->render(_renderer);
}

void Game::detectCollisions()
{

}
