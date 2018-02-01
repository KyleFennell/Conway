#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

class TextureManager{
public:

    static void draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
    static SDL_Texture* loadTexture(const char* file);

};
