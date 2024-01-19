#ifndef Game_hpp
#define Game_hpp

#include "SDL.h"
#undef main
#include "libraries.hpp"

class Game {
	
public:
	Game();
	~Game();

	void init();

	void handleEvents();
	void update(int ticks);
	void render();
	void clean();

	bool running();

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	bool isRunning;
	std::vector<GameObject*>* gameObjects = new std::vector<GameObject*>();
};

#endif