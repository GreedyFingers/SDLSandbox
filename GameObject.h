#pragma once

#include <SDL.h>
#include <string>
#include "Texture.h"
#include "Animation.h"
#include "Clock.h"
#include "Sprite.h"
#include "Draw.h"

class GameObject
{
	//members
	public:
		//list GameObject types
		static enum ObjectID { 
			Player,
			Scout,
			UnitControl,
			Terrain
		};

		static char* ObjectNames[4];

	private:
		//this object's type
		ObjectID _type;

	protected:

		//Position information
		int _x, _y;
		int _sx, _sy;

		//Sprite clips
		SDL_Rect* _clips;
		SDL_Rect _currentClip;
		int _currentClipIndex;

		//Time synchronization information
		Clock _clock;

		//slows down GameObjects specifically
		int _damping = 50;

		//flag to remove
		bool _remove;

	public:
		GameObject();
		~GameObject();

		//Game logic members
		virtual void input();
		virtual void update();
		virtual void render() = 0;

		//initialize object
		void init(int x, int y, ObjectID type, int spriteCount);

		//initialize texture clips
		SDL_Rect* initClips(int spriteCount);

		//initialize animation clips
		void initAnimations(int animationCount);

		//getters
		int getX();
		int getY();
		int getSX();
		int getSY();

		ObjectID getType();
};

