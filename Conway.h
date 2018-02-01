#pragma once

#include <iostream>
#include "SDL.h"

class Conway{
public:

    int texW(){return _texW;}
    int texH(){return _texH;}

    Conway();
    Conway(int w, int h, bool autoFill);
    void init();
    void draw();

    void iterate();
    void toggleBoard(int x, int y){board[y][x] = !board[y][x];};

private:
    bool first = true;

    int** board;
    int width;
    int height;

    int neighbours(int x, int y);

    SDL_Texture* on;
    SDL_Texture* off;
    SDL_Rect src, dest;

    int _texW;
    int _texH;
};
