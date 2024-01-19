#include "game.hpp"
#include "libraries.hpp"

int main(int argc, const char* argv[]) {

	Game* game = new Game();
	game->init();

	while (game->running()) {
		int ticks = SDL_GetTicks();
		game->handleEvents();
		game->update(ticks);
		game->render();
	}

	return 0;
}