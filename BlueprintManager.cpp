#include "BlueprintManager.h"
#include "TextureManager.h"
#include <fstream>
#include <iostream>

BlueprintManager::BlueprintManager(Conway* c, int width, int height){

    this->height = height;
    this->width = width;

    _texH = Manager::HEIGHT/(height);
    _texW = Manager::WIDTH/(width);

    bpOn = TextureManager::loadTexture("assets/bpOn.png");

    src.x = src.y = 0;
    src.w = src.h = 8;

    dest.w = _texW;
    dest.h = _texH;

    conway = c;

    std::string line;
    std::ifstream file ("blueprints.txt");
    if (file.is_open()){
        std::cout << "file opened" << std::endl;
        while ( getline(file, line) ){
            std::cout << line << std::endl;
            if (line.compare("begin") == 0){
                getline(file, line);
                std::string name = line;
                std::cout << name << std::endl;
                getline(file, line);
                std::vector<std::vector<int>> bpdata;
                while (line.compare("end") != 0){
                    std::vector<int> row;
                    std::cout << line << std::endl;
                    for (int i = 0; i < (int)line.size(); i += 2){
                        row.push_back(stoi(line.substr(i,1)));
                    }
                    bpdata.push_back(row);
                    getline(file, line);
                }
                add(name, bpdata);
                std::cout << name << " added" << std::endl;
            }
        }
        file.close();
        std::cout << "file closed" << std::endl;
    }
    else{
        std::cout << "Unable to open file";
    }
    crntBP = new Blueprint(blueprints[crnt]);
}

void BlueprintManager::add(std::string name, std::vector<std::vector<int>> data){
    Blueprint* b = new Blueprint(name, data);
    BlueprintManager::blueprints.push_back(b);
    size++;
}

void BlueprintManager::draw(int x, int y){
    std::vector<std::vector<int>> bpData = crntBP->data();
    for (int i = 0; i < crntBP->height(); i++){
        for (int j = 0; j < crntBP->width(); j++){
            if (bpData[i][j]){
                dest.x = (x+j-(crntBP->width()/2))*_texW;
                dest.y = (y+i-(crntBP->height()/2))*_texH;
                TextureManager::draw(bpOn, src, dest);
            }
        }
    }
}

void BlueprintManager::place(int x, int y){
    std::vector<std::vector<int>> bpData = crntBP->data();
    for (int i = 0; i < crntBP->height(); i++){
        for (int j = 0; j < crntBP->width(); j++){
            if (bpData[i][j]){
                int posx = x/_texW+j-(crntBP->width()/2);
                int posy = y/_texH+i-(crntBP->height()/2);
                if (posx >= 0 && posx < width && posy >= 0 && posy < height){
                    conway->setBoard(posx, posy);
                }
            }
        }
    }
}

void BlueprintManager::next(){
    crnt = ((crnt >= size)? 0:crnt+1);
    crntBP = new Blueprint(blueprints[crnt]);
}

void BlueprintManager::prev(){
    crnt = ((crnt <= 0)? size:crnt-1);
    crntBP = new Blueprint(blueprints[crnt]);
}

void BlueprintManager::rotateLeft(){
    transpose();
    flipY();
}

void BlueprintManager::rotateRight(){
    transpose();
    flipX();
}

void BlueprintManager::flipX(){
    std::vector<std::vector<int>> bpData = crntBP->data();
    std::vector<std::vector<int>> out(bpData.size());
    for (int i = 0; i < (int)out.size(); i++){
        out[i] = std::vector<int>(bpData[i].size());
        for (int j = 0; j < (int)out[i].size(); j++){
            out[i][j] = bpData[i][bpData[i].size()-j-1];
            std::cout << out[i][j];
        }
        std::cout << std::endl;
    }
    crntBP = new Blueprint(blueprints[crnt]->name(), out);
}

void BlueprintManager::flipY(){
    std::vector<std::vector<int>> bpData = crntBP->data();
    std::vector<std::vector<int>> out(bpData.size());
    for (int i = 0; i < (int)out.size(); i++){
        out[i] = std::vector<int>(bpData[i].size());
        for (int j = 0; j < (int)out[i].size(); j++){
            out[i][j] = bpData[bpData.size()-i-1][j];
        }
    }
    crntBP = new Blueprint(blueprints[crnt]->name(), out);
}

void BlueprintManager::transpose(){
    std::vector<std::vector<int>> bpData = crntBP->data();
    std::vector<std::vector<int>> out(bpData[0].size());
    for (int i = 0; i < (int)out.size(); i++){
        out[i] = std::vector<int>(bpData.size());
    }
    for (int i = 0; i < (int)out.size(); i++){
        for (int j = 0; j < (int)out[i].size(); j++){
            out[i][j] = bpData[j][i];
        }
    }
    crntBP = new Blueprint(blueprints[crnt]->name(), out);
}
