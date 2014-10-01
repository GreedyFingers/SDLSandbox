#include "csurface.h"

SDL_Surface* CSurface::onLoad(std::string fileName)
{
	SDL_Surface *tempSurface;
	tempSurface = IMG_Load(fileName.c_str());
	if (tempSurface == NULL)
		return NULL;
	return tempSurface;
}

bool CSurface::onDraw(SDL_Surface *src, SDL_Surface *dest, int destX, int destY)
{
	if (src == NULL || dest == NULL)
		return false;
	SDL_Rect destR;
	destR.x = destX;
	destR.y = destY;
	SDL_BlitSurface(src, NULL, dest, &destR);
	return true;
} 

bool CSurface::onDraw(SDL_Surface *src, SDL_Surface *dest, int destX, int destY,
						int srcX, int srcY, int width, int height)
{
	if (src == NULL || dest == NULL)
		return false;
	SDL_Rect destR;
	destR.x = destX;
	destR.y = destY;
	SDL_Rect srcR;
	srcR.x = srcX;
	srcR.y = srcY;
	srcR.w = width;
	srcR.h = height;
	SDL_BlitSurface(src, &srcR, dest, &destR);
	return true;
}

bool CSurface::setTrasnparentColor(SDL_Surface *target, int R, int G, int B)
{
	if (target == NULL)
		return false;
	SDL_SetColorKey(target, SDL_TRUE | SDL_RLEACCEL,
		SDL_MapRGB(target->format, R, G, B));
	return true;
}