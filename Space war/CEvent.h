#ifndef _CEVENT_H
#define _CEVENT_H

#include <SDL.h>

class CEvent {
public:
	CEvent();
	~CEvent();
	virtual void OnEvent(SDL_Event* Event);
	virtual void OnKeyDown(SDL_Keycode keyCode);
	virtual void OnExit();
};

#endif
