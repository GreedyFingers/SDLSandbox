#include "Text.h"
#include "draw.h"

Text::~Text()
{
}

bool Text::loadText(std::string textureText, SDL_Color textColor,
					SDL_Texture* texture, int* sx, int* sy)
{
	return Draw::loadText(textureText, textColor, texture, sx, sy);
}