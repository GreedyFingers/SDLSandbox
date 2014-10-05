#pragma once

#include <SDL.h>
#include <string>

class GameObject
{
	//members
	public: 
		static enum ObjectID { player };
	private:
		ObjectID _type;
		bool _remove;
	protected:
		int _x, _y;
		int _sx, _sy;
		int _spritestart, _spriteend;
		SDL_Texture* _texture;
		SDL_Renderer* _renderer;

	public:
		GameObject();
		~GameObject();

		virtual void input();
		virtual void update();
		virtual void render();
		void init(int, int, int, int, ObjectID, std::string, SDL_Renderer*, int, int);
		int getX();
		int getY();
		int getSX();
		int getSY();
		SDL_Texture* getTexture();
		ObjectID getType();
};

