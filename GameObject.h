#pragma once

#include <SDL.h>
#include <string>
#include "Texture.h"
#include "Animation.h"
#include "Clock.h"

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

		//Sprite clips
		SDL_Rect* _clips;
		SDL_Rect _currentClip;

		//Animations
		Animation* _animations;
		Animation _currentAnimation;

		//Time synchronization information
		Clock _clock;

		//slows down GameObjects specifically
		int _damping = 50;

	public:
		GameObject();
		~GameObject();

		//Game logic members
		virtual void input();
		virtual void update();
		virtual void render(SDL_Renderer* renderer);

		//initialize object
		void init(SDL_Renderer* renderer,int x, int y, ObjectID type, 
					std::string texturePath, int spriteCount, int animationCount);

		//initialize texture clips
		void initClips(int spriteCount);

		//initialize animation clips
		void initAnimations(int animationCount);

		//getters
		int getX();
		int getY();
		int getSX();
		int getSY();

		ObjectID getType();
};

