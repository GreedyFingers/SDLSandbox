#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <SDL_ttf.h>

class Draw
{
	static SDL_Renderer* _renderer;
public:
	static void initRenderer(SDL_Window* window, Uint32 flags );
	static SDL_Texture* loadTexture(std::string fileName);
	static SDL_Texture* loadText(std::string textureText, SDL_Color textColor,
									int* sx, int* sy);
	static bool draw(SDL_Texture* texture, int rendX,
						int rendY, SDL_Rect* clip);
	static bool setTransparentColor(SDL_Surface *target, int R, int G, int B);
	static void getRendererSize(int* rw, int* rh);
	static void setRenderDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	static void renderClear();
	static void renderPresent();

	//TODO: destroy renderer function
};