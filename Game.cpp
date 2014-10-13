#include <algorithm>
#include <functional>
#include "Game.h"
#include "GameObject.h"
#include "Player.h"
#include "Scout.h"
#include "UnitControl.h"
#include "Terrain.h"
#include "SparkHUD.h"
#include "SparkHUD_Assets.h"

Game::Game(SDL_Renderer *renderer)
{
	//renderer width and height, so that the GameObjects know where they will be drawing
	int rw;
	int rh;
	_renderer = renderer;
	SDL_GetRendererOutputSize(renderer,&rw,&rh);

	//Make some objects for start of game
	Player *player = new Player(renderer, 600, rh - 50);
	Scout *scout1 = new Scout(renderer, 400, rh - 300);
	Scout *scout2 = new Scout(renderer, 600, rh - 300);
	Scout *scout3 = new Scout(renderer, 800, rh - 300);

	//Menus
	UnitControl *control1 = new UnitControl(renderer, 0, 0);

	//HUDs
	SparkHUD *sparkHUD = new SparkHUD(	renderer,
										control1->getSX() + 5,
										control1->getSY() - SparkHUD_Assets::TEXTURE_H - 5);

	//Terrain
	Terrain *terrain = new Terrain(renderer, (int)(rw / 4), 0);

	//push objects into vector
	_objects.push_back(terrain);
	_objects.push_back(player);
	_objects.push_back(scout1);
	_objects.push_back(scout2);
	_objects.push_back(scout3);
	_objects.push_back(control1);
	_objects.push_back(sparkHUD);
}

Game::~Game()
{
	_objects.clear();
}

//Loop through vector of GameObjects and run the appropriate functions for each
void Game::gameLoop()
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
