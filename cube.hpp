#pragma once
#include "vector.hpp"

class Cube : public GameObject
{
public:
	Cube(SDL_Renderer* renderer, Vector* center, Vector* orientation, float scale);
	~Cube();
	void render();

private:
	Vector center;
	Vector orientation;
	float scale;
};

