#include "CApp.h"

bool CApp::OnInit() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		return false;
	}

	if ((Surf_Display = SDL_CreateWindow("Space War",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		640, 480,
		SDL_SWSURFACE)) == NULL) {
		return false;
	}
	return true;
}