#include "KeyboardHandler.h"

void KeyboardHandler::handleEvents(){
    switch (Manager::event.type){
    case SDL_MOUSEBUTTONDOWN:
        std::cout << "mouseDown" << std::endl;
        switch (Manager::event.button.button){
        case SDL_BUTTON_LEFT:
            bpmanager->place(Manager::event.button.x, Manager::event.button.y);
            break;
        default:
            break;
        }
        break;
    case SDL_MOUSEBUTTONUP:
        std::cout << "mouse up" << std::endl;
        break;
    case SDL_MOUSEWHEEL:
        std::cout << "mousewheel" << std::endl;
        switch(Manager::event.wheel.y){
        case 1:
            std::cout << "wheel up" << std::endl;
            break;
        case (-1):
            std::cout << "wheel down" << std::endl;
            break;
        default:
            break;
        }
        break;
    case SDL_KEYDOWN:
        std::cout << "keydown" << std::endl;
        switch (Manager::event.key.keysym.sym){
        case SDLK_SPACE:
            std::cout << "space " << std::endl;
            if (Manager::event.key.repeat == 0){
                manager->togglePause();
            }
            break;
        default:
            break;
        }
        break;
    case SDL_KEYUP:
        std::cout << "keyup" << std::endl;
        break;
    default:
        break;
    }
}
