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
		int _spriteCount;

		//Time synchronization information
		int _lastUpdateTime;
		int _timeSinceLastUpdate;

		//slows down gameobjects specifically
		int _damping = 50;

		//Sprite clips
		SDL_Rect* _clips;
		SDL_Rect _currentClip;

	public:
		GameObject();
		~GameObject();

		//Game logic members
		virtual void input();
		virtual void update();
		virtual void render(SDL_Renderer* renderer);

		//initialize object
		void init(SDL_Renderer* renderer,int x, int y, ObjectID type, 
					std::string texturePath);

		//getters
		int getX();
		int getY();
		int getSX();
		int getSY();

		ObjectID getType();
};

