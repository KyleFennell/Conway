#include "BlueprintManager.h"
#include "TextureManager.h"

BlueprintManager::BlueprintManager(Conway* c, int width, int height){
    std::vector<std::vector<int>> none;
    std::vector<int> v = {1, 1, 1};
    none.push_back(v);
    v = {1, 0, 0};
    none.push_back(v);
    v = {0, 1, 0};
    none.push_back(v);
    add("default", none);

    _texH = Manager::HEIGHT/(height);
    _texW = Manager::WIDTH/(width);

    bpOn = TextureManager::loadTexture("assets/bpOn.png");

    src.x = src.y = 0;
    src.w = src.h = 8;

    dest.w = _texW;
    dest.h = _texH;

    conway = c;

}

void BlueprintManager::add(std::string name, std::vector<std::vector<int>> data){
    Blueprint* b = new Blueprint(name, data);
    BlueprintManager::blueprints.push_back(*b);
    size++;
}

void BlueprintManager::draw(int x, int y){
    std::vector<std::vector<int>> bp = blueprints[crnt].data();
    for (int i = 0; i < bp.size(); i++){
        for (int j = 0; j < bp[i].size(); j++){
            if (bp[i][j]){
                dest.x = (x+j)*_texW;
                dest.y = (y+i)*_texH;
                TextureManager::draw(bpOn, src, dest);
            }
        }
    }
}

void BlueprintManager::place(int x, int y){
    std::cout << "placing" << std::endl;
    std::vector<std::vector<int>> bp = blueprints[crnt].data();
    for (int i = 0; i < bp.size(); i++){
        for (int j = 0; j < bp[i].size(); j++){
            std::cout << i << "," << j << " " << x+j << "," << y+i << std::endl;
            if (bp[i][j]){
                dest.x = (x+j)*_texW;
                dest.y = (y+i)*_texH;
                std::cout << x/_texW+j << "," << y/_texH+i << std::endl;
                conway->setBoard(x/_texW+j, y/_texH+i);
            }
        }
    }
}
