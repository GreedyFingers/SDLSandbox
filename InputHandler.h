#pragma once
#include "GameObject_Manager.h"

class InputHandler
{
	GameObject_Manager* _objectManager;

	public:
		InputHandler(GameObject_Manager *objectManager);
		~InputHandler();

		void mouseClick(int x, int y);
};

