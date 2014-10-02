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
		SDL_Surface* _screen;
		bool _remove;
	protected:
		float _x, _y;
		float _sx, _sy;
		float _spritestart, _spriteend;
		SDL_Surface* _texture;

	public:
		GameObject();
		~GameObject();

		virtual void input();
		virtual void update();
		void init(float, float, float, float, ObjectID, std::string, SDL_Surface *screen, int, int);
		virtual void render();
		float getX();
		float getY();
		float getSX();
		float getSY();
		ObjectID getType();
};

