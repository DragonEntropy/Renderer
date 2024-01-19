#pragma once
#include "libraries.hpp"

class GameObject
{
public:
	GameObject();
	GameObject(SDL_Renderer* renderer);
	~GameObject();

	void update();
	virtual void render() = 0;
	
protected:
	SDL_Renderer* renderer = NULL;
};
