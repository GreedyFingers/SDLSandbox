#pragma once

#ifdef DRAW_EX
#define DRAW_EX __declspec(dllexport)
#else
#define DRAW_EX __declspec(dllimport)
#endif  

#include <SDL.h>
#include <SDL_image.h>
#include <string>

namespace Util
{
	class DRAW_EX Renderer
	{

		SDL_Renderer* _renderer;
		float _rwNormalized;
		float _rhNormalized;

	public:
		void initRenderer(SDL_Window* window, Uint32 flags);
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

		//TODO: destroy renderer function
	};
}