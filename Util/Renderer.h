#pragma once

#ifdef RENDERER_EX
#define RENDERER_EX __declspec(dllexport)
#else
#define RENDERER_EX __declspec(dllimport)
#endif  

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "Window.h"

namespace Util
{
	class RENDERER_EX Renderer
	{

		SDL_Renderer* _SDLRenderer;
		float _rwNormalized;
		float _rhNormalized;

	public:

		bool initRenderer(Util::Window* window, Uint32 flags);
		SDL_Texture* loadTexture(std::string fileName);
		void loadText(std::string textureText, SDL_Color textColor,
			int* sx, int* sy);
		bool draw(SDL_Texture* texture, int rendX,
			int rendY, SDL_Rect* clip);
		bool setTransparentColor(SDL_Surface *target, int R, int G, int B);
		void getRendererSize(int* rw, int* rh);
		void setRenderDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
		void renderClear();
		void renderPresent();

		float getRWNormalized();
		float getRHNormalized();

		Renderer();
		~Renderer();

	};
}