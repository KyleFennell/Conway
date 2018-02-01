#pragma once
#include "SDL.h"
#include "Conway.h"
#include "KeyboardHandler.h"
#include <iostream>

class KeyboardHandler;

class Manager{
public:

    Manager(Conway* conway);
    ~Manager();

    static SDL_Event event;
    static SDL_Renderer* renderer;
    static const int WIDTH = 1600;
    static const int HEIGHT = 900;

    void init(const char* title, bool fullscreen);
    void handleEvents();
    void update();
    void draw();
    void clean();

    bool isRunning(){ return running; }
    bool isPaused(){ return paused; }
    void togglePause(){ paused = !paused; }


private:
    SDL_Window* window;
    bool running = false;
    bool paused = true;
    Conway* conway;
    KeyboardHandler* keyboard;
};
