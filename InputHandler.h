#pragma once

class InputHandler
{
		Game* _game;
	public:
		InputHandler(Game* game);
		~InputHandler();

		void mouseClick(int x, int y);
};

