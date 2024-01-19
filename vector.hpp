#pragma once
#include "libraries.hpp"

class Vector : public GameObject
{
public:
	Vector();
	Vector(SDL_Renderer* renderer, int dim, float* values);
	~Vector();

	static Vector* add(Vector v1, Vector v2);
	static Vector* scale(Vector v, float s);
	float getValue(int dim);
	int getDim() { return dim; };
	float getMagnitude();

	SDL_Renderer* getRenderer() { return renderer; };
	void render();
	void print();
	SDL_Point* toSDLPoint(int xShift, int yShift);
		
private:
	int dim = 0;
	float values[3];
};

