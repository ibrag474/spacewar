#ifndef _CAPP_H_
#define _CAPP_H_

#include "CEvent.h"
#include <SDL.h>

class CApp : public CEvent {

public:
private:
	bool    Running;

	SDL_Window* Surf_Display;
public:
	CApp();

	int OnExecute();

public:

	bool OnInit();

	void OnEvent(SDL_Event* Event);

	void OnExit();

	void OnLoop();

	void OnRender();

	void OnCleanup();

};

#endif