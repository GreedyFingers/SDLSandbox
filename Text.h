#pragma once
#include "Texture.h"
#include "Global_Assets.h"

class Text : public Texture
{

public:
	Text();
	~Text();

	bool loadText(std::string textureText, SDL_Color textColor,
				SDL_Texture* texture, int* sx, int* sy);

	//TODO: add functions for actually drawing the text
};

