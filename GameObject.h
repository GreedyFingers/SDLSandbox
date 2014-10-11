#pragma once

#include <SDL.h>
#include <string>
#include "Texture.h"

class GameObject
{
	//members
	public:
		//list GameObject types
		static enum ObjectID { player };
	private:
		//this object's type
		ObjectID _type;

		//flag to remove
		bool _remove;

	protected:

		//Texture information
		Texture* _texture;
		int _x, _y;
		int _sx, _sy;
		int _spritestart, _spriteend;

		int _lastUpdateTime;
		int _timeSinceLastUpdate;

		int _damping = 50;

		SDL_Rect _clips[1];
		SDL_Rect _currentClip = _clips[0];

	public:
		GameObject();
		~GameObject();

		//Game logic members
		virtual void input();
		virtual void update();
		virtual void render(SDL_Renderer* renderer);

		//initialize object
		void init(SDL_Renderer* renderer,int x, int y, ObjectID type, 
					std::string texturePath, int spriteStart, int spriteEnd);

		//getters
		int getX();
		int getY();
		int getSX();
		int getSY();
		Texture* getTexture();
		ObjectID getType();
};

