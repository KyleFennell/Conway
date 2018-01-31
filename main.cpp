#include <iostream>
#include "Conway.h"
#include "Manager.h"


int main(int argc, char** argv){

    Manager::init("conway", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Conway::WIDTH, Conway::HEIGHT, false);
    Conway c = Conway(160, 90, false);

    const int FPS = 15;
    const int PAUSEDFPS = 60;
    const int frameDelay = 1000 / FPS;
    const int pausedDelay = 1000 / PAUSEDFPS;
    int activeDelay = pausedDelay;
    Uint32 frameStart;
    int frameTime;
    bool paused = true;
    bool isRunning = true;

    std::cout << "Startup Finished" << std::endl;
    while(isRunning){
        frameStart = SDL_GetTicks();

        SDL_PollEvent(&Conway::event);
        if (Conway::event.type == SDL_QUIT) {
            isRunning = false;
        }
        if (Conway::event.key.type == SDL_KEYDOWN && Conway::event.key.repeat == 0 && Conway::event.key.keysym.sym == SDLK_SPACE){
            paused = !paused;
            if (paused){
                activeDelay = pausedDelay;
            }
            else {
                activeDelay = frameDelay;
            }
            std::cout << "paused: " << paused << std::endl;
        }
        if (!paused){
            c.iterate();
        }

        c.handelEvents();

        SDL_RenderClear(Manager::renderer);
        c.draw();
        SDL_RenderPresent(Manager::renderer);
        frameTime = SDL_GetTicks()-frameStart;

        if (activeDelay > frameTime){
            SDL_Delay(activeDelay-frameTime);
        }
    }
    return 0;
}
