#include "Conway.h"
#include "Manager.h"
#include <iostream>

const float PERCENTAGE = 0.3;
SDL_Event Conway::event;

Conway::Conway(int w, int h, bool autoFill){

    height = h;
    texH = HEIGHT/(height);
    width = w;
    texW = WIDTH/(width);
    board = new int*[height];
    for (int i = 0; i < height; i++){
        board[i] = new int[width];
        for (int j = 0; j < width; j++){
            if (autoFill && static_cast <float> (rand()) / static_cast <float> (RAND_MAX) <= PERCENTAGE){
                board[i][j] = 1;
            }
            else{
                board[i][j] = 0;
            }
        }
    }

    on = Manager::loadTexture("on.png");
    off = Manager::loadTexture("off.png");

    src.x = src.y = 0;
    src.w = src.h = 8;

    dest.w = texW;
    dest.h = texH;
}


void Conway::draw(){
    SDL_RenderClear(Manager::renderer);
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            dest.x = texW*j;
            dest.y = texH*i;
            switch (board[i][j]){
            case 0:
                Manager::draw(off, src, dest);
                break;
            case 1:
                Manager::draw(on, src, dest);
                break;
            default:
                break;
            }
        }
    }
}

void Conway::iterate(){
    int** newBoard = new int*[height];
    for (int i = 0; i < height; i++){
        newBoard[i] = new int[width];
        for (int j = 0; j < width; j++){
            if (neighbours(i, j) < 2){
                newBoard[i][j] = 0;
            }
            else if (neighbours(i,j) < 3){
                newBoard[i][j] = board[i][j];
            }
            else if(neighbours(i, j) == 3){
                newBoard[i][j] = 1;
            }
            else {
                newBoard[i][j] = 0;
            }
        }
    }
    board = newBoard;
}

void Conway::handelEvents(){
    if (first && Conway::event.type == SDL_MOUSEBUTTONDOWN && Conway::event.button.button == SDL_BUTTON_LEFT){
        std::cout << Conway::event.button.x << "," << Conway::event.button.y << std::endl;
        toggleBoard(Conway::event.button.x/texW, Conway::event.button.y/texH);
        first = false;
    }
    else if (!first && Conway::event.type == SDL_MOUSEBUTTONUP){
        first = true;
    }
}

void Conway::toggleBoard(int x, int y){
    if (board[y][x]){
        board[y][x] = 0;
    }
    else {
        board[y][x] = 1;
    }
}

int Conway::neighbours(int x, int y){
    int count = 0;
    for (int i = -1; i < 2; i++){
        for (int j = -1; j < 2; j++){
            if ((i != 0 || j != 0) && board[(height+i+x)%height][(width+j+y)%width]){
                count++;
            }
        }
    }
    return count;
}
