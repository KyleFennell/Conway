#pragma once
#include "SDL.h"
#include "Conway.h"
#include "KeyboardHandler.h"
#include "BlueprintManager.h"
#include <iostream>

class KeyboardHandler;

class Manager{
public:

    Manager();
    ~Manager();

    int mouseX;
    int mouseY;

    static SDL_Event event;
    static SDL_Renderer* renderer;
    static const int WIDTH = 800;
    static const int HEIGHT = 600;

    void init(const char* title, bool fullscreen);
    void initConway(int width, int height);
    void readBlueprints();

    void handleEvents();
    void update();
    void draw();
    void clean();

    bool isRunning(){ return running; }
    bool isPaused(){ return paused; }
    void togglePause(){ paused = !paused; }


private:
    static SDL_Window* window;
    bool running = false;
    bool paused = true;
    Conway* conway;
    KeyboardHandler* keyboard;
    BlueprintManager* bpmanager;
};
