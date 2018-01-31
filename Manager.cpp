#include "Manager.h"

SDL_Renderer* Manager::renderer = nullptr;
SDL_Window* Manager::window = nullptr;

void Manager::init(const char* title, int x, int y, int width, int height, bool fullscreen){
    std::cout << "SDL begin" << std::endl;
    Uint32 flag = 0;
    if (fullscreen){
        flag = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0){
        std::cout << "SDL initialised..." << std::endl;

        std::cout << window <<std::endl;
        window = SDL_CreateWindow(title, x, y, width, height, flag);
        std::cout << window <<std::endl;
        if (window){
            std::cout << "Window created..." << std::endl;
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer){
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            std::cout << "Renderer created..." << std::endl;
        }
    }
    else {
        std::cout << "Init failed..." << std::endl;
    }
}

void Manager::draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest){
    SDL_RenderCopy(Manager::renderer, tex, &src, &dest);
}

SDL_Texture* Manager::loadTexture(const char* file){
    SDL_Surface* tempSurface = IMG_Load(file);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(Manager::renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    return tex;
}
