#pragma once

#include "Manager.h"
#include "SDL_image.h"

class TextureManager{
public:

    static SDL_Texture* loadTexture(const char* file);
    static void draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);

};
