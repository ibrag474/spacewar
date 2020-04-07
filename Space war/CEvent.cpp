#include "CEvent.h"

CEvent::CEvent() {
}

CEvent::~CEvent() {
    //Do nothing
}

void CEvent::OnEvent(SDL_Event* Event) {
    switch (Event->type) {
    case SDL_KEYDOWN: 
        OnKeyDown(Event->key.keysym.scancode);
        break;
    case SDL_QUIT: 
        OnExit();
        break;
    }
}

void CEvent::OnKeyDown(SDL_Keycode keyCode) {
    
}

void CEvent::OnExit() {
    
}