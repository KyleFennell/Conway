#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

class Manager{
public:
    static SDL_Renderer* renderer;

    static void init(const char* title, int x, int y, int width, int height, bool fullscreen);
    static void draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
    static SDL_Texture* loadTexture(const char* file);

private:
    static SDL_Window* window;
};
