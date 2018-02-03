#pragma once

#include <string>
#include <vector>
#include "Manager.h"
#include "Conway.h"

class Blueprint{
public:
    Blueprint(Blueprint *b){this->_data = b->data(); this->_name = b->name();}
    Blueprint(std::string name, std::vector<std::vector<int>>  data){_data = data; _name = name;}
    std::vector<std::vector<int>> data(){return _data;}
    std::string name(){return _name;}
    int width(){return _data[0].size();}
    int height(){return (int)_data.size();}
private:
    std::vector<std::vector<int>> _data;
    std::string _name;
};

class BlueprintManager{
public:
    BlueprintManager(Conway* conway, int width, int height);
    ~BlueprintManager();

    void draw(int x, int y);
    void place(int x, int y);

    void next();
    void prev();
    void rotateLeft();
    void rotateRight();
    void flipY();
    void flipX();

private:
    void add(std::string name, std::vector<std::vector<int>> data);
    int size = -1;
    int crnt = 0;
    Blueprint* crntBP = nullptr;
    int rotation = 0;
    std::vector<Blueprint*> blueprints;

    SDL_Texture* bpOn;
    SDL_Rect src, dest;
    Conway* conway;

    int width;
    int height;

    int _texW;
    int _texH;

    void transpose();
};
