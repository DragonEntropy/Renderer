#include "cube.hpp"
#include "libraries.hpp"
#include "vector.hpp"

Cube::Cube(SDL_Renderer* renderer, Vector* center, Vector* orientation, float scale) : GameObject(renderer) {
	this->center = *center;
	this->orientation = *orientation;
	this->scale = scale;
}

Cube::~Cube() {}

void Cube::render() {
	Vector corners[8];
	center.print();
	for (int a = 0; a < 2; a++) {
		for (int b = 0; b < 2; b++) {
			for (int c = 0; c < 2; c++) {
				float shift[3] = { scale * (2 * a - 1) * SQRT3 / 2, scale * (2 * b - 1) * SQRT3 / 2, scale * (2 * c - 1) * SQRT3 / 2 };
				Vector* shiftVector = new Vector(renderer, 3, shift);
				corners[4 * a + 2 * b + c] = *Vector::add(center, *shiftVector);
			}
		}
	}

	Vector projections[8];
	for (int i = 0; i < 8; i++) {
		float scalar = corners[i].getMagnitude() / 600;
		projections[i] = *Vector::scale(corners[i], 1 / scalar);
	}
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_Point points[8];
	for (int i = 0; i < 8; i++) {
		points[i] = *projections[i].toSDLPoint(300, 300);
		std::cout << "(" << points[i].x << ", " << points[i].y << ")" << std::endl;
	}
	SDL_Point connectedPoints[13] = {points[0], points[1], points[3], points[2], points[0], points[4], points[5], points[7], points[6], points[4]};
	SDL_RenderDrawLines(renderer, connectedPoints, 10);
	for (int i = 1; i < 4; i++) {
		SDL_RenderDrawLine(renderer, points[i].x, points[i].y, points[i + 4].x, points[i + 4].y);
	}
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	for (int i = 0; i < 8; i++) {
		SDL_RenderDrawPoints(renderer, points, 8);
	}
}
