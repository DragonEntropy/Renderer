#include "game.hpp"
#include "libraries.hpp"
#include "cube.hpp"

Game::Game() {
	window = NULL;
	renderer = NULL;
	isRunning = false;
}
Game::~Game() {}

void Game::init() {
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Renderer", 600, 300, 600, 600, 0);
	renderer = SDL_CreateRenderer(window, 0, 0);
	isRunning = true;
}

void Game::handleEvents() {
	return;
}

void Game::update(int ticks) {
	gameObjects->clear();
	float position[3][3] = { { 10, 0, ticks / 200 }, {5, 5, ticks / 200}, {-10, -5, ticks / 100 } };
	std::cout << "Ticks: " << ticks << std::endl;
	float orientation[3] = { 0, 0, 0 };
	Vector* orientationVector = new Vector(renderer, 3, orientation);
	for (float* pos : position) {
		Vector* positionVector = new Vector(renderer, 3, pos);
		gameObjects->push_back((GameObject*)(new Cube(renderer, positionVector, orientationVector, 10)));
	}
}

void Game::render() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	for (GameObject* object : *gameObjects) {
		object->render();
	}
	SDL_RenderPresent(renderer);
	SDL_Delay(50);
}

void Game::clean() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

bool Game::running() {
	return isRunning;
}