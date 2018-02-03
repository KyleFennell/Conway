#include <iostream>
#include "Manager.h"

int main(int argc, char** argv){


    Manager manager;
    manager.init("conway", false);
    manager.initConway(80, 60);
    manager.readBlueprints();

    const int FPS = 15;
    const int PAUSEDFPS = 60;
    const int frameDelay = 1000 / FPS;
    const int pausedDelay = 1000 / PAUSEDFPS;
    int activeDelay = pausedDelay;
    Uint32 frameStart;
    int frameTime;

    std::cout << "Startup Finished" << std::endl;
    while(manager.isRunning()){
        frameStart = SDL_GetTicks();

        if (SDL_PollEvent(&Manager::event) == 1){
            manager.handleEvents();
        }

        manager.update();
        manager.draw();

        activeDelay = ((manager.isPaused())? pausedDelay:frameDelay);
        frameTime = SDL_GetTicks()-frameStart;

        if (activeDelay > frameTime){
            SDL_Delay(activeDelay-frameTime);
        }
    }
    manager.clean();
    return 0;
}
