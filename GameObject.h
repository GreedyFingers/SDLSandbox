#pragma once

#include <SDL.h>
#include <string>
#include "Texture.h"
#include "Animation.h"
#include "Clock.h"
#include "Sprite.h"
#include "Draw.h"
#include "Global_Assets.h"

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
		int _currentTextureClip = Global_Assets::ENTIRE_TEXTURE;

		//Time synchronization information
		Clock _clock;

		//flag to remove
		bool _remove;

	public:
		GameObject();
		~GameObject();

		//Game logic members
		virtual void select();
		virtual void update();
		virtual void render();

		//initialize object
		void init(int x, int y, ObjectID type, int sx, int sy);

		//initialize texture clips
		SDL_Rect* initClips(int spriteCount);

		//initialize animation clips
		void initAnimations(int animationCount);

		//getters
		int getX();
		int getY();
		int getSX();
		int getSY();

		//extensions
		bool containsPoint(int x, int y);

		ObjectID getType();
};

