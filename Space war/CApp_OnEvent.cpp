#include "CApp.h"
#include "CEvent.h"
#include <iostream>

void CApp::OnEvent(SDL_Event* Event) {
	CEvent::OnEvent(Event);
}

void CApp::OnExit() {
	Running = false;
}