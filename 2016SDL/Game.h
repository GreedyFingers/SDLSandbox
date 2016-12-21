#pragma once

#include <vector>
#include "CommonEnums.h"
#include "Renderer.h"

class Game
{
	Util::Renderer* _renderer;

public:

	//receives renderer so that it can load textures onto it
	Game(Util::Renderer* renderer);
	~Game();

	void start();
	void run();
	void stop();

	//three methods which are repeatedly called for each GameObject
	//void selectObject(int x, int y);
	/*void update(GameObject*);
	void render(GameObject*);*/

	void update();
	void render();

};

