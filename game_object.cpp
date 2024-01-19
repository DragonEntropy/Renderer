#include "game_object.hpp"

GameObject::GameObject() {}
GameObject::GameObject(SDL_Renderer* renderer) {
	this->renderer = renderer;
}
GameObject::~GameObject() {}

void GameObject::update() {}