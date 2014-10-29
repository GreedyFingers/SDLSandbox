#pragma once
#include "Text.h"
#include "draw.h"

Text::Text()
{

}

Text::~Text()
{
}

void Text::loadText(std::string textureText, SDL_Color textColor,
					int sx, int sy)
{
	//_texture.setTexture(Draw::loadText(textureText, textColor, &sx, &sy));
	_clip.w = sx;
	_clip.h = sy;
}