#pragma once

#include "Conway.h"
#include "Manager.h"

class Manager;

class KeyboardHandler{
public:

    KeyboardHandler(Conway* c, Manager* m){ conway = c; manager = m; }
    void handleEvents();

private:
    Conway* conway;
    Manager* manager;

    bool keyDown = false;
    bool mouseDown = false;

};
