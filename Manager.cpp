#include "Manager.h"

SDL_Renderer* Manager::renderer = nullptr;
SDL_Event Manager::event;

Manager::Manager(Conway* c){
    conway = c;
}

Manager::~Manager(){

}

void Manager::init(const char* title, bool fullscreen){
    std::cout << "SDL begin" << std::endl;
    Uint32 flag = 0;
    if (fullscreen){
        flag = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0){
        std::cout << "SDL initialised..." << std::endl;

        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, flag);
        if (window){
            std::cout << "Window created..." << std::endl;
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer){
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            std::cout << "Renderer created..." << std::endl;
        }
        running = true;
    }
    else {
        std::cout << "Init failed..." << std::endl;
    }

    keyboard = new KeyboardHandler(conway, this);
}

void Manager::handleEvents(){
    if (Manager::event.type == SDL_QUIT) {
        running = false;
    }
    keyboard->handleEvents();
}

void Manager::update(){
    conway->iterate();
}

void Manager::draw(){
    SDL_RenderClear(Manager::renderer);
    conway->draw();
    SDL_RenderPresent(Manager::renderer);
}

void Manager::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(Manager::renderer);
    SDL_Quit();
    std::cout << "SDL Cleaned..." << std::endl;
}

