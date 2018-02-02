#pragma once

#include "Conway.h"
#include "Manager.h"
#include "BlueprintManager.h"

class Manager;
class BlueprintManager;

class KeyboardHandler{
public:

    KeyboardHandler(Conway* c, Manager* m, BlueprintManager* b){
        conway = c;
        manager = m;
        bpmanager = b;
    }

    void handleEvents();

private:
    Manager* manager;
    Conway* conway;
    BlueprintManager* bpmanager;

};
