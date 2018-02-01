#include "TextureManager.h"
#include "Manager.h"

void TextureManager::draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest){
    SDL_RenderCopy(Manager::renderer, tex, &src, &dest);
}

SDL_Texture* TextureManager::loadTexture(const char* file){
    std::cout << "Load image " << IMG_Load(file) << std::endl;

    SDL_Surface* tempSurface = IMG_Load(file);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(Manager::renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    return tex;
}
