#pragma once
#include "Texture.h"
#include "Global_Assets.h"

class Text
{
	Texture _texture;
	SDL_Rect _clip;
public:
	Text();
	~Text();

	void loadText(std::string textureText, SDL_Color textColor,
					int sx, int sy);
	//TODO: add functions for actually drawing the text
};

