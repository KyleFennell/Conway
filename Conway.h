#ifndef CONWAY_H
#define CONWAY_H

#include "SDL.h"
#include "SDL_image.h"
#include "Manager.h"
#include <iostream>

class Conway{
public:

    static const int WIDTH = 1600;
    static const int HEIGHT = 900;
    static SDL_Event event;

    Conway();
    Conway(int w, int h, bool autoFill);
    void init();
    void draw();
    void handelEvents();

    void iterate();

private:
    bool first = true;

    int** board;
    int width;
    int height;

    void toggleBoard(int x, int y);
    int neighbours(int x, int y);

    SDL_Texture* on;
    SDL_Texture* off;
    SDL_Rect src;
    SDL_Rect dest;

    int texH;
    int texW;
};

#endif // CONWAY_H
