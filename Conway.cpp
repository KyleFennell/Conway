#include "Conway.h"
#include "TextureManager.h"
#include "Manager.h"

const float PERCENTAGE = 0.3;

Conway::Conway(int w, int h){

    height = h;
    width = w;

    _texH = Manager::HEIGHT/(height);
    _texW = Manager::WIDTH/(width);

    board = new int*[height];
    for (int i = 0; i < height; i++){
        board[i] = new int[width];
        for (int j = 0; j < width; j++){
            board[i][j] = 0;
        }
    }

    on = TextureManager::loadTexture("assets/on.png");
    off = TextureManager::loadTexture("assets/off.png");

    src.x = src.y = 0;
    src.w = src.h = 8;

    dest.w = _texW;
    dest.h = _texH;
}


void Conway::draw(){
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            dest.x = _texW*j;
            dest.y = _texH*i;
            switch (board[i][j]){
            case 0:
                TextureManager::draw(off, src, dest);
                break;
            case 1:
                TextureManager::draw(on, src, dest);
                break;
            default:
                break;
            }
            //std::cout << board[i][j] << " ";
        }
        //std::cout << std::endl;
    }
    //std::cout << std::endl;
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

void Conway::randomFill(){
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            if ((float)rand()/(float)RAND_MAX <= PERCENTAGE){
                board[i][j] = 1;
            }
            else{
                board[i][j] = 0;
            }
        }
    }
}

void Conway::clear(){
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            board[i][j] = 0;
        }
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
