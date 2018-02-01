#include "KeyboardHandler.h"

void KeyboardHandler::handleEvents(){
    switch (Manager::event.type){
    case SDL_MOUSEBUTTONDOWN:
        std::cout << "mouseDown" << std::endl;
        if (!mouseDown){
            switch (Manager::event.button.button){
            case SDL_BUTTON_LEFT:
                conway->toggleBoard(Manager::event.button.x/conway->texW(), Manager::event.button.y/conway->texH());
                std::cout << Manager::event.button.x/conway->texW() << "," << Manager::event.button.y/conway->texH() << std::endl;
                break;
            default:
                break;
            }
        }
        mouseDown = true;
        break;
    case SDL_MOUSEBUTTONUP:
        std::cout << "mouse up" << std::endl;
        mouseDown = false;
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
            std::cout << "not space" << &Manager::event << std::endl;
            break;
        }
        keyDown = true;
        break;
    case SDL_MOUSEWHEEL:
        std::cout << "mousewheel" << std::endl;
        break;
    case SDL_KEYUP:
        std::cout << "keyup" << std::endl;
        keyDown = false;
        break;
    default:
        break;
    }
}
