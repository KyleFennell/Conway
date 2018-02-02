#include "Manager.h"

SDL_Renderer* Manager::renderer = nullptr;
SDL_Window* Manager::window = nullptr;
SDL_Event Manager::event;

Manager::Manager(){
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

}

void Manager::initConway(int width, int height, bool autofill){
    conway = new Conway(width, height, autofill);
    bpmanager = new BlueprintManager(conway, width, height);
    keyboard = new KeyboardHandler(conway, this, bpmanager);
}

void Manager::readBlueprints(){

}

void Manager::handleEvents(){
    if (Manager::event.type == SDL_QUIT) {
        running = false;
    }
    keyboard->handleEvents();
}

void Manager::update(){
    if (!paused){
        conway->iterate();
    }
}

void Manager::draw(){
    SDL_RenderClear(Manager::renderer);
    conway->draw();
    bpmanager->draw(Manager::event.button.x/conway->texW(), Manager::event.button.y/conway->texH());
    SDL_RenderPresent(Manager::renderer);
}

void Manager::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(Manager::renderer);
    SDL_Quit();
    std::cout << "SDL Cleaned..." << std::endl;
}

