#include "vector.hpp"
#include "libraries.hpp"

Vector::Vector() {
}

Vector::Vector(SDL_Renderer* renderer, int dim, float* values) : GameObject(renderer) {
	this->dim = dim;
	for (int i = 0; i < dim; i++) {
		this->values[i] = values[i];
	}
}
Vector::~Vector() {}

float Vector::getValue(int pos) {
	if (0 <= pos && pos < dim) {
		return values[pos];
	}

	return 0;
}

Vector* Vector::add(Vector v1, Vector v2) {
	float values[3];
	if (v1.getDim() == v2.getDim()) {
		for (int i = 0; i < v1.getDim(); i++) {
			values[i] = v1.getValue(i) + v2.getValue(i);
		}
		return new Vector(v1.getRenderer(), v1.getDim(), values);
	}
	else {
		memset(values, 0, sizeof(values));
		return new Vector(v1.getRenderer(), 0, values);
		std::cout << "Vector size error!" << std::endl;
	}
}

Vector* Vector::scale(Vector v, float s) {
	float values[3];
	for (int i = 0; i < v.getDim(); i++) {
		values[i] = s * v.getValue(i);
	}
	return new Vector(v.getRenderer(), v.getDim(), values);
}

float Vector::getMagnitude() {
	float square_sum = 0;
	for (int i = 0; i < dim; i++) {
		square_sum += pow(values[i], 2);
	}
	return sqrt(square_sum);
}

void Vector::render() {
	float scalar = getMagnitude() / 600;
	Vector* projected = scale(*this, 1 / scalar);
	SDL_RenderDrawPoint(renderer, projected->getValue(0) + 300, projected->getValue(1) + 300);
}

void Vector::print() {
	std::cout << "[" << values[0] << ", " << values[1] << ", " << values[2] << "]" << std::endl;
}

SDL_Point* Vector::toSDLPoint(int xShift, int yShift) {
	SDL_Point* point = new SDL_Point();
	point->x = values[0] + xShift;
	point->y = values[1] + yShift;
	return point;
}