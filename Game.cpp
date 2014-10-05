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
	SDL_GetRendererOutputSize(renderer,&rw,&rh);
	Player *player = new Player(rw / 2, rh - 50, renderer);
	Scout *scout1 = new Scout(50, 50, renderer);
	Scout *scout2 = new Scout(rw * 2 / 4, rh - 200, renderer);
	Scout *scout3 = new Scout(rw * 3 / 4, rh - 200, renderer);
	Scout *scout4 = new Scout(rw * 3 / 4, rh - 300, renderer);
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
