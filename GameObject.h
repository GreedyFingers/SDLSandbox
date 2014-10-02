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
		SDL_Renderer* _renderer;
		bool _remove;
	protected:
		float _x, _y;
		int _sx, _sy;
		int _spritestart, _spriteend;
		SDL_Texture* _texture;

	public:
		GameObject();
		~GameObject();

		virtual void input();
		virtual void update();
		void init(float, float, int, int, ObjectID, std::string, SDL_Renderer*, int, int);
		virtual void render();
		float getX();
		float getY();
		int getSX();
		int getSY();
		SDL_Texture* getTexture();
		ObjectID getType();
};

